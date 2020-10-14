// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) *'z';

// Initialize words in the dictionary counter
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    int index = hash(word);

    // Access linked list at that index in the hash table
    node *cursor = table[index];

    // Keep moving cursor until get to NULL, checking each node for the word
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    // The word wasn't found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Add all of the ASCII values of the word
    int hash = 0;
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }

    // Hash value is sum modded by array size
    hash = sum % N;

    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Declare a buffer
    char word_tmp[LENGTH + 1];

    // Read words from file one at a time
    while (fscanf(file, "%s", word_tmp) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy word into node
        strcpy(n->word, word_tmp);

        // Hash word to obtain a hash value
        int index = hash(word_tmp);

        // Insert node into hash table, at the front of the list
        if (table[index] == NULL)
        {
            // Set first element in the linked list pointer to null
            n->next = NULL;

            // Set first element in the linked list to be new node
            table[index] = n;
        }
        else
        {
            // Set new node next pointer to be the first element in the linked list
            n->next = table[index];

            // Reset first element in the linked list to be new node
            table[index] = n;
        }

        // Count the number of words
        word_count++;
    }

    // Close dictionary file
    fclose(file);

    // Successfully loaded
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Repeat for every bucket in the table
    for (int i = 0; i < N; i++)
    {
        // Access linked list at that index in the hash table
        node *cursor = table[i];

        // Free the linked list until the end of it
        while (cursor != NULL)
        {
            // Set temporary variable to be equal to the next node
            node *tmp = cursor->next;

            // Free current node
            free(cursor);

            // Set current node equal to the next node which was saved in the temp variable
            cursor = tmp;
        }
    }

    // Successfully unloaded
    return true;
}
