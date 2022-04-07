#include<bits/stdc++.h>
using namespace std;

//Program to print all duplicates print all the duplicates and their counts in the input string 

//Hashmap - TC (N) SC O(N)
void printDuplicates(string &s) {
    if(s.length()==0) return;

    unordered_map<char, int> um;
    for(int i=0; i<s.length(); i++) 
        um[s[i]] ++;
    
    for(auto &i: um) {
        if(i.second>1)
            cout<<i.first<<" "<<i.second<<"\n";
        
    }
}

int main(){
    string s = "test string";
    printDuplicates(s);
    return 0;
}