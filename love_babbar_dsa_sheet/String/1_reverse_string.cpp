#include<bits/stdc++.h>
using namespace std;

//Two-Pointer TC O(N) SC O(1)
void reverseString(vector<char>& s) {
    int i=0, j=s.size()-1;
    while(i<j)
        swap(s[i++], s[j--]);
}

int main(){
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);

    for(auto i: s)
        cout<<i<<" ";
    return 0;
}