// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
void deload(node *x);

// TODO: Choose number of buckets in hash table
const unsigned int N = 3000;
int size_dict = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    while (cursor->next != NULL)
    {
        if (strcasecmp(word, cursor->next->word) == 0) return true;
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (toupper(word[0]) - 'A') + ((strlen(word) % 15)) * 26 ;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input = fopen(dictionary, "r");
    if (!input)
    {
        printf("Error opening file!\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = malloc(sizeof(node));
        table[i]->next = NULL;
    }

    char *word = malloc(sizeof(char) * LENGTH);
    while(fscanf(input, "%s", word) == 1)
    {
        node *new = malloc(sizeof(node));
        strcpy(new->word, word);
        int index = hash(word);
        new->next = table[index]->next;
        table[index]->next = new;
        size_dict++;
    }

    free(word);
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_dict;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        deload(table[i]);
    }
    return true;
}

void deload(node *x)
{
    if (x->next == NULL)
    {
        free(x);
        return;
    }
    deload(x->next);
    free(x);
}
