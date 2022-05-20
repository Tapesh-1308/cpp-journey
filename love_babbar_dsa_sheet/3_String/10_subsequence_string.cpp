#include<bits/stdc++.h>
using namespace std;


//Approach - Recursive TC O(2^N) SC O(1)
void func(string t, int i, int n, string s) {
    if(i==n) {
        cout<<t<<"\n";
        return;
    }
    func(t, i+1, n, s);
    t += s[i];
    func(t, i+1, n, s);
}

int main(){
    string s = "tape";
    string t = "";
    func(t, 0, s.length(), s);
    return 0;
}