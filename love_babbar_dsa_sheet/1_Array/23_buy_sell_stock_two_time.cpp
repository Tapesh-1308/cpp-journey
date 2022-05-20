// C++ program to find maximum possible profit with at most two transactions
#include <bits/stdc++.h>
using namespace std;

// Returns maximum profit with two transactions on a given list of stock prices, price[0..n-1]

//Method 1 TC O(N) SC O(N) - Dynamic Programming
int maxProfit(int price[], int n)
{
	// Create profit array and initialize it as 0
	int* profit = new int[n];
	for (int i = 0; i < n; i++)
		profit[i] = 0;

	/* Get the maximum profit with only one transaction allowed. After this loop,
	   profit[i] contains maximum profit from price[i..n-1] using at most one trans. */
	int max_price = price[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		// max_price has maximum of price[i..n-1]
		max_price = max(price[i], max_price);

		// we can get profit[i] by taking maximum of:
		// a) previous maximum, i.e., profit[i+1]
		// b) profit by buying at price[i] and selling at max_price
		profit[i] = max(profit[i + 1], max_price - price[i]);
	}

	/* Get the maximum profit with two transactions allowed
	After this loop, profit[n-1] contains the result */
	int min_price = price[0];
	for (int i = 1; i < n; i++) {
		// min_price is minimum price in price[0..i]
		min_price = min(price[i], min_price);

		// Maximum profit is maximum of:
		// a) previous maximum, i.e., profit[i-1]
		// b) (Buy, Sell) at (min_price, price[i]) and add profit of other trans. stored in profit[i]
		profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
	}
	int result = profit[n - 1];

	delete[] profit; // To avoid memory leak

	return result;
}

//Method 2 TC (ON) SC O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int fb = INT_MIN, fs = 0, sb = INT_MIN, ss = 0;
        
        for(int i=0; i<prices.size(); i++){
            fb = max(fb, -prices[i]);
            fs = max (fs, fb+prices[i]);
            sb = max(sb, fs-prices[i]);
            ss = max(ss, sb+prices[i]);
        }
        
        return ss;
    }
};

int main()
{
	int price[] = { 2, 30, 15, 10, 8, 25, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	cout << "Maximum Profit = " << maxProfit(price, n);

    // Solution ob; 
    // vector<int> prices = { 2, 30, 15, 10, 8, 25, 80 };
    // cout<<ob.maxProfit(prices);
	return 0;
}
