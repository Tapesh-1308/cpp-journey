// Leetcode problem - 3
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin>>s;
    vector<int> vec(256, -1);
    int n = s.size();
    int maxLen = 0, start = -1;
    for (int i = 0; i < n; i++)
    {
        cout<<vec[s[i]]<<" ";
        if(vec[s[i]]>start) start = vec[s[i]];
        vec[s[i]] = i;
        maxLen = max(maxLen, i-start);
    } cout<<maxLen;
    
    return 0;
}