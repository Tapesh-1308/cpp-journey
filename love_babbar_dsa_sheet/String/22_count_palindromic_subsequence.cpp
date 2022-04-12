/* Counts Palindromic Subsequence in a given String */
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

/* Method - 1 Brute Force TC -> O(2^N * N) SC O(N)
bool isPalindrome(string t) { //Check is string is palindrome or not
    if(t.length() == 0) return false;
    if(t.length() == 1) return true;
    
    int i=0, j=t.length()-1;
    
    while(i<j) {
        if(t[i] != t[j]) {
            return false;
        }
        i++; j--;
    }
    return true;
}

// Recursive func to get all subsequences
void solve(string t, int i, int n, string str, int &ans) {
    if(i==n) {
        if(isPalindrome(t)) { //if palindrom then only increment ans;
            ans = (ans+1) % mod;
        }
    }
    else {
        solve(t, i+1, n, str, ans); 
        t += str[i];
        solve(t, i+1, n, str, ans);
    }
}

int countPS(string str) {
    int ans = 0;
    solve("", 0, str.length(), str, ans);
    return ans;
} */

/* Method 2 - Using DP || TC -> O(N^2) || SC -> O(N^2) */
int countPS(string str) {
	int n = str.length();

	// create a 2D array to store the count of palindromic subsequence
	int dp[n][n];
    int i, j;

	// check subsequence of length L is palindrome or not
	for(long long int gap=0; gap<n; gap++) {
        i=0;
        j=gap;
        while(j<n) {
            if(gap == 0) dp[i][j] = 1; // 1 Length Palindromic string 

            /* if length is 2 then 2 case appear  same char 'aa' 
            or diff char 'ac' if same dp[i][j] = 3 else 2 */
            else if(gap == 1) 
                dp[i][j] = (str[i] == str[j]) ? 3 : 2;

            else 
                    dp[i][j] = (str[i] == str[j])
                    ? ((dp[i][j-1] + dp[i+1][j])%mod + 1ll) % mod
                    : ((dp[i][j-1] + dp[i+1][j])%mod - dp[i+1][j-1]+mod) % mod;

            i++; j++;
        }
    }
       

	// return total palindromic subsequence
	return dp[0][n - 1];
}

int main() {
	string str = "abcb";
	cout << "Total palindromic subsequence are : " << countPS(str) << endl;
	return 0;
}
