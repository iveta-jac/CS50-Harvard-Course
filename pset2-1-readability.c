#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string array);
int count_words(string array);
int count_sentences(string array);

int main(void)
{
    string text = get_string("Text: ");

    // Average number of letters per 100 words in the text
    float L = count_letters(text) * 100 / (float) count_words(text);

    // Average number of sentences per 100 words in the text
    float S = count_sentences(text) * 100 / (float) count_words(text);

    // Grade level computed by the Coleman-Liau formula, rounded to the nearest integer
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Count the number of letters in the text
int count_letters(string array)
{
    int sum = 0;
    for (int i = 0, n = strlen(array); i < n; i++)
    {
        // Count letters when char is an alphabet (a-z, A-Z)
        if (isalpha(array[i]))
        {
            sum++;
        }
    }
    return sum;
}

// Count the number of words in the text
int count_words(string array)
{
    int sum = 0;
    for (int i = 0, n = strlen(array); i < n; i++)
    {
        // Count words when char is a space and after it follows not a space. Don't count when space(s) are before first or after the last word
        if ((i == 0 && array[i] != ' ') || (array[i] == ' ' && array[i + 1] != ' ' && i != n - 1))
        {
            sum++;
        }
    }
    return sum;
}

// Count the number of sentences in the text
int count_sentences(string array)
{
    int sum = 0;
    for (int i = 0, n = strlen(array); i < n; i++)
    {
        // Count sentences when char is '.', '!' or '?'
        if (array[i] == '.' || array[i] == '!' || array[i] == '?')
        {
            sum++;
        }
    }
    return sum;
}