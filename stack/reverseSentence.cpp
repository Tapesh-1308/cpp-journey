// Reversing each word 
/* #include<iostream>
#include<stack>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i]!=' ' && i < s.length())
        {
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;   
}

int main() {
    string s = "Hey, how are you doing?"; 
    reverseSentence(s);
    return 0;
}
*/

// Reversing each char
/* #include<iostream>
#include<stack>
using namespace std;

void reverseSentence(string &s){
    stack<int> st;
    for (char i : s)
    {
        // string word = "";
        // while (i > s.length())
        // {
        //     word+=s[i];
        //     i++;
        // }
        // st.push(word);
        st.push(i);

    }
    for(int i = 0; i<s.length(); i++){
        s[i] = st.top();
        st.pop();
    }  
}

int main() {
    string s = "Hey, how are you doing?"; 
    reverseSentence(s);
    cout<<s;
    return 0;
} */