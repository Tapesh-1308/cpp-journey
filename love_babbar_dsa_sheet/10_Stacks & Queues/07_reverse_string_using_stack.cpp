#include <bits/stdc++.h>
using namespace std;
 
// TC O(N)
// SC O(N)

// Reverse a string using a stack container in C++.
// Note that the string is passed by reference
void reverse(string &str)
{
    // create an empty stack
    stack<char> s;
 
    // Push each character in the string to the stack
    for (char ch: str) {
        s.push(ch);
    }
 
    // pop all characters from the stack and
    // put them back to the input string
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = s.top();
        s.pop();
    }
}
 
int main()
{
    string str = "Reverse me";
 
    reverse(str);
    cout << str;
 
    return 0;
}