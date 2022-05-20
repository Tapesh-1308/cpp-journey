// A C++ solution for longest palindrome
#include <bits/stdc++.h>
using namespace std;

// Function to print a substring str[low..high]
void printSubStr(string str, int low, int high) {
	for (int i = low; i <= high; ++i)
		cout << str[i];
}

/* Method 1 Brute Force TC O(N^3) SC O(1)
// This function prints the longest palindrome substring It also returns the length
// of the longest palindrome
int longestPalSubstr(string str) {
	// get length of input string
	int n = str.size();

	// All substrings of length 1 are palindromes
	int maxLength = 1, start = 0;

	// Nested loop to mark start and end index
	for (int i = 0; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			int flag = 1;

			// Check palindrome
			for (int k = 0; k < (j - i + 1) / 2; k++)
				if (str[i + k] != str[j - k])
					flag = 0;

			// Palindrome
			if (flag && (j - i + 1) > maxLength) {
				start = i;
				maxLength = j - i + 1;
			}
		}
	}

	cout << "Longest palindrome substring is: ";
	printSubStr(str, start, start + maxLength - 1);

	// return length of LPS
	return maxLength;
} */

/* Method 2 Dynamic Programming TC O(N^2) SC O(N^2)
int longestPalSubstr(string str) {
	// get length of input string
	int n = str.size();

	// table[i][j] will be false if substring str[i..j] is not palindrome.
	// Else table[i][j] will be true
	bool table[n][n];

	memset(table, 0, sizeof(table));

	// All substrings of length 1 are palindromes
	int maxLength = 1;
	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	// check for sub-string of length 2.
	int start = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	// Check for lengths greater than 2. k is length of substring
	for (int k = 3; k <= n; ++k) {
		// Fix the starting index
		for (int i = 0; i < n - k + 1; ++i) {
			// Get the ending index of substring from starting index i and length k
			int j = i + k - 1;

			// checking for sub-string from ith index to jth index if str[i+1] to str[j-1] is a
			// palindrome
			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;

				if (k > maxLength) {
					start = i;
					maxLength = k;
				}
			}
		}
	}

	cout << "Longest palindrome substring is: ";
	printSubStr(str, start, start + maxLength - 1);

	// return length of LPS
	return maxLength;
} */

// Method 3 TC O(N^2) SC O(1) 
int longestPalSubstr(string s) {
    int n = s.length(); //Size of string
        
    int start = 0, end = 1; //Satrting position of palindrom, and end store max Length of palindrome

    int low, hi;
    for(int i=0; i<n; i++) {
        //Even part
        low = i-1;
        hi = i;
        while(low>=0 && hi < n && s[low]==s[hi]) {
            if(hi-low+1 > end) {
                start = low;
                end = hi-low+1;
            }
            low--; hi++;
        }            
        
        //Odd Part
        low = i-1;
        hi = i+1;
        
        while(low>=0 && hi < n && s[low]==s[hi]) {
            if(hi-low+1 > end) {
                start = low;
                end = hi-low+1;
            }
            low--; hi++;
        }   
    }
    
    printSubStr(s, start, start+end-1);
    return end;
}

int main()
{
	string str = "forgeeksskeegfor";
	cout << "\nLength is: "
		<< longestPalSubstr(str);
	return 0;
}
