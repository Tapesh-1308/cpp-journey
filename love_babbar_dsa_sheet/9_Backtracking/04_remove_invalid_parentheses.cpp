// C++ program to remove invalid parenthesis
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^N) 
// Space Complexity: O(N) -> maximum depth possible

// function to find the minimum numbers of invalid parentheses
int getMinInValid(string s)
{
    /* 
    * Traverse the string, 
    * if ith char is (, push it into stack 
    * if it is ) then check 
        * if stack is empty or top element is also ) 
            * then push ith char also into the stack 
        * if top element is ( the pop this from the stack 
    * at the end stack is containing only invalid parentheses
    * so return stack size
    */
    stack<char> stck;
    int i = 0;
    while(i < s.size())
    {
        if(s[i] == '(')
            stck.push('(');
        else if(s[i] == ')')
        {
            if(stck.size() > 0 && stck.top() == '(')
                stck.pop();
            else
                stck.push(')');
        }
        i++;
    }
    return stck.size();
}

// recursive function
// takes -> ip string, min invalids, result vector, map
void solve(string s,int minInv, vector<string> &res, unordered_map<string,int> &mp){

    // if string is already present in map return
    if(mp[s] != 0) 
        return;
    else
        mp[s]++;  // else mark as visited in map
    
    // base case
    if(minInv == 0) // if mininv becomes 0, means we remove minInv parentheses
    {
        // check if string becomes balanced -> number of invalid parenthesis is 0
        if(!getMinInValid(s))
            // if yes then push the string into vector 
            res.push_back(s);
        return;
    }
    
    // traverse the whole string
    for(int i=0; i<s.size(); i++)
    {
        // remove char only if it is a bracket not any other char (reduces number of function calls)
        if(s[i] == '(' || s[i] == ')') {
            // remove ith char from string (0...i-1 + i+1...n-1)
            string left = s.substr(0,i);
            string right = s.substr(i+1);

            // recursivel call after remove ith parenthesis from string and decrease minInv
            solve(left+right, minInv-1, res, mp); 
        }
    }
}

// function to remove invalid parentheses
vector<string> removeInvalidParentheses(string s) 
{
    vector<string> res; // store all outputs

    // unordered map helps to remove duplicates and also decrease number of recursive calls that are repeating 
    unordered_map<string,int> mp; 

    // call recursive function
    solve(s, getMinInValid(s), res, mp);

    // return res
    return res;
}

int main(){
    string s = "()())()";

    vector<string> ans = removeInvalidParentheses(s);
    for(auto s: ans){
        cout << s << endl;
    }
    return 0;
}