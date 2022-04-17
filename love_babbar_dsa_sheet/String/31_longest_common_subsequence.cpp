/* Find longest common subsequence of 2 strings */
#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Recursion TC O(2^N) SC O(mn)
int lcs( string s1, string s2, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (s1[m-1] == s2[n-1])
        return 1 + lcs(s1, s2, m-1, n-1);
    else
        return max(lcs(s2, s2, m, n-1), lcs(s1, s2, m-1, n));
} */

/* Method - 2 Memoization TC O(MN) SC O(MN)
int lcs( string s1, string s2, int m, int n, vector<vector<int> >& dp) {
    if (m == 0 || n == 0)
        return 0;

    if(dp[m][n] != -1) return dp[m][n];

    if (s1[m-1] == s2[n-1])
        return dp[m][n] = 1 + lcs(s1, s2, m-1, n-1, dp);
    else
        return dp[m][n] = max(lcs(s2, s2, m, n-1, dp), lcs(s1, s2, m-1, n, dp));
} */

// Method - 3 Tabulation TC O(MN) SC O(MN)
int lcs( string s1, string s2) {
    int m = s1.length(), n = s2.length();

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int m = s1.length();
    int n = s2.length();

    //Recusrion
    // cout << "Length of LCS is " << lcs( s1, s2, m, n);

    //Memoization
    // vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
    // cout << "Length of LCS is " << lcs( s1, s2, m, n, dp);

    //Tabulation
    cout << "Length of LCS is " << lcs(s1, s2);

    return 0;
}
