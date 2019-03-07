// Implements a dictionary's functionality
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char *word;
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];
void add_word_bucket(int index, char *word);
int word_count = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0])-'a';
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
    char word[LENGTH+1];//=calloc(LENGTH+ 1,sizeof(char));

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        int index = hash(word);
        add_word_bucket(index, word);
    }
    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}
void add_word_bucket(int index, char word[LENGTH+1])
{
    node* temp = hashtable[index];
         
    	//Test to see if node is null
        if(hashtable[index] == NULL)
        {
            hashtable[index] =  (node*) malloc(sizeof(node));
            strcpy(hashtable[index]->word, word);
            word_count++;
            return;
        }
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        if(temp->next == NULL)
        {
            temp->next = (node*)malloc(sizeof(node));
            strcpy(temp->next->word, word);
            word_count++;
        }

}




// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int word_size = strlen(word); 
    char small_word[word_size+1];
    for(int i = 0; i < word_size; i++)
    {
        small_word[i] = tolower(word[i]);
    }
    int index = hash(small_word);
    node *head = hashtable[index];
    if (head != NULL)
    {
        //Points the cursor to the same location
        node* cursor = head;
        //Traverse the linked list
        while(cursor != NULL)
        {
            if(strcmp(small_word, cursor->word) == 0)
            {
                //Return true if word matches the word in our dictionary
                return true;
            }
            //Else move cursor to the next linked list
            cursor = cursor->next;
        }
    }
    return false;
}


// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // for each node in the hashtable
    for (int i = 0; i < N; i++)
    {
        // check the table for a node at that index
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
            // create a temporary node
            node* temp = cursor;
            cursor = cursor -> next;

            // free the current node
            free(temp);
        }
    }
    return true;
}