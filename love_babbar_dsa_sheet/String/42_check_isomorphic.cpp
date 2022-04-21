#include<bits/stdc++.h>
using namespace std;

// Method - TC O(N) SC O(1)
bool isIsomorphic(string s1, string s2) {
    int n = s1.length(), m = s2.length();

    // If size is not equal it can't be isomorphic
    if(n != m) return false;

    int m1[26] = {0}; // To map s1 -> s2
    int m2[26] = {0}; // To map s2 -> s1

    for(int i=0; i<n; i++) {
        // If both are elements are not visited
        if(!m1[s1[i] - 'a'] && !m2[s2[i] - 'a']) {
            m1[s1[i] - 'a'] = s2[i]; // Map s1 -> s2 in m1
            m2[s2[i] - 'a'] = s1[i]; // Map s2 -> s1 in m2
        }
        // If it is visited but curr element is not equal to mapping
        else if(m1[s1[i] - 'a'] != s2[i]) return false;
    }

    // If abouve loop runs completely return true
    return true;
}

int main(){
    string s1 = "aab";
    string s2 = "xxy";

    if(isIsomorphic(s1, s2))
        cout<<"Yes\n";
    else 
        cout<<"NO\n";

    return 0;
}