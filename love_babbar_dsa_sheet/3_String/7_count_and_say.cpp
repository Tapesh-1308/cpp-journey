#include<bits/stdc++.h>
using namespace std;


//1<=n<=30

//Method 1 TC O(n*LengthOfLongestString) SC O(LengthOfLongestString)
/* string countAndSay(int n) { 
    if(n==1) return "1";
    if(n==2) return "11";
    
    string s = "11";
    for(int i=3; i<=n; i++) {
        string t = "";
        int c = 1;
        for(int j=1; j<=s.length(); j++) {
            if(s[j] != s[j-1]) {
                t+=to_string(c);
                t+=s[j-1];
                c=1;
            }
            else c++;
        }
        s = t;
    }
    return s;
} */

//Method 2 TC O(n*LengthOfLongestString) SC O(LengthOfLongestString)
string generator(string s) {
    string ans = "";

    unordered_map<char, int> um;
    for(int i=0; i<=s.length(); i++) {
        if(um.find(s[i]) == um.end() && i>0) {
            auto it = um.find(s[i-1]);
            ans += to_string(it->second) + it->first;
            um.clear();
        } 
         um[s[i]] ++;
    
    }
    return ans;
}

string countAndSay(int n) {
    string res = "1";
    for(int i=1; i<n; i++) {
        res = generator(res);
    }
    return res;
}

int main(){
    int n = 5;
    cout<<countAndSay(n)<<endl;
    return 0;
}