#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

	long long maxProduct(vector<int> arr, int n) {
	    long long ans = arr[0];
	    long long maxi = 1, mini = 1;
	    for(int i=0; i<n; i++){
	        if(arr[i]<0)
	            swap(maxi, mini);
	        maxi = max((long long)arr[i], maxi*(long long)arr[i]);
	        mini = min((long long)arr[i], mini*(long long)arr[i]);
	        ans = max(maxi, ans);
	    }
	    return ans;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}