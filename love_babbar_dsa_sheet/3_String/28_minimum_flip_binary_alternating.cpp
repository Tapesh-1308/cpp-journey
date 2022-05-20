// Find minimum number of flip to make binary string alternate
#include <bits/stdc++.h>
using namespace std;

/* METHOD - 1 TC O(N) SC O(1)

// Utility method to get minimum flips when alternate string starts with expected char
int getFlipWithStartingCharcter(string str, char expected) {
	int flipCount = 0;
	for (int i = 0; i < str.length(); i++) {
		// if current character is not expected, increase flip count
		if (str[i] != expected)
			flipCount++;

		// flip expected character each time
		expected = ( expected == '0') ? '1' : '0';
	}
	return flipCount;
}

// method return minimum flip to make binary string alternate
int minFlipToMakeStringAlternate(string str) {
	// Return minimum of following two
	//    1) flips when alternate string starts with 0
	//    2) flips when alternate string starts with 1 
	return min(getFlipWithStartingCharcter(str, '0'),
			   getFlipWithStartingCharcter(str, '1'));
} */

// Method - 2 TC O(N) SC O(1)
int minFlipToMakeStringAlternate(string s) {
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++) {
 
        // If there is 1 at even index positions
        if (i % 2 == 0 && s[i] == '1')
            ans++;
 
        // If there is 0 at odd index positions
        if (i % 2 == 1 && s[i] == '0')
            ans++;
    }
    return min(ans, len - ans);
}

int main() {
	string str = "0001010111";
	cout << minFlipToMakeStringAlternate(str);
	return 0;
}
