#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }

    // Positive integer between 1 and 8, inclusive
    while (height < 1 || height > 8);

    // Make rows
    for (int i = 0; i < height; i++)
    {
        // First pyramid
        for (int j = 0; j < height; j++)
        {
            if (i + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        // 2 spaces
        printf("  ");

        // Second pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // New row
        printf("\n");
    }
}