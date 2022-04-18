/* Minimum characters to be added at front to make string palindrome */
#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Brute Force TC O(N^2) SC O(1)
// Function to check palindrome
bool isPalindrome(string s) {
    int i=0, j = s.length()-1;
    while(i<=j) {
        if(s[i] != s[j])
            return false;
        i++; j--;
    }
    return true;
}

int count(string s) {
    int count = 0; // Store answer

    // Check if s is palindrom if not -> remove last char and increment count
    while(s.length() != 0 && !isPalindrome(s)) {
        count++;
        s = s.substr(0, s.length()-1);
    }

    // Return answer
    return count;
} */

// Method - 2 Longest Prefix Suffix - TC O(N) SC O(N)
int count(string s) {
    string reverseStr = s; 
    reverse(reverseStr.begin(), reverseStr.end()); // Reverse the string

    // Concat  ->  ABC + $ + CBA = ABC$CBA
    string concat = s + '$' + reverseStr;

    // Calculate longest prefix suffix
    int lps[concat.length()];
    lps[0] = 0;

    int i=1, len = 0;
    while(i<concat.length()) {
        if(concat[i] == concat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) 
                len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // return the ans 
    return s.length() - lps[concat.length()-1];
}

int main() {
	string s="BABABAA";
	cout << count(s);

	return 0;
}