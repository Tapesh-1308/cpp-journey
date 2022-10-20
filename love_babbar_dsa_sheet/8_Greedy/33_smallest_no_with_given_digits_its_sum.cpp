// Find the smallest number with given sum of digits as S and number of digits as D.
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(D)
// Auxiliary Space: O(D)

// function to find the smallest, S -> sum and D -> number of digits
string smallestNumber(int S, int D)
{
    // if given sum is greater than maximimum possible sum, return -1
    // S = 37, D = 4  Number -> 9999 => 36(maximum), 37 > 36(9*4) ==> -1
    if (S > 9 * D)
        return "-1";

    // string to create answer
    string ans = "";

    // start from the least significant digit (last)
    for (int i = D - 1; i >= 0; i--)
    {
        // if sum is greater than 9, put 9 in answer
        if (S > 9)
        {
            ans = '9' + ans;
            S -= 9; // emove 9 from sum
        }
        // in this case S value lies in 1-9
        else
        {
            // in case when we come to firt digit, put remaining in first position(which is definately less than 9)
            if (i == 0)
                ans = to_string(S) + ans;

            // if this is not the case
            else
            {
                // remove one from the remaining sum, we will use it on i=0(MSdigit)
                ans = to_string(S - 1) + ans; // now add remaining sum on curr position
                i--;                          // move one pos left

                // Now we just need 1 on the first place and remaining digit must be flled by 0
                while (i > 0)
                { // when i reach 0 break loop
                    ans = '0' + ans;
                    i--;
                }
                // add 1 on first digit
                ans = '1' + ans;
            }
        }
    }

    // return the generated string at the end
    return ans;
}

int main()
{
    // S -> sum and D -> number of digits
    int S, D;
    cout << smallestNumber(S, D) << endl;
    return 0;
}