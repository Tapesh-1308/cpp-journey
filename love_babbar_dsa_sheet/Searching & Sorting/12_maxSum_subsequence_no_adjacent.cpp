#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Recusrion TC O(2^n * n) SC O(n) 

// Recursive function
int solve(vector<int> &arr, int index){
    // Base cases
    if(index == 0) return arr[index]; // If index is 0
    if(index < 0) return 0; // If index become negative return 0

    // pick -> if we take curr element then solve index-2, skip adjacent
    int pick = arr[index] + solve(arr, index-2);

    // notpick -> if we skip curr element then solve for index-1
    int notPick = 0 + solve(arr, index-1);

    // return the max of both pick and not pick
    return max(pick, notPick);
}

int getMaxSum(vector<int> &arr) {
    int n(arr.size()); // size of arr

    // Stores the sum return by recursive function
    int sum = solve(arr, n-1);
    return sum;
} */

/* Method - 2 Memoization TC O(N) SC O(N+N)
int solve(vector<int> &arr, int index, vector<int> &dp){
    if(index == 0) return arr[index];
    if(index < 0) return 0;

    // If we get same function call return from dp
    if(dp[index] != -1) return dp[index];

    int pick = arr[index] + solve(arr, index-2, dp);
    int notPick = 0 + solve(arr, index-1, dp);

    // store ans also in dp
    return dp[index] = max(pick, notPick);
}

int getMaxSum(vector<int> &arr) {
    int n(arr.size());

    // Dp array to store overlapping subproblems
    vector<int> dp(n, -1);

    int sum = solve(arr, n-1, dp);
    return sum;
} */

/* method - 3 Tabulation TC O(N) SC O(N)
int getMaxSum(vector<int> &arr) {
    int n(arr.size());
    vector<int> dp(n, 0);

    // 1st Base case if index==0
    dp[0] = arr[0];

    // Traverse from i=1, as we already a[0] in dp 
    for(int i=1; i<n; i++) {
        // If we pick a[0] + dp[i-2], if i-2 is negative this is the second base case, just don't add it as we return 0 in previous approach
        int pick = (i-2 < 0) ? arr[i] : (arr[i] + dp[i-2]);

        // If we don't pick it
        int notPick = 0 + dp[i-1];

        // dp[i] is the max of pick and notpick 
        dp[i] = max(pick, notPick);
    }
    // Return the last element
    return dp[n-1];
} */

// Method - 4 More Space Optimization TC O(N) SC O(1)
int getMaxSum(vector<int> &arr) {
    // Instead of using dp we can use 3 variables as we only need dp[i-2], dp[i-1], dp[i]
    int n(arr.size());

    // Prev is dp[i-1]
    // Prev2 is dp[i-2]
    // curr is dp[i]
    int prev(0), prev2(0), curr(0);
	   
    // 1st base dp[0] = a[0]
    prev = arr[0];

    for(int i=1; i<n; i++) {

        int pick = (i-2 < 0) ? arr[i] : (arr[i] + prev2);
        int notPick = 0 + prev;

        curr = max(pick, notPick);
        
        // Now update i-2 will be now equal to i-1, as we will incrment i in loop i-2 + 1 = i-1 <-< prev
        prev2 = prev;
        // i-1 = i i-1 +1 = i <-< curr
        prev = curr;
    }

    // return prev as i is now n and we have to return n-1 = i-1 = prev
    return prev;
}

int main() {
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout << getMaxSum(arr) << endl;
}