#include <iostream> 
#include <bits/stdc++.h> 
#include <string>
using namespace std;

// Returns string is a integer or not
int isInteger(string str)
{
    int i = 0, flag = 1;
    while (i < str.length())
    {
        if(str[i] - '0' >= 0 && str[i] - '0' <= 9)
        {
            i++;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main (void)
{
    long long i, xadd, x2;
    int addsum, x2prod, sum;
    string str;

    // Get user's credit card number
    do
    {
        cout << "Enter your credit card number:\n";
        cin >> str;
    }
    while (!isInteger(str)); 

    // String to long integer
    i= stol(str);       

    // Sum every other digit starting from 1st to the the last
    for (xadd = i, addsum = 0; xadd > 0; xadd /= 100)
        addsum += xadd % 10;

    // Double every other digit starting from 2nd to last
    // Then sum the individual digits of these products
    for (x2 = i / 10, x2prod = 0; x2 > 0; x2 /= 100)
    {
        if (2 * (x2 % 10) > 9)
        {
            x2prod += (2 * (x2 % 10)) / 10;
            x2prod += (2 * (x2 % 10)) % 10;
        }
        else
            x2prod += 2 * (x2 % 10);
    }
    
    sum = addsum + x2prod;

    // Check to see if the credit card number is in the range
    if (sum % 10 == 0)
    {   
        if ((i >= 340000000000000 && i < 350000000000000) || (i >= 370000000000000 && i < 380000000000000))
            cout<<("AMERICAN EXPRESS\n");
        else if ( i >= 5100000000000000 && i < 5600000000000000 )
            cout<<("MASTERCARD\n");
        else if ((i >= 4000000000000 && i < 5000000000000) || (i >= 4000000000000000 && i < 5000000000000000))
            cout<<("VISA\n");
        else
            cout<<("INVALID\n");
    }
    else
        cout<<("INVALID\n");

    return 0;
}