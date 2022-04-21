#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Recursion TC - Exponential O(N+M + 2^N+M) - SC O(N+M)
bool solve(int i, int j, string &p, string &s) {
    // If both string completely traversed
    if(i < 0 && j < 0) return true;

    // If pattern is traversed and text has some elements remaining
    if(j >= 0 && i < 0) return false;
    
    // If text is completely traversed and pattern has some elements remaining
    if(j < 0 && i >= 0) {
        // If all element are * we can return true as * can be = to 0 else return false
        for(int k=0; k<=i; k++) 
            if(p[k] != '*')
                return false;
        return true;
    }

    // If p of i and s of j matches or p of i is ? means we can check for both i-1 and j-1
    if(p[i] == s[j] || p[i] == '?') 
        return solve(i-1, j-1, p, s);
    
    // In case we got * the there are 2 condition 
        // -> 1) We can mark * as nothing and decrement i
        // -> 2) We can mark it as equal to s of j 
    // We have two check this conditions for all 0 to j
        
    if(p[i] == '*') 
        return solve(i-1, j, p, s) || solve(i, j-1, p, s);

    // This case arise when p of i != s of j    
    return false;
}

bool isMatch(string p, string s) {
    int n = p.size();
    int m = s.size();

    return solve(n-1, m-1, p, s);
} */

/* Method - Memoization - TC O(N*M) SC O(N*M + N+M)

// Due to overlapping substructre and repeated subproblems we memoize it, store function call in dp
bool solve(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
    if(i < 0 && j < 0) return true;
    if(j >= 0 && i < 0) return false;
    
    if(j < 0 && i >= 0) {
        for(int k=0; k<=i; k++) 
            if(p[k] != '*')
                return false;
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(p[i] == s[j] || p[i] == '?') 
        return dp[i][j] = solve(i-1, j-1, p, s, dp);
    
    
    if(p[i] == '*') 
        return dp[i][j] = solve(i-1, j, p, s, dp) || solve(i, j-1, p, s, dp);
    
    return dp[i][j] = 0;
}

bool isMatch(string p, string s) {
    int n = p.size();
    int m = s.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    return solve(n-1, m-1, p, s, dp);
} */

/* Method - 3 Tabulation - 2D Array - TC O(N*M) SC O(N*M)
bool isMatch(string p, string s) {
    int n = p.size();
    int m = s.size();

    vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));

    dp[0][0] = true; // 1st base case

    for(int j=1; j<=m; j++) // 2nd base case
        dp[0][j] = false;

    for(int i=1; i<=n; i++){ // 3rd base case
        bool flag = true;
        for(int k=1; k<=i; k++) {
            if(p[k-1] != '*') {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    
    // Indexing starting with 1
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(p[i-1] == s[j-1] || p[i-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if(p[i-1] == '*')
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
} */

// Method - 4 Tabulation 1D Array - TC O(N*M) SC O(N+M)

// Instead of 2d array we can use 1 D array
// because we just need i-1 and i row, means we need prev and row
bool isMatch(string p, string s) {
    int n = p.size();
    int m = s.size();

    // Prev - dp[i-1]
    // Curr - dp[i]
    vector<bool> prev(m+1, 0), curr(m+1, 0); 
        
    prev[0] = true; // 1st base case

    for(int j=1; j<=m; j++) // 2nd base case
        prev[j] = false;
        
    for(int i=1; i<=n; i++) { 
        // 3rd base case
        // Mark curr[0] - dp[i][0] as true if it contains all * else false
        bool flag = true;
        for(int k=1; k<=i; k++) {
            if(p[k-1] != '*') {
                flag = false;
                break;
            }
        }
        curr[0] = flag;

        for(int j=1; j<=m; j++) {                
            if(p[i-1] == s[j-1] || p[i-1] == '?')
                curr[j] = prev[j-1];
            else if(p[i-1] == '*')
                curr[j] = curr[j-1] || prev[j];
            else curr[j] = false;
        }
        // Update prev as curr
        prev = curr;
    }
    // return last ele prev as answer
    return prev[m];
}

int main() {
    string pattern = "ge?ks*";
    string text = "geeksforgeeks";

    if(isMatch(pattern, text)) 
        cout<<"Strings are matching\n";
    else cout<<"String are not matching\n";

    return 0;
}