//Program to Check if a string is a valid shuffle of two distinct strings
#include<bits/stdc++.h>
using namespace std;

//Using 3 Pointers TC O(l3) SC O(1)
void checkShuffled(string &s1, string &s2, string &s3) {
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();
    
    if(l1+l2 != l3) {
        cout<<"NO";
        return;
    }
    
    int i=0, k=0, j=0;
    bool flag = false;
    while(k<l3) {
        if(i<l1 && s1[i]==s3[k]) {
            i++; k++;
        } else if (j<l2 && s2[j]==s3[k]) {
            j++; k++;
        }
        else {
            flag = 1;
            break;
        }
    }
    if(j<l2 || i<l1 || flag) cout<<"NO";
    else cout<<"Yes";
}

int main(){
    string s1 = "XY";
    string s2 = "12";
    string s3 = "Y21XX";
    checkShuffled(s1, s2, s3);
    return 0;
}