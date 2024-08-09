#define LZ4_HC_STATIC_LINKING_ONLY
#define LZ4_COMMONDEFS_ONLY
#include "lz4hc.h"
#include "lz4.c"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_COMP_SIZE (8*1024*1024)

// #define FAVOR_DECOMPRESSION_SPEED
#define COMPRESSION_LEVEL LZ4HC_CLEVEL_MAX

#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

static uint32_t* sCurrentNibblePendingOutputPtr = NULL;
static uint32_t sCurrentNibble = 0;
static uint32_t sCurrentNibbleShift = 8;
static uint32_t sNibblesPushed = 0;

static void pushNibble(BYTE** _op, uint32_t newNibble)
{
    sNibblesPushed++;
    LOG("%d: Pushing nibble: %x\n", sNibblesPushed, newNibble);
    if (0 == sCurrentNibbleShift)
    {
        LOG("Requesting fresh nibbles\n");
        uint32_t nibbleBE = __builtin_bswap32(sCurrentNibble);
        memcpy(sCurrentNibblePendingOutputPtr, &nibbleBE, 4);
        sCurrentNibblePendingOutputPtr = (uint32_t*)(*_op);
        memset(sCurrentNibblePendingOutputPtr, 0, 4);
        sCurrentNibble = 0;
        sCurrentNibbleShift = 8;
        (*_op) += 4;
    }

    sCurrentNibbleShift--;
    newNibble <<= sCurrentNibbleShift * 4;
    sCurrentNibble |= newNibble;
    LOG("New nibble batch: 0x%x\n", sCurrentNibble);
}

int LZ4HC_encodeSequence (
    const BYTE** _ip,
    BYTE** _op,
    const BYTE** _anchor,
    int matchLength,
    int offset,
    limitedOutput_directive,
    BYTE*)
{
#define ip      (*_ip)
#define op      (*_op)
#define anchor  (*_anchor)

    /* Encode Literal length */
    size_t length = (size_t)(ip - anchor);
    LOG("Encoding literals: %d\n", length);
    if (length)
    {
        if (length > 21) {
            // means that encoding is extended
            pushNibble(&op, 8);
            size_t len = length - 21;
            while (len) {
                // bitcode the length
                if (len <= 127) {
                    LOG("Pushing final len: %d\n", len);
                    *op++ = len;
                } else {
                    LOG("Pushing partial len: %d\n", len & 127);
                    *op++ = 128 | (len & 127);
                }
                len >>= 7;
            }

            LOG("Copying literals wildly: %p %p %u\n", op, anchor, length);
            LZ4_wildCopy8(op, anchor, op + length);
            op += length;
        } else {
            size_t len = length;
            void* src = anchor;
            // put raw nibbles
            while (len) {
                LOG("Copying literals sizely: %p %p %u\n", op, anchor, length);
                uint32_t cut = len > 7 ? 7 : len;
                pushNibble(&op, 8 | cut);
                *(uint64_t*) op = *(uint64_t*)src;
                op += cut;
                src += cut;
                len -= cut;
            }
        }
    }

    /* Encode Offset */
    if (matchLength > 8) {
        // 7 means that matchLength is extended
        pushNibble(&op, 7);
    } else {
        // matchLength in [3, 8] so matchLength - 2 in [1, 6] - just enough for encoding
        pushNibble(&op, matchLength - 2);
    }
    assert(offset <= LZ4_DISTANCE_MAX );
    assert(offset > 0);
    LZ4_writeLE16(op, (U16)(offset)); op += 2;
    LOG("Offset: %d\n", offset);

    /* Encode MatchLength */
    assert(matchLength >= MINMATCH);
    LOG("Encoding match: %d\n", matchLength);
    if (matchLength > 8) {
        size_t len = matchLength - 8;
        while (len) {
            // bitcode the length
            if (len <= 127) {
                LOG("Pushing final len: %d\n", len);
                *op++ = len;
            } else {
                LOG("Pushing partial len: %d\n", len & 127);
                *op++ = 128 | (len & 127);
            }
            len >>= 7;
        }
    }

    /* Prepare next loop */
    ip += matchLength;
    anchor = ip;

    return 0;

#undef ip
#undef op
#undef anchor
}

int LZ4T_lastLiterals (
    const BYTE** _ip,
    BYTE** _op,
    const BYTE** _anchor,
    limitedOutput_directive limit,
    BYTE* oend,
    size_t length)
{
#define ip      (*_ip)
#define op      (*_op)
#define anchor  (*_anchor)

    if (length)
    {
        LOG("Encoding literals: %d\n", length);
        if (length > 21) {
            // means that encoding is extended
            pushNibble(&op, 8);
            size_t len = length - 21;
            while (len) {
                // bitcode the length
                if (len <= 127) {
                    LOG("Pushing final len: %d\n", len);
                    *op++ = len;
                } else {
                    LOG("Pushing partial len: %d\n", len & 127);
                    *op++ = 128 | (len & 127);
                }
                len >>= 7;
            }

            LZ4_wildCopy8(op, anchor, op + length);
            op += length;
        } else {
            size_t len = length;
            void* src = anchor;
            // put raw nibbles
            while (len) {
                uint32_t cut = len > 7 ? 7 : len;
                pushNibble(&op, 8 | cut);
                *(uint64_t*) op = *(uint64_t*)src;
                op += cut;
                src += cut;
                len -= cut;
            }
        }
        
    }

    // push ending marker
    uint32_t nibbleBE = __builtin_bswap32(sCurrentNibble);
    memcpy(sCurrentNibblePendingOutputPtr, &nibbleBE, 4);
    sCurrentNibblePendingOutputPtr = (uint32_t*)(*_op);
    memset(sCurrentNibblePendingOutputPtr, 0, 4);
    (*_op) += 4;
    sCurrentNibblePendingOutputPtr = NULL;

    ip = anchor + length;
    return 0;

#undef ip
#undef op
#undef anchor
}

// Counts are in nibbles so 1 byte is 2 nibbles
int LZ4HC_literalsPrice(int const litlen)
{
    int price = litlen * 2;
    assert(litlen >= 0);
    if (litlen > 21) {
        int len = litlen - 21;
        // encode 1 nibble for ex size
        price += 1;
        while (len)
        {
            // each ex size byte is 2 nibbles
            price += 2;
            len >>= 7;
        }
    } else {
        int len = litlen;
        while (len) {
            // single nibble for short sizes
            int cut = len > 7 ? 7 : len;
            price += 1;
            len -= cut;
        }
    }
    return price;
}

int LZ4HC_sequencePrice(int litlen, int mlen)
{
    int price = 4 ; // 16-bit offset is 4 nibbles
    assert(litlen >= 0);
    assert(mlen >= MINMATCH);

    price += LZ4HC_literalsPrice(litlen);
    // nibble for encoding match
    price += 1;
    if (mlen > 8) {
        // ex size encoding
        int len = mlen - 8;
        while (len)
        {
            // each ex size byte is 2 nibbles
            price += 2;
            len >>= 7;
        }
    }
    return price;
}

static char* lz4t_unpack(const char* in)
{
    const uint32_t* src = (const uint32_t*)in;
    uint32_t magicHeader = __builtin_bswap32(*src++);
    uint32_t srcSize = __builtin_bswap32(*src++);
    uint32_t compSize = __builtin_bswap32(*src++);
    int32_t nibbles = 0;
    int nibblesHandled = 0;

    char* dst = malloc(srcSize + 16);
    in = in + 12;
    char* out = dst;
    while (1)
    {
        if (0 == nibbles)
        {
            nibbles = __builtin_bswap32(*(uint32_t*) in);
            in += 4;
            LOG("Loaded new pack of nibbles: %x\n", nibbles);
            if (!nibbles)
            {
                break;
            }
        }

        nibblesHandled++;
        if (nibbles < 0)
        {
            LOG("%d: Handle literal nibble 0x%x\n", nibblesHandled, ((uint32_t) nibbles) >> 28);
            // literal
            int amount = 7 & (nibbles >> 28);
            LOG("Amount: %d\n", amount);
            if (amount == 0)
            {
                LOG("Amount is 0, unpacking extras\n");
                int shift = 0;
                while (1)
                {
                    int8_t next = *(int8_t*) (in++);
                    LOG("Next: %d\n", next);
                    if (next < 0)
                    {
                        amount |= (next & 0x7f) << shift;
                        shift += 7;
                        LOG("New partial amount: %x\n", amount);
                    }
                    else
                    {
                        amount |= (next << shift);
                        LOG("Amount is %d\n", amount);
                        break;
                    }
                }

                amount += 21;
                LOG("Copying amount %d via memcpy: %p %p\n", amount, out, in);
                memcpy(out, in, amount);
                out += amount;
                in += amount;
            }
            else
            {
                *(uint64_t*)out = *(uint64_t*)in;
                LOG("Copying amount %d wildly: %p %p\n", amount, out, in);
                out += amount;
                in += amount;
            }
        }
        else
        {
            LOG("%d: Handle match nibble 0x%x\n", nibblesHandled, ((uint32_t) nibbles) >> 28);
            // match
            uint16_t offset = *(uint16_t*)in;
            in += 2;

            LOG("Offset: %d\n", offset);
            int amount = 2 + (7 & (nibbles >> 28));
            LOG("Amount: %d\n", amount);
            if (amount == 9)
            {
                LOG("Amount is 9, unpacking extras\n");
                amount = 0;
                int shift = 0;
                while (1)
                {
                    int8_t next = *(int8_t*) (in++);
                    LOG("Next: %d\n", next);
                    if (next < 0)
                    {
                        amount |= (next & 0x7f) << shift;
                        shift += 7;
                        LOG("New amount: %d\n", amount);
                    }
                    else
                    {
                        amount |= (next << shift);
                        LOG("Amount is %d\n", amount);
                        break;
                    }
                }

                amount += 8;
            }

            LOG("Copying amount %d: %p %p\n", amount, out, out - offset);
            for (int i = 0; i < amount; i++)
            {
                out[i] = out[i - offset];
            }
            out += amount;
        }

        nibbles <<= 4;
    }

    return dst;
}

static void saveBufferToFile(const char* buffer, size_t size, const char* filename)
{
    FILE* out = fopen(filename, "wb");
    if (out == NULL)
    {
        LOG("Cannot create output file!\n");
        return;
    }

    fwrite(buffer, size, 1, out);

    fclose(out);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s [SRC_PATH] [DST_PATH]\n", argv[0]);
        return -1;
    }
    
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL)
    {
        printf("Cannot open input file!\n");
        return -1;
    }
    fseek(in, 0, SEEK_END);
    int srcSize = ftell(in);
    fseek(in, 0, SEEK_SET);
    char* src = malloc(srcSize);
    size_t fread_result = fread(src, srcSize, 1, in);
    fclose(in);

    uint32_t firstNibble = 0;
    char* dst = malloc(MAX_COMP_SIZE);
    LZ4_streamHC_t* state = LZ4_createStreamHC();
#ifdef FAVOR_DECOMPRESSION_SPEED
    LZ4_favorDecompressionSpeed(state, 1);
#endif
    LZ4_setCompressionLevel(state, COMPRESSION_LEVEL);  
    sCurrentNibblePendingOutputPtr = &firstNibble;
    LOG("src=%p dst=%p srcSize=%u", src, dst, srcSize);
    int compSize = LZ4_compress_HC_continue(state, (char*)src, dst, srcSize, MAX_COMP_SIZE);
    LZ4_freeStreamHC(state);
    if (sCurrentNibblePendingOutputPtr)
    {
        printf("Error: Nibble output pointer is not NULL after compression\n");
        abort();
    }
    if (0 == compSize)
    {
        printf("Compression failed!\n");
        return -1;
    }

#if 0
    char* buf = malloc(8 * 1024 * 1024);
    patch_lz4_block(dst, compSize, buf, 8 * 1024 * 1024);
    free(buf);
#endif

    FILE* out = fopen(argv[2], "wb");
    if (out == NULL)
    {
        printf("Cannot create output file!\n");
        return -1;
    }

    uint32_t compSizeBE = __builtin_bswap32(compSize);
    uint32_t srcSizeBE = __builtin_bswap32(srcSize);
    uint32_t magicHeader = 'LZ4T';

    fwrite(&magicHeader  , 1, sizeof(magicHeader), out);
    fwrite(&srcSizeBE    , 1, sizeof(srcSizeBE)  , out);
    fwrite(&compSizeBE   , 1, sizeof(compSizeBE) , out);
    fwrite(&firstNibble  , 1, sizeof(firstNibble), out);

    fwrite(dst, compSize, 1, out);

    fclose(out);

    free(dst);

    {
        FILE* in = fopen(argv[2], "rb");
        if (in == NULL)
        {
            printf("Cannot open input file!\n");
            return -1;
        }
        fseek(in, 0, SEEK_END);
        int compTestSize = ftell(in);
        fseek(in, 0, SEEK_SET);
        char* compTest = malloc(compTestSize);
        size_t fread_result = fread(compTest, compTestSize, 1, in);
        fclose(in);

        char* dec = lz4t_unpack(compTest);

        if (0 != memcmp(dec, src, compTestSize))
        {
            printf("Compression failed!\n");
            int i;
            for (i = 0; i < compTestSize; i++)
            {
                if (dec[i] != src[i])
                {
                    printf("Mismatch at %d: %x != %x\n", i, dec[i], src[i]);
                    saveBufferToFile(dec, compTestSize, "dec.bin");
                    break;
                }
            }
            return -1;
        }

        free(dec);
        free(compTest);
    }

    free(src);
    return 0;
}
