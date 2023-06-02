// C++ program to find min sum of squares
// of characters after k removals
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// Main Function to calculate min sum of
// squares of characters after k removals
int minStringValue(string str, int k)
{
	int l = str.length(); // find length of string

	// if K is greater than length of string
	// so reduced string will become 0
	if (k >= l)
		return 0;

	// Else find Frequency of each character and
	// store in an array
	int frequency[MAX_CHAR] = { 0 };
	for (int i = 0; i < l; i++)
		frequency[str[i] - 'a']++;

	// Push each char frequency into a priority_queue
	priority_queue<int> q;
	for (int i = 0; i < MAX_CHAR; i++)
		q.push(frequency[i]);

	// Removal of K characters
	while (k--) {
		// Get top element in priority_queue,
		// remove it. Decrement by 1 and again
		// push into priority_queue
		int temp = q.top();
		q.pop();
		temp = temp - 1;
		q.push(temp);
	}

	// After removal of K characters find sum
	// of squares of string Value
	int result = 0; // Initialize result
	while (!q.empty()) {
		int temp = q.top();
		result += temp * temp;
		q.pop();
	}

	return result;
}

// Driver Code
int main()
{
	string str = "abbccc"; // Input 1
	int k = 2;
	cout << minStringValue(str, k) << endl;

	str = "aaab"; // Input 2
	k = 2;
	cout << minStringValue(str, k);

	return 0;
}
