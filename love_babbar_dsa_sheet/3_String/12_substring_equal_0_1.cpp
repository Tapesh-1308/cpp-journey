// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count substring with equal 0’s and 1’s
int maxSubStr(string str) {

    int n = str.length(); //length of string
	// To store the count of 0s and 1s
	int count0 = 0, count1 = 0;

	// To store the count of maximum substrings str can be divided into
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0')
			count0++;
		
		else 
			count1++;
		
		if (count0 == count1) 
			cnt++;
		
	}

	// It is not possible to split the string
	if (count0!=count1) {
		return -1;
	}

	return cnt;
}


int main() {
	string str = "0100110101";
	int n = str.length();

	cout << maxSubStr(str);

	return 0;
}
