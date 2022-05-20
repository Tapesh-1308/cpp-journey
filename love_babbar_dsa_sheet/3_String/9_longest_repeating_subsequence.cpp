// Find the longest repeating subsequence
#include <iostream>
#include <string>
using namespace std;

//Using Dynamic Programming TC O(N^2) SC O(N^2)

// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.
int findLongestRepeatingSubSeq(string str) {
	int n = str.length();

	// Create and initialize DP table
	int dp[n+1][n+1];
	

	// Fill dp table (similar to LCS loops)
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
            if(i==0 || j==0) dp[i][j] = 0;
			// If characters match and indexes are not same
			else if (str[i-1] == str[j-1] && i != j)
				dp[i][j] = 1 + dp[i-1][j-1];		
					
			// If characters do not match
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[n][n];
}

int main() {
	string str = "aabb";
	cout << "The length of the largest subsequence that"
			" repeats itself is : "
		<< findLongestRepeatingSubSeq(str);
	return 0;
}
