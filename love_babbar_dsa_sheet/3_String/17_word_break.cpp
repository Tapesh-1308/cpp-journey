#include <bits/stdc++.h>
using namespace std;

/*Method 1 Rcursion TC O(2^n) SC O(s) where s is dict size
// Returns true if string can be segmented into space separated words, otherwise returns false
bool wordBreak(string str, unordered_set<string> &mySet) {
	int size = str.size();

	// Base case
	if (size == 0) return true;

	// Try all prefixes of lengths from 1 to size
	for (int i=1; i<=size; i++) {
		// Temp is str.substr(0, i) which is prefix (of input string) of length 'i'. We first check whether
		// current prefix is in dictionary. Then we recursively check for remaining string
		// str.substr(i, size-i) which is suffix of length size-i
        string temp = str.substr(0, i);
		if (mySet.find(temp) != mySet.end() && wordBreak( str.substr(i, size-i), mySet))
			return true;
	}

	// If we have tried all prefixes and none of them worked
	return false;
} */

/*Method 2 DP TC O(N^3) SC O(N^2)
bool wordBreak(string s, unordered_set<string> mySet) {
    int n = s.size();
    
    bool dp[n+1][n+1];
    
    for(int length=1; length<=n; length++) {
        int start = 1;
        int end = length;
        
        while(end<=n) {
            string temp = s.substr(start-1, length);
            if(mySet.find(temp) != mySet.end())
                dp[start][end] = true;
            else {
                bool flag = false;
                
                for(int i = start; i<end; i++) {
                    if(dp[start][i] && dp[i+1][end]) {
                        flag = true;
                        break;
                    }
                }
                dp[start][end] = flag;
            }
            start++; end++;
        }
    }
    return dp[1][n];
} */

//Method 3 Optimised DP TC O(N*S) SC O(S) 
unordered_map<string, int> um;
int wordBreak(string s, unordered_set<string> mySet) {
    int n = s.size();
    if(n==0) return 1;
    if(um[s]!=0) return um[s];
    
        
    for(int i=1; i<=n; i++) {
        string temp = s.substr(0, i);
        bool flag = 0;
        if(mySet.find(temp) != mySet.end()) {
            flag = 1;
        }
        if(flag && wordBreak(s.substr(i, n-1), mySet)==1) return um[s] = 1;
    }
    return um[s] = 0;
    
}

int main() {
	vector<string> wordDict = {"mobile","samsung","sam","sung",
                                "man","mango","icecream","and",
                                "go","i","like","ice","cream"};
    unordered_set<string> mySet;
    for(auto str : wordDict) 
        mySet.insert(str);
    
	wordBreak("", mySet)? cout <<"Yes\n": cout << "No\n";
	wordBreak("ilikelikeimangoiii", mySet)? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmango", mySet)? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmangok", mySet)? cout <<"Yes\n": cout << "No\n";
	return 0;
}
