#include <bits/stdc++.h>
using namespace std;

/**
 * Approach #1: Using Priority_Queue
 * TC: O(nlogn)
 * SC: O(26)
 * Solved @ 34 strings problem
*/

/**
 * Approach #2: Fill even pos, then odd pos
 * TC: O(N)
 * SC: O(26)
*/

char getMaxCountChar(vector<int>& count)
{
	int max = 0;
	char ch;
	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			ch = 'a' + i;
		}
	}

	return ch;
}

string rearrangeString(string S)
{
	int N = S.size();
	if (N == 0)
		return "";

	vector<int> count(26, 0);
	for (auto& ch : S)
		count[ch - 'a']++;

	char ch_max = getMaxCountChar(count);
	int maxCount = count[ch_max - 'a'];

	// check if the result is possible or not
	if (maxCount > (N + 1) / 2)
		return "";

	string res(N, ' ');
	int ind = 0;

	// filling the most frequently occurring char in the
	// even indices
	while (maxCount) {
		res[ind] = ch_max;
		ind = ind + 2;
		maxCount--;
	}

	count[ch_max - 'a'] = 0;

	// now filling the other Chars, first
	// filling the even positions and then
	// the odd positions
	for (int i = 0; i < 26; i++) {

		while (count[i] > 0) {

			ind = (ind >= N) ? 1 : ind;
			res[ind] = 'a' + i;
			ind += 2;
			count[i]--;
		}
	}

	return res;
}

// Driver's code
int main()
{
	string str = "bbbaa";

	// Function call
	string res = rearrangeString(str);
	if (res == "")
		cout << "Not possible" << endl;
	else
		cout << res << endl;

	return 0;
}
