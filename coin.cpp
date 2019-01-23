#include <iostream> 
#include <bits/stdc++.h> 
#include <string>
using namespace std; 

// Returns minimum number of coins
int minCoins(int coins[], int m, int V)
{
   // Base case
   if (V == 0) return 0;

   // Initialize result
   int res = INT_MAX;

   // Try every coin that has smaller value than V
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         int sub_res = minCoins(coins, m, V-coins[i]);

         // Check for INT_MAX to avoid overflow and see if
         // Result can minimized
         if (sub_res != INT_MAX && sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
}

// Returns that input string has or has not a numarical value
int isNumber(string str)
{
    // Initilize decimal point (rdot) 
    int i = 0, flag = 1, rdot = 0;
    while (i < str.length())
    {
        // For checking numerical 
        if(str[i] - '0' >= 0 && str[i] - '0' <= 9 )
        {
            i++;
        }
        // For checking decimal 
        else if (str[i] - '.' == 0)
        {
            rdot++;
            i++;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    // For only one dot string  and more than one dot in numerical string
    if (rdot > 1 || (rdot ==1 && str.length() == 1))
    {
        flag = 0;
    }
    // String has integer or float value
    if (flag == 1 && (rdot == 1 || rdot == 0))
    {
        return flag;
    }
    return 0;
}

int main(void)
{
    float amount;
    string str;
    // Taking input till it has numerical value
    do 
    {
        cout << "Change owed: ";
        cin >> str;
    }
    while (!isNumber(str));

    // String to float value
    amount = stof(str);
    // For checking float or integer
    if (abs(amount-int(amount)) > 0)
    {
        amount = round (amount * 100);
    }

    // Coins in cashier’s drawer 
    int coins []={25,10,5,1};
    cout << minCoins(coins,4,amount);
    return 0;
}
