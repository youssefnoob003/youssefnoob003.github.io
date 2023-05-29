#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

typedef uint8_t BYTE;

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1

    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Error loading the file\n");
        return 2;
    }

    // Read header
    // TODO #3
    WAVHEADER *header = malloc(sizeof(WAVHEADER));
    fread(header, 1, 44, input);

    // Use check_format to ensure WAV format
    // TODO #4

    if (check_format(*header) == 0)
    {
        printf("INVALID FORMAT\n");
        return 3;
    }

    // Open output file for writing
    // TODO #5

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Error loading the file\n");
        return 2;
    }

    // Write header to file
    // TODO #6

    fwrite(header, 1, 44, output);

    // Use get_block_size to calculate size of block
    // TODO #7

    int block_size = get_block_size(*header);

    // Write reversed audio to file
    // TODO #8


    BYTE *data[500000];
    data[0] = malloc(sizeof(BYTE) * block_size);
    int index = 0;

    while (fread(data[index], 1, block_size, input) == block_size)
    {
        index++;
        data[index] = malloc(sizeof(BYTE) * block_size);
    }
    free(data[index]);

    for (int i = index - 1; i>=0; i--)
    {
        fwrite(data[i], 1, block_size, output);
        free(data[i]);
    }

    free(header);
    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    return (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E');
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.bitsPerSample * header.numChannels / 8;
}