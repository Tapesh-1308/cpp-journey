#include <bits/stdc++.h>
using namespace std;

// Approach - 1 TC O(N) SC O(N)

int findSmallestWindowCount(string str) {
    unordered_set<char> us; //To store distinct ele

    // Filling the unordered set
    for(int i=0; i<str.length(); i++) 
        us.insert(str[i]);
        
    //Size of set - Tell how many element we need 
    int n = us.size();

    //To keep track of how many ele we get so far
    int count = 0;

    int ans = INT_MAX;
    
    unordered_map<char, int> um; //Store freq
    um[str[0]]++; //Store first word
    count++;
    
    int i=0, j=1; // i is start of window and j is end
    while(i<=j && j<str.length()) {
        //If we need to add more elements then expand window
        if(count < n) {
            //If it is a new element
            if(um[str[j]] == 0) count++;
            um[str[j]]++;
            j++; 
        } 
        //If we get all distinct elements then try to shrink window
        else if (count == n) {
            ans = min(ans, j-i); //Update ans
            if(um[str[i]] == 1) count--; 
            um[str[i]]--;
            i++;
        }
    }
    
    //Run this loop to shrink further more if possible
    while(count==n) {
        ans = min(ans, j-i);
        if(um[str[i]] == 1) count--;
        um[str[i]]--;
        i++;
    }
    
    return ans;
}

int main() {
    string str;
    cout << findSmallestWindowCount(str) << endl;
    return 0;
}