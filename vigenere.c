// Outputs Cipher text

// Author : Tek Chand
// 5th January 2018
// Week : 2, Problem : 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// Helper functions
char* get_char(const char* message);
int is_alpha_array(const char *array);
char* ciphertext(char *keyword, char *plaintext);

int main(void)
{
    char *keyword;
    char *plaintext;
    keyword = (char *)malloc(50* sizeof(char));
    // Prompt user to enter keyword
    keyword = get_char("Keyword: ");
    plaintext = (char *)malloc(50* sizeof(char));
    printf("plaintext: ");
    // Enter plaintext
    scanf("\n%[^\n]",plaintext);
    printf("ciphertext: ");
    printf("%s\n", ciphertext(keyword, plaintext));
}

// Returns a valid integer value entered through stdin
char* get_char(const char* message)
{
    char *input;
    input = (char *)malloc(50* sizeof(char));
    do
    {
        printf("%s",message);
        scanf("%s",input);
    }while(!is_alpha_array(input));
    //sscanf(input, "%d", &value);
    return input;
}

// Returns if given char array conatins valid integer
// Returns false for empty array

int is_alpha_array(const char *array)
{
    // Empty array
    if(*array == '\0')
    {
        return 0;
    }
    while (*array)
    {
        if (islower(*array++) == 0 && isupper(*array++) == 0)
        {
            return 0;
        }
    }
    return 1;
}




// Returns ciphertext
char* ciphertext(char *keyword, char *plaintext)
{
    int i = 0, j = 0;
    int length = strlen(keyword);
    char* Ciphertext;
    Ciphertext = malloc (sizeof (char) * 50);

    while (plaintext[i] != '\0')
    {
        if (islower(plaintext[i]) && islower(keyword[j])) 
        {
            Ciphertext[i] = 'a' + (plaintext[i] - 'a' + (keyword[j] - 'a'))%26;
            j++;
        }
        else if (isupper(plaintext[i]) && islower(keyword[j]))
        {
            Ciphertext[i] = 'A' + (plaintext[i] - 'A' + (keyword[j] - 'a'))%26;
            j++;
        }
        else if (islower(plaintext[i]) && isupper(keyword[j])) 
        {
            Ciphertext[i] = 'a' + (plaintext[i] - 'a' + (keyword[j] - 'A'))%26;
            j++;
        }
        else if (isupper(plaintext[i]) && isupper(keyword[j])) 
        {
            Ciphertext[i] = 'A' + (plaintext[i] - 'A' + (keyword[j] - 'A'))%26;
            j++;
        }
        else
        {
            Ciphertext[i] = plaintext[i];
        }
        i++;  
        if(j == length)
        {
            j = 0;
        }
    }
     
    return Ciphertext;
}