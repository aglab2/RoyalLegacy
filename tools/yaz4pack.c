#include "zlib-ng.h"

#include <stdlib.h>
#include <stdio.h>

// must be between 6 and 9
#define COMPRESSION_LEVEL 9
#define MAX_COMP_SIZE (8*1024*1024)

static const size_t ChunksPerGroup = 8;
typedef uint8_t group_header_t;
static const size_t MaximumMatchLength = 0xFF + 0x12;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct
{
    size_t m_written_amount;
    uint8_t* m_result;
    size_t m_pending_chunks;
    group_header_t m_group_header;
    size_t m_group_header_offset;
} group_writer_t;

static void reset(group_writer_t*);
static void init(group_writer_t* self, uint8_t* m_buffer)
{
    self->m_written_amount = 0;
    self->m_result = m_buffer;
    reset(self);
}

static void push_byte(group_writer_t* self, uint8_t b)
{
    self->m_result[self->m_written_amount++] = b;
}

static void write_match(group_writer_t* self, uint32_t distance, uint32_t length);
static void handle_zlib_match(group_writer_t* self, uint32_t dist, uint32_t lc)
{
    if (dist == 0)
    {
        // Literal.
        self->m_group_header |= 1 << (7 - self->m_pending_chunks);
        push_byte(self, lc);
    }
    else
    {
        // Back reference.
        static const uint32_t kZlibMinMatch = 3;
        write_match(self, dist - 1, lc + kZlibMinMatch);
    }

    ++self->m_pending_chunks;
    if (self->m_pending_chunks == ChunksPerGroup)
    {
        self->m_result[self->m_group_header_offset] = self->m_group_header;
        reset(self);
    }
}

static void _handle_zlib_match(void* opaque, uint32_t dist, uint32_t lc)
{
    handle_zlib_match((group_writer_t*)opaque, dist, lc);
}

// Must be called after zlib has completed to ensure the last group is written.
static void finalise(group_writer_t* self)
{
    if (self->m_pending_chunks != 0)
        self->m_result[self->m_group_header_offset] = self->m_group_header;
}

static void reset(group_writer_t* self)
{
    self->m_pending_chunks = 0;
    self->m_group_header = 0;
    self->m_group_header_offset = self->m_written_amount;
    push_byte(self, 0xff);
}

static void write_match(group_writer_t* self, uint32_t distance, uint32_t length) 
{
    if (length < 18)
    {
        push_byte(self, ((length - 2) << 4) | (uint8_t)(distance >> 8));
        push_byte(self, (uint8_t)(distance));
    }
    else
    {
        // If the match is longer than 18 bytes, 3 bytes are needed to write the match.
        const size_t actual_length = MIN(MaximumMatchLength, length);
        push_byte(self, (uint8_t)(distance >> 8));
        push_byte(self, (uint8_t)(distance));
        push_byte(self, (uint8_t)(actual_length - 0x12));
    }
}

typedef struct
{
    const uint8_t* data;
    size_t len;
} compress_result_t;

static compress_result_t compress(const uint8_t* src, size_t srcLen, int level)
{
    group_writer_t writer;
    init(&writer, malloc(MAX_COMP_SIZE));

    // Let zlib do the heavy lifting.
    char dummy[8];
    size_t dummy_size = sizeof(dummy);
    const int ret = zng_compress2(dummy, &dummy_size, src, srcLen, level, _handle_zlib_match, &writer);
    if (ret != Z_OK)
        abort();

    finalise(&writer);
    
    compress_result_t result;
    result.data = writer.m_result;
    result.len = writer.m_written_amount;

    return result;
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

    FILE* out = fopen(argv[2], "wb");
    if (out == NULL)
    {
        printf("Cannot create output file!\n");
        return -1;
    }

    compress_result_t result = compress(src, srcSize, COMPRESSION_LEVEL);
    uint8_t* dst = (uint8_t*)result.data;
    uint32_t compSize = result.len;

    uint32_t compSizeBE = __builtin_bswap32(compSize);
    uint32_t srcSizeBE = __builtin_bswap32(srcSize);
    uint32_t magicHeader = 'YAZ4';
    uint32_t magicFooter = 'YBZ4';

    fwrite(&magicHeader, 1, sizeof(magicHeader), out);
    fwrite(&srcSizeBE  , 1, sizeof(srcSizeBE)  , out);
    fwrite(&compSizeBE , 1, sizeof(compSizeBE) , out);
    fwrite(&magicFooter, 1, sizeof(magicFooter), out);  

    fwrite(dst, compSize, 1, out);

    fclose(out);

    free(src);
    free(dst);

    return 0;
}
