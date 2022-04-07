#include <bits/stdc++.h>
using namespace std;

//Two-Pointer TC O(N) SC O(1)
int isPalindrome(string s) {
    int i=0, j=s.length()-1;
    while(i<j) {
        if(s[i]!=s[j])
            return 0;
        i++; j--;
    }
    return 1;
}

int main() {   
   	int t;
   	cin >> t;
   	while(t--) {
   		string s;
   		cin >> s;

   		cout << isPalindrome(s) << "\n";
   	}

    return 0;
}