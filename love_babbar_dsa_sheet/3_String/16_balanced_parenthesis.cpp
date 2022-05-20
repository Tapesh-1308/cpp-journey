#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string x)
{
    stack<int> st;
    
    for(int i=0; i<x.length(); i++) {
        if(x[i] == '('  || x[i] == '[' || x[i] == '{')
            st.push(x[i]);
            
        else if (x[i] == ')' && !st.empty() && st.top() == '(')
            st.pop();
            
        else if (x[i] == ']' && !st.empty() && st.top() == '[')
            st.pop();
            
        else if (x[i] == '}' && !st.empty() && st.top() == '{')
            st.pop();
        else return false;
    }
    if(st.empty()) return true;
    return false;
}

int main() {
    
    string a = "{[()]}";
    if(isBalanced(a))
    cout<<"balanced"<<endl;
    else
    cout<<"not balanced"<<endl;
    
    return 0;
}