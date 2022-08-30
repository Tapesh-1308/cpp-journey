// Buy Maximum Stocks if i stocks can be bought on i-th day
#include <bits/stdc++.h>
using namespace std;

// Return the maximum stocks
int buyMaximumProducts(int n, int k, int price[])
{
	vector<pair<int, int> > v;

	// Making pair of product cost and number of day
	for (int i = 0; i < n; ++i)
		v.push_back(make_pair(price[i], i + 1));

	// Sorting the vector pair.
	sort(v.begin(), v.end());

	// Calculating the maximum number of stock count.
	int ans = 0;
	for (int i = 0; i < n; ++i) {
        // buy the minimum of numbers of stocks (available, enough money to buy)
		ans += min(v[i].second, k / v[i].first);
        // decrease the amount of stock you have bought
		k -= v[i].first * min(v[i].second, (k / v[i].first));
	}

    // return the maximum bought stocks 
	return ans;
}

int main()
{
	int price[] = { 10, 7, 19 };
	int n = sizeof(price)/sizeof(price[0]);
	int k = 45;

	cout << buyMaximumProducts(n, k, price) << endl;

	return 0;
}
