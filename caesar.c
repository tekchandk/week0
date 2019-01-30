// Outputs Cipher text

// Author : Tek Chand
// 28 January 2018
// Week : 2, Problem : 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// Helper functions
int get_int(const char *message);
int is_int_array(const char *array);
char* ciphertext(int key, char *plaintext);

int main(void)
{
    int key;
    char plaintext[MAX_INPUT_LENGTH];
    // Prompt user to enter key value
    do
    {
        key = get_int("Key: ");
    } while(key < 0);

    printf("plaintext: ");

    // Enter plaintext
   	scanf("%s", plaintext);
    printf("%s", ciphertext(key, plaintext));

}


// Returns a valid integer value entered through stdin
int get_int(const char* message)
{
    char input[MAX_INPUT_LENGTH];
    int value;
    do
    {
        printf("%s",message);
        scanf("%s",input);
    }while(!is_int_array(input));
    sscanf(input, "%d", &value);
    return value;
}


// Returns if given char array conatins valid integer
// Returns false for empty array

int is_int_array(const char *array)
{
    // Empty array
    if(*array == '\0')
    {
        return 0;
    }
    while (*array)
    {
        if (isdigit(*array++) == 0)
        {
            return 0;
        }
    }
    return 1;
}
char* ciphertext(int key, char *plaintext)
{
    int i=0;
    char* Ciphertext;
    Ciphertext = malloc (sizeof (char) * 50);
    while (plaintext[i] != '\0')
    {
        if (islower(plaintext[i])) 
        {
            Ciphertext[i] = 'a' + (plaintext[i] - 'a' + key)%26;
        }
        else if (isupper(plaintext[i]))
        {
            Ciphertext[i] = 'A' + (plaintext[i] - 'A' + key)%26;
        }
        else
        {
            Ciphertext[i] = plaintext[i];
        }
        i++;
         
    }
     
    return Ciphertext;
}