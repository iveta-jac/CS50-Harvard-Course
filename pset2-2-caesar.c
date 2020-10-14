#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool isdigits(string array);
char cipher(char symbol, char start, char key);

int main(int argc, string argv[])
{
    // Ensure only single command-line argument, a non-negative integer
    if (argc != 2 || !isdigits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert from a string to an int
    int key = atoi(argv[1]);

    string p = get_string("plaintext: ");
    printf("ciphertext: ");

    // Plaintext encryption, one char by one
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        char c = p[i];

        // Check if char is alphabetic, rotate it
        if (isalpha(c))
        {
            // If char is uppercase, remain uppercase
            if (isupper(c))
            {
                printf("%c", cipher(c, 'A', key));
            }

            // If char is lowercase, remain lowercase
            else if (islower(c))
            {
                printf("%c", cipher(c, 'a', key));
            }
        }

        // If it's not alphabetic, leave the character as-is
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}

// Check if all chars are digits
bool isdigits(string array)
{
    // Iterate over the provided argument
    for (int i = 0, n = strlen(array); i < n; i++)
    {
        // If char is not a digit
        if (!isdigit(array[i]))
        {
            return false;
        }
    }

    // If char is a digit
    return true;
}

// Encryption using Caesar’s cipher formula
char cipher(char symbol, char start, char key)
{
    return (symbol - start + key) % 26 + start;
}
