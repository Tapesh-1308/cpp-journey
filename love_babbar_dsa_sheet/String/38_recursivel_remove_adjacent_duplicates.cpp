// Problem Link - https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1

#include<bits/stdc++.h>
using namespace std;

// Method - TC - O(N^2) - SC - O(1)
string remove(string s){
    bool last = 0, flag; // Last - to check if we get any adjacent or not, flag - check if we get any adjacent then we should add it to our ans

    int n = s.length(), l = 0, r; // start and end of substring
    string ans = "";
    
    for(int i=0; i<n;) {
        int j = i+1;  
        flag = 0;

        while(s[i] == s[j] && j<n) {
            j++;
            flag = 1;
            last = 1;
        }
        // If we get any duplicate chars
        if(flag) {
            l=j;
            i=j;
        }
        // else add it into ans
        else {
            r = i;
            ans += s.substr(l, r-l+1);
            l = j;
            i++;
        }
    }
    
    if(!last) return ans; // else Just return ans
    else return remove(ans); // If string had repeated char then check it again
}

int main(){
    string s = "abzxxab";
    cout << remove(s);
    return 0;
}