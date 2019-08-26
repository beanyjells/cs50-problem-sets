// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
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

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        node *newnode = malloc(sizeof(node));

        //in case newnode == NULL
        if (!newnode)
        {
            free(newnode);
            return false;
        }
        strcpy(newnode->word, word);

        //get the hash value of the word
        int hashvalue = hash(word);

        //in case the N array is empty
        if (!hashtable[hashvalue])
        {
            hashtable[hashvalue] = newnode;
            newnode->next = NULL; //add word to a node that points to null
        }
        else //in case the pointer already exists
        {
            node *head = hashtable[hashvalue];
            newnode->next = head;
            head = newnode; //add it to the linked list
        }
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
    //scan the list with a new cursor
    node *cursor = hashtable[hash(word)];
    while (cursor != NULL)
    {
        int check = strcasecmp(cursor->word, word);

        if (check == 0)
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
        //introduce a new cursor to traverse the list
        node *cursor_free;
        cursor_free = hashtable[i];

        //free nodes
        while (cursor_free)
        {
            node *temp = cursor_free;
            cursor_free = cursor_free->next;
            free(temp);
        }

        //clean the hashtable
        hashtable[i] = NULL;
    }
    return true;
}
