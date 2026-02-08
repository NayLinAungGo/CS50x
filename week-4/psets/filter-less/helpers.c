#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Initialize pixel pointer at the first one
    RGBTRIPLE *pixel = &image[0][0];
    // Loop through each pixel
    for (int i = 0; i < height * width; i++)
        // Assign gray-scale converted value to all the color channels
        pixel[i].rgbtRed = pixel[i].rgbtGreen = pixel[i].rgbtBlue =
            // Luma-corrected grayscale formula used by GIMP
            round(pixel[i].rgbtRed * 0.3 + pixel[i].rgbtGreen * 0.59 + pixel[i].rgbtBlue * 0.11);

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
