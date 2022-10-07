// C++ program to find the minimum days on which you need to buy food from the shop so that you
// can survive the next S days
#include <bits/stdc++.h>
using namespace std;

// TC - O(1) SC O(1)

int main()
{
	int S = 10, N = 16, M = 2;

    // days on which we can buy food, excluding sundays
    int canBuy = S - S/7;

    // minimum days on which we will buy food
    int daysReq = ceil((float)(M*S)/N);
    
    // if we can survive print required days to buy food else -1 
    daysReq <= canBuy ? cout << daysReq : cout << -1;

	return 0;
}
