// find maximum integer possible by doing at-most K swap operations on its digits.
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(Nk), For every recursive call N recursive calls are generated until the value of k is 0, Thus O((Nk).
// Auxiliary Space: O(N). The space required to store the output string.

// Function to find maximum integer possible by doing at-most K swap operations on its digits
void findMaximumNum(string str, int k, string& max, int idx) {
	// return if no swaps left
	if (k == 0)
		return;

	int n = str.length();

	// Consider every digit after the cur position
	char maxm = str[idx];
	for (int i=idx+1; i<n; i++) {
		// Find maximum digit greater than at idx among rest
		if (maxm < str[i])
			maxm = str[i];
	}

	// If maxm is not equal to str[idx], decrement k
	if (maxm != str[idx])
		k--;

	// search this maximum among the rest
	for (int i=idx; i<n; i++) {
		// If digit equals maxm, swap the digit with current digit and recurse for the rest
		if (str[i] == maxm) {
			// swap str[idx] with str[i]
			swap(str[idx], str[i]);

			// If current num is more than maximum so far
			if (str.compare(max) > 0)
				max = str;

			// recurse other swaps after cur
			findMaximumNum(str, k, max, idx + 1);

			// Backtrack
			swap(str[idx], str[i]);
		}
	}
}

int main() {
	string str = "129814999";
	int k = 4;

	string max = str;
	findMaximumNum(str, k, max, 0);

	cout << max << endl;

	return 0;
}
