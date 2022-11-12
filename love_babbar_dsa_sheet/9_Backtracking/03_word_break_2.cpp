// A recursive program to print all possible partitions of a given string into dictionary words
#include <bits/stdc++.h>
using namespace std;

// Complexities: 

// Time Complexity: O(2n). Because there are 2n combinations in The Worst Case.
// Auxiliary Space: O(n2). Because of the Recursive Stack of solve(…) function in The Worst Case.

// recursive function to find all partition recursively
// takes-> i/p string s,  created string till now, dictionary, string vector to store all partitions 
void solve(string s, string created, unordered_set<string> &dict, vector<string> &ans) {
    // base case -> if given string length becomes 0 means all word are stored in created string and we get an answer
    if(s.length() == 0){
        ans.push_back(created); // so store that ans in out ans vector and return
        return;
    }
    
    // traverse whole string 
    for(int i=0; i<s.length(); i++) {
        // generate all possible by separating (0 to ith char) word from string
        string left = s.substr(0, i+1);

        // if create word is present in the dictionary
        if(dict.find(left) != dict.end()) {

            // find the remaining part after removing that word
            string right = s.substr(i+1);

            // call for the remaining part 

            // created part will be -> created till now + generated word + space (adding space for next words)
            // only add space when string length is greater than 0, if s length is 0 means this the last word 
            // and no space required at the last
            solve(right, (s.length() == 0 ? created+left : created+left+' '), dict, ans);
        }
    }       
}

// word break generates all partitions possible
vector<string> wordBreak(string s, vector<string>& wordDict) {
    // store dictionary in unordered_set to access elements in O(1)
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    // create resultant vector    
    vector<string> ans;

    // call this recursive function 
    solve(s, "", dict, ans);
    
    // return the output
    return ans;
}

int main()
{

    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};

    vector<string> result = wordBreak(s, wordDict);
    for(auto str : result)
        cout << str << endl;
 
    return 0;
}