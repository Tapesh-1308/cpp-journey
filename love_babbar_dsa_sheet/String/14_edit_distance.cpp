#include <bits/stdc++.h>
using namespace std;

/*Method 1 Using Recursion TC O(min(3^m, 3^n) + mod(m-n)) SC O(n+m)
int solve(int i, int j, string s1, string s2) {
    if(i<0) return j+1;
    if(j<0) return i+1;
    
    if(s1[i] == s2[j]) return solve(i-1, j-1, s1, s2);
    return 1+min(solve(i-1, j, s1, s2), min(solve(i, j-1, s1, s2), solve(i-1, j-1, s1, s2)));
}
int editDistance(string word1, string word2) {
    int n = word2.length();
    int m = word1.length();
    
    return solve(m-1, n-1, word1, word2);
}*/

/* Method 2 Dynamic Programming (2d Array) TC O(M*N) SC O(M*N)
int editDistance(string word1, string word2) {
    int n = word2.length();
    int m = word1.length();
    
    int dp[n+1][m+1];
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0) dp[i][j] = j;
            else if (j==0) dp[i][j] = i;
            else if (word2[i-1] == word1[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+ min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
    return dp[n][m];
} */

//Method 3 Dynamic Programming (1d Array) TC O(m*n) SC O(m+n)
int editDistance(string word1, string word2) {
    int n = word2.length();
    int m = word1.length();
    
    vector<int> prev(m+1), cur(m+1);
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0) cur[j] = j;
            else if (j==0) cur[j] = i;
            else if (word2[i-1] == word1[j-1]) cur[j] = prev[j-1];
            else cur[j] = 1+ min(prev[j], min(cur[j-1], prev[j-1]));
        }
        prev = cur;
    }
    return cur[m];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int ans = editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}