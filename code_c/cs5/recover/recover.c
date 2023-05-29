#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");


    int counter = -1;
    BYTE *buffer = malloc(sizeof(BYTE) * 512);

    FILE *output = fopen("tmp.jpg", "w");

    while (fread(buffer, 1, 512, file) == 512)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xF0) == 0xE0)
        {

            fclose(output);
            counter++;
            char *name = malloc(sizeof(char) * 8);
            sprintf(name, "%03i.jpg", counter);
            output = fopen(name, "w");
            fwrite(buffer, 1, 512, output);
            free(name);
        }
        else
        {
            fwrite(buffer, 1, 512, output);
        }
    }
    fclose(output);
    free(buffer);
    fclose(file);
}