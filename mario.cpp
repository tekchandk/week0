#include <iostream> 
#include <bits/stdc++.h> 
#include <string>
using namespace std; 

// String has or has not  value between 1 and 8  
int isInteger(string str)
{
    int flag = 1;
    if (str[0]-'0' <1 || str[0]-'0'>8 || str[1]!='\0')
    {
        flag=0;
    }
    return flag;
}

int main(void)
{
    string str;
    do
    {
        cout << "Height: ";
    	cin >> str;
    }
    while (!isInteger(str));

    
    int n = str[0] - '0';

    for (int i = 0; i < n; i++)
    {
        // No. of spaces before '#'
        for (int j = n - 1; j >= i + 1; j--)
        {
            cout << (" ");
        }
        // For right half
        for (int k = 0; k <= i; k++)
        {
            cout << ("#");
        }
        // Between right half and left half
        cout << (" ");
        // For light half
        for (int k = 0;k <= i; k++)
        {
            cout << ("#");
        }
        cout << ("\n");  
    }
        

}
