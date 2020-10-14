#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average pixel value
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Set each color value to the average value
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }
    return;
}

// The result must be an integer between 0 and 255, inclusive (sepia)
int cap(int value)
{
    if (value > 255)
    {
        value = 255;
    }
    return value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            int originalRed = image[i][j].rgbtRed;

            // Calculate each new color value using the Sepia formula
            image[i][j].rgbtBlue = cap(round(.131 * originalBlue + .534 * originalGreen + .272 * originalRed));
            image[i][j].rgbtGreen = cap(round(.168 * originalBlue + .686 * originalGreen + .349 * originalRed));
            image[i][j].rgbtRed = cap(round(.189 * originalBlue + .769 * originalGreen + .393 * originalRed));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary array to swap values
    RGBTRIPLE temp[width];

    for (int i = 0; i < height; i++)
    {
        // Swap pixels on horizontally opposite sides
        for (int j = 0; j < width / 2; j++)
        {
            temp[j] = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp[j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary array to start creating blurred image
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = 0, green = 0, red = 0;
            int counter = 0;

            // Filter matrix. Cycle neighbor pixels 3x3
            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    // Ignore pixels off the grid
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        // Sum the color amounts for each looped pixel
                        blue += image[x][y].rgbtBlue;
                        green += image[x][y].rgbtGreen;
                        red += image[x][y].rgbtRed;
                        counter++;
                    }
                }
            }

            // New pixel value, averaging the color values of neighboring pixels
            temp[i][j].rgbtBlue = round((float)blue / counter);
            temp[i][j].rgbtGreen = round((float)green / counter);
            temp[i][j].rgbtRed = round((float)red / counter);
        }
    }

    // Replace original image with blurred image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
