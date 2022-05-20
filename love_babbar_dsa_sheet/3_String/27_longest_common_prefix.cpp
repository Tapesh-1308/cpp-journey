#include<bits/stdc++.h>
using namespace std;

string lcp(vector<string> &str) {
    int minLength = str[0].length();

    for(auto i : str )
        minLength = min(minLength, (int)i.length());
    
    string ans = "";
    char ch;
    for(int i=0; i<minLength; i++) {
        ch = str[0][i];
        for(int j=0; j<str.size(); j++) {
            if(ch != str[j][i])
                return ans;
        }
        ans.push_back(ch);
    }
    return ans;
}

int main(){
    vector<string> str = {"flower", "flight", "flow"};
    string ans = lcp(str);

    if(ans.empty()) cout << "-1";
    else cout << ans; 

    return 0;
}