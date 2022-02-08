// Hackerearth Ques - The Three Musketeers
#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
    return ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u';
}

vector<string> subsets(string s){
    int sz = (1<<s.size());
    vector<string> ans;
    for(int i=0; i<sz; i++){
        string subset;
        for(int j=0; j<s.size(); j++)
            if(i & (1<<j)) subset.push_back(s[j]);
        if(subset.size()) ans.push_back(subset);
    }
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string str[n];
        for(int i=0; i<n; i++)
            cin>>str[i];
        unordered_map<string, int> hsh;
        for(int i=0; i<n; i++){
            set<char> distinctVW;
            for(char ch:str[i])
                if(isVowel(ch))
                    distinctVW.insert(ch);

            string vowelStr;
            for(char ch:distinctVW)
                vowelStr.push_back(ch);
            vector<string> allSubsets = subsets(vowelStr);
            for(string vowelSubset:allSubsets)
                hsh[vowelSubset]++;
        }
        long long ans = 0;
        for(auto &pr:hsh){
            if(pr.second<3) continue;
            long long ct = pr.second;
            long long ways = ct*(ct-1)*(ct-2) / 6;
            if(pr.first.size() % 2==0) ans -= ways;
            else ans += ways;
        }
        cout<<ans<<endl;
    }   
    return 0;
}