// Outputs Swap Values

// Author : Tek Chand
// 31th March, 2019
// Quiz Problem : 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// Helper functions
int get_int(char argv[]);
int is_int_array(const char *array);
int sum(int array[], int size);
int check(int array1[], int size1, int array2[], int size2);

int main(int argc, char *argv[])
{

    if(argc != 3)
    {
        printf("Usage: positive integer\n");
    }

    // Prompt user to enter key value
    int l1 = get_int(argv[1]);
    int l2 = get_int(argv[2]);
    int value1, value2;
    int arr1[MAX_INPUT_LENGTH], arr2[MAX_INPUT_LENGTH];
    int i;
    for(i = 0; i < l1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for(i = 0; i < l2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    if(!check(arr1, l1, arr2, l2))
    {
        printf("Not Possible\n");
    }
    return 0;
}

int check(int array1[], int size1, int array2[], int size2)
{
    int i,j;
    if((sum(array1, size1)+sum(array2, size2)) % 2 == 0)
    {
        for(i = 0; i < size1; i++)
        {
            for(j = 0; j < size2; j++)
            {
                int newsum1 = sum(array1, size1) - array1[i]+ array2[j];
                int newsum2 = sum(array2, size2) - array2[j]+ array1[i];
                if(newsum1 == newsum2)
                {
                    printf("%d, %d",array1[i], array2[j]);
                    return 1;
                }
            }
        }
    }
    return 0;

}

int sum(int array[], int size)
{
    int total = 0;
    for(int i = 0; i < size; i++)
    {
        total = total + array[i];
    }
    return total;
    
} 
// Returns a valid integer value entered through stdin
int get_int(char argv[])
{
    int value;
    while(!is_int_array(argv))
    {
        printf("Usage: positive integer\n");
        scanf("%s",argv);
    }
    sscanf(argv, "%d", &value);
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
        if (isdigit(*array) == 0)
        {
            return 0;
        }
        *array++;
    }
    return 1;
}
