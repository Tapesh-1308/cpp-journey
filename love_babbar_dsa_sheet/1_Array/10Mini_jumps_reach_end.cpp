#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int canReach(int arr[], int n) {
	//Method 1 Dp Approach O(N^2)
        int* jumps = new int[n];
        if (n == 0 || arr[0] == 0)
             return -1;
     
        jumps[0] = 0;
        
         for (int i = 1; i < n; i++) {
             jumps[i] = INT_MAX;
             for (int j = 0; j < i; j++) {
                 if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                     jumps[i] = min(jumps[i], jumps[j] + 1);
                     break;
                 }
             }
         }
        return jumps[n-1];
        
	// Method 2 Greedy Approach O(n)
        int maxR = arr[0];
        int step = arr[0];
        int jump = 1;
        if (arr[0] == 0)
	    return -1;
        
        if(n==0) return 0;
        
        for(int i=1; i<n; i++){
            if(i==n-1 && step) 
                return jump;
            maxR = max(maxR, i+arr[i]);
            step--;
            if(step==0) {
                jump++;
                if(i>=maxR) return -1;
                step = maxR-1;
            }
        }
    
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  