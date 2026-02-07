// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    for (int i = 0; i <= HEADER_SIZE; i++)
        // Get HEADER_SIZE long char from input then put it to output
        fputc(fgetc(input), output);

    // Buffer for sample assumed to be 16 bit (2 bytes) signed value
    int16_t sample;

    // Read from buffer until it fails
    while (fread(&sample, sizeof(int16_t), 1, input) != 0)
    {
        sample *= factor; // Multiply sample by factor
        // Write from buffer to output
        fwrite(&sample, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
