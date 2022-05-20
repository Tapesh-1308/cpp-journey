#include <bits/stdc++.h>
using namespace std;

// Approach - 1 TC O(N+M) SC O(M) 
// Where N = str.len and M = t.len

string findSmallestWindowCount(string str, string t) {
    unordered_map<char, int> um;
    
    // Push element of t in map
    for(int i=0; i<t.length(); i++) {
        um[t[i]]++;
    }
    
    int count = um.size();
    
    int ans = INT_MAX; // Max sub string length
    int ansi = 0, ansj = 0; // ansi store max ith pos and ans j stores max jth pos
    
    int i=0, j=0; // i-> start j -> end

    // Sliding Window Code
    while(i<=j && j<str.length()) {
        // Expand window
        if(count > 0) {
            if(um.find(str[j]) != um.end()) {
                um[str[j]]--;
                if(um[str[j]] == 0) 
                    count--;
            }
            j++;
        } 
        // Shrink window
        else if(count == 0) {
            //Calculate ans
            if(ans > j-i) {
                ans = j-i;
                ansi = i;
                ansj = j;
            }

            if(um.find(str[i]) != um.end()) {
                um[str[i]]++;
                if(um[str[i]] > 0)
                    count++;
            }
            i++;
        }
    }
    // Shrink more if possible, in case when j reach end and count = 0 means we may shrink
    while(count==0) {
        if(ans > j-i) {
            ans = j-i;
            ansi = i;
            ansj = j;
        }
        if(um.find(str[i]) != um.end()) {
            um[str[i]]++;
            if(um[str[i]] > 0)
                count++;
        }
        i++;
    }

    // Caluclate ans
    string ansStr = "";
    for(int i=ansi; i<ansj; i++) {
        ansStr.push_back(str[i]);
    }
    // If nothing found
    if(ansStr.empty()) return "-1";
    
    return ansStr;
}

int main() {
    string str = "geeksforgeeks";
    string t = "ork"; 
    cout << findSmallestWindowCount(str, t) << endl;
    return 0;
}