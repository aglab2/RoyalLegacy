#include "lz4ultra/lib.h"
#include "lz4ultra/shrink_inmem.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_COMP_SIZE (8*1024*1024)

// #define FAVOR_DECOMPRESSION_SPEED

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

    char* dst = malloc(MAX_COMP_SIZE);

    size_t compSize = lz4ultra_compress_inmem(src, dst, srcSize, MAX_COMP_SIZE, LZ4ULTRA_FLAG_RAW_BLOCK | LZ4ULTRA_FLAG_FAVOR_RATIO, 7);
    if (-1 == compSize)
    {
        printf("Compression failed!\n");
        abort();
    }

#ifdef FAVOR_DECOMPRESSION_SPEED
    LZ4_favorDecompressionSpeed(state, 1);
#endif

    FILE* out = fopen(argv[2], "wb");
    if (out == NULL)
    {
        printf("Cannot create output file!\n");
        return -1;
    }

    uint32_t compSizeBE = __builtin_bswap32((uint32_t) compSize);
    uint32_t srcSizeBE = __builtin_bswap32(srcSize);
    uint32_t magicHeader = 'LZ4H';
    uint32_t magicFooter = 'LZ4F';

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
