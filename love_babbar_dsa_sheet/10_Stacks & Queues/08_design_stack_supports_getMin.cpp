#include<bits/stdc++.h>
using namespace std;

struct Stack {
    stack<int> s;
    int minEle;

    void push(int x) {
        if(s.empty()) {
            s.push(x);
            minEle = x;
            return;
        }

        if(x >= minEle) {
            s.push(x);
        }
        else {
            s.push(2*x - minEle);
            minEle = x;
        }
    }

    int pop() {
        if(s.empty()) {
            return -1;
        }

        int t = s.top();
        s.pop();

        if(t <= minEle)
            minEle = 2*minEle - t;
        
        return t;
    }

    int getMin(){
        if(s.empty())
            return -1;

        return minEle;
    }

    int top(){
        if(s.empty())
            return -1;

        if(s.top() >= minEle)
            return s.top();

        else return minEle;
    }
};

int main(){
    Stack s;

    s.push(5); // [5]
    cout << s.getMin() << endl; // min -> 5

    s.push(3); // [5,3]
    cout << s.getMin() << endl; // min -> 3

    s.push(2); // [5,3,2]
    cout << s.getMin() << endl; // min -> 2

    s.push(15); // [5,3,2,15]
    cout << s.getMin() << endl; // min-> 2

    s.pop(); // [5,3,2]
    cout << s.getMin() << endl; // min -> 2

    s.pop(); // [5,3]
    cout << s.getMin() << endl; // min -> 3

    s.pop(); // [5]
    cout << s.getMin() << endl; // min ->5

    s.pop(); // []
    cout << s.getMin() << endl; // min -> -1

    
    return 0;
}