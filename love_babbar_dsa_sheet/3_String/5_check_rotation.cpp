#include<bits/stdc++.h>
using namespace std;

void checkRotation(string &s1, string &s2) {
    string temp = s1+s1;
    if(temp.find(s2) != string::npos) //check if string 2 is present in temp
        cout<<"YES";
    else cout<<"NO";
}

int main(){
    string s1 = "ABCD";
    string s2 = "CDAB";
    checkRotation(s1, s2);
    return 0;
}