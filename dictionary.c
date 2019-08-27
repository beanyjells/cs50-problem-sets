// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

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

//Counter set to see the number of words added to the dictionary
int dictionary_count = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return (tolower(word[0]) - 'a');
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

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s\n", word) != EOF)
    {
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            unload();
            return false;
        }

        //get the hash value of the word
        int hashvalue = hash(word);

        //link it to the front of the list
        strcpy(newnode->word, word);
        newnode->next = hashtable[hashvalue];
        hashtable[hashvalue] = newnode;
        dictionary_count++; //count it as a word added to the dictionary
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (dictionary_count > 0)
    {
        return dictionary_count;
    }
    else
    {
        return 0;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hashvalue = hash(word);
    //scan the list with a new cursor set to the front of the list
    node *head = NULL;
    node *cursor = head = hashtable[hashvalue];

    while (cursor != NULL)
    {
        int checking = strcasecmp(cursor->word, word); //compare the words and see if they are similar

        if (checking == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next; //move to what's next
        }
    }
    return false;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //introduce a new cursor to traverse the list
    node *cursor_free;

    for (int i = 0; i < N; i++)
    {
        cursor_free = hashtable[i];

        //free nodes
        while (cursor_free != NULL)
        {
            node *temp = cursor_free;
            cursor_free = cursor_free->next;
            free(temp);
        }
        hashtable[i] = NULL; //make sure hashtable is free
    }
    return true;
}
