#include <bits/stdc++.h>
using namespace std;

// TC - O(n)
// SC - O(n)

int main() {
    // n - number of inhabitants
    int n;
    cin >> n;

    while (1) {
        // If aᵢ ≥ 0, it means that the inhabitant living in the ith house wants to buy ai bottles of wine.
        // If aᵢ < 0, he wants to sell -aᵢ bottles of wine.
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // create separate vectors of buy and sell, which include {data, index}
        vector<pair<int, int>> buy;
        vector<pair<int, int>> sell;

        // fill vectors, if neg push in sell else push in buy
        for (int i = 0; i < n; i++) {
            if (a[i] < 0)
                sell.push_back({a[i], i});
            else
                buy.push_back({a[i], i});
        }

        // i-index of buy, j-index of sell
        int i = 0, j = 0;
        long long int ans = 0; // minimum amount of work units needed so that every inhabitant has his demand fulfilled

        while (i < buy.size() && j < sell.size()) {
            // find the number bottle that trade
            int x = min(buy[i].first, -sell[j].first);
            buy[i].first -= x;  // decrease buying requirements, 4 -> 0
            sell[j].first += x; // increase selling leads to decrease in selling requirement, -4  -> 0

            // find the distance of one house to other
            int diff = abs(buy[i].second - sell[j].second);
            ans += (x * diff); // work done -> Transporting one bottle of wine from one house to an adjacent house results in one unit of work.

            // if buying requirements fulfilled, increment i
            if (buy[i].first == 0)
                i++;

            // if selling requirements fulfilled, increment j
            if (sell[j].first == 0)
                j++;
        }

        // print ans
        cout << ans << endl;

        // take another input for other test case
        cin >> n;

        // if input is 0 break out of loop
        if (n == 0)
            break;
    }

    return 0;
}
