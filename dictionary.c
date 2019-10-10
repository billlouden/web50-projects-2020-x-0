//  Implements a dictionary's functionality
//  Bill Louden

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Word counter
int wordcount = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // create a buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // We want to malloc a node for every word we scan
        node *new_node = malloc(sizeof(node));

        // Making sure that the pointer to that node doesn't point to NULL
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        else

            // Copy word into a node
        {
            strcpy(new_node->word, word);
        }

        // Insert word into a linked list
        int i = hash(word);

        // If this is the first word in the bucket
        if (hashtable[i] == NULL)
        {
            hashtable[i] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = hashtable[i];
            hashtable[i] = new_node;
        }

        wordcount++;
    }


    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Traversing linked list
    int i = hash(word);
    node *cursor = hashtable[i];

    while (cursor != NULL)
    {
        // Compare 2 strings
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor -> next;
            free(temp);
        }
        free(cursor);
    }
        return true;

}
