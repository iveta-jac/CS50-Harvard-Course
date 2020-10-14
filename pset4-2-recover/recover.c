#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open memory card
    FILE *file = fopen(argv[1], "r");

    // Check if the file was successfully opened
    if (!file)
    {
        return 1;
    }

    // Create variables
    char filename[8];
    FILE *image;
    int counter = 0;
    BYTE buffer[BLOCK_SIZE];

    // Read 512 bytes into a buffer, repeat until end of card
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous jpeg file if it's not the first one
            if (counter > 0)
            {
                fclose(image);
            }

            // Create filename
            sprintf(filename, "%03i.jpg", counter++);

            // Open new JPEG file
            image = fopen(filename, "w");

            // Check if new file created successfully
            if (!image)
            {
                return 1;
            }
        }

        // If already found jpeg, keep writing to currently opened file
        if (counter > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
    }

    // Close all opened files
    fclose(image);
    fclose(file);

    return 0;
}
