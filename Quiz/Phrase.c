// Outputs Phrase text

// Author : Tek Chand
// 31th March, 2019
// Quiz Problem : 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// Helper functions
char *get_int(char argv[]);
int is_int_array(const char *array);
void phrasetext(char number[]);
void single_digit(char *number, int index);
void phrasetext(char *number);
void two_digit(char *number, int index);

// Phrase text for single digit
const char *single_digits[] = { "", "one", "two",  
                               "three", "four","five",  
                               "six", "seven", "eight", "nine"}; 

// Phrase text for two digits   
const char *two_digits[] = {"ten", "eleven", "twelve",  
                               "thirteen", "fourteen", 
                               "fifteen", "sixteen",  
                               "seventeen", "eighteen", "nineteen"}; 
  
// Phrase text for 2nd digits  
const char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty", 
                            "sixty", "seventy", "eighty", "ninety"}; 
  
const char *tens_power[] = {"", "thousand", "thousand", "thousand", "million", "million", "million", "billion", "billion", "billion", "trillion"};


int main(int argc, char *argv[])
{

    if(argc != 2)
    {
        printf("Usage:  input\n");
    }
    char *number;
    // Prompt user to enter a positive number
    number = get_int(argv[1]);
    phrasetext(number);
    return 0;
}

// Returns a valid integer value entered through stdin
char *get_int(char argv[])
{
    //int value;
    while(!is_int_array(argv))
    {
        printf("Usage: positive integer: ");
        scanf("%s",argv);
    }
    return argv;
}

// Returns if given char array conatins valid integer
// Returns false for empty array

int is_int_array(const char *array)
{
    // Empty array or starting from '0'
    if(*array == '\0' || *array == '0')
    {
        return 0;
    }
    while (*array)
    {
        if (isdigit(*array) == 0)
        {
            return 0;
        }
        *array++;
    }
    return 1;
}

// Returns Phrasetext
void single_digit(char *number, int index)
{
    printf("%s ",single_digits[*(number+index) - '0']);
}

void two_digit(char *number, int index)
{
    // for two digits eg. eleven, tweleve...
    if(*(number + index) - '0' == 1)
    {
        printf("%s ", two_digits[*(number + index + 1) - '0']);
    }

    // for ten multiple eg. twenty, thirty...
    else
    {
        printf("%s ", tens_multiple[*(number + index) - '0']);
        printf("%s ", single_digits[*(number + index + 1) - '0']);
    }
}
void phrasetext(char *number)
{
    int length = strlen(number);
    // total digits
    int total_digits = length; 
    // index start from 1st digit
    int index = 0;
    int flag = 1;

    // if there is only single digit number
    if(length == 1)
    {
        single_digit(number, index);
    }

    // if there is only two digit number
    else if(length == 2)
    {
        two_digit(number, index);
    }
    // if there is more than two digit number
    else
    {
        while(length > 0 && index < total_digits)
        {
            if(length == 2)
            {
                two_digit(number, index);
            }
            else if (length % 3 == 0)
            {
                if(number[total_digits-length] == '0')
                {
                   index = index + 1; 
                }
                else
                {
                    single_digit(number, index);
                    index = index + 1;
                    printf("hundred and ");
                }
                two_digit(number, index);
                index = index + 2;
                if (length > 3 && number[total_digits-length] != '0')
                {
                    printf("%s ",tens_power[length - 3]);
                }
            }
            // only for first and second digit.
            if (flag == 1)
            {
                if ((total_digits + 1) % 3 == 0)
                {
                two_digit(number, index);
                index = index + 2;
                printf("%s ",tens_power[length - 3]);
                flag = 0;
                }
                else if ((total_digits - 1) % 3 == 0)
                {   
                    single_digit(number, index);
                    index = index + 1;
                    printf("%s ",tens_power[length - 3]);
                    flag = 0;
                }
                
            }

            length = length -1;
                        
        }
    }

    printf("\n");
}
