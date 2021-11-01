#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int topEle = st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topEle);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int element = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, element);
}

int main() {
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}