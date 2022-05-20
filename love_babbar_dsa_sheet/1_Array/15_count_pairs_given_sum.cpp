#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int count = 0;

        //Method 1 TC O(N^2) SC O(1)
        /*for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (arr[i] + arr[j] == k)
                    count++;
        return count;*/

        //Method 2 TC O(N) SC O(N)
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            if(m.find(k-arr[i]) != m.end())
                count += m[k-arr[i]];
            m[arr[i]]++;
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}