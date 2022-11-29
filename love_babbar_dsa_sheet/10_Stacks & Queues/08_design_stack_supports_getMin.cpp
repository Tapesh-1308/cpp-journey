#include<bits/stdc++.h>
using namespace std;

// stack that supports getMinimum() in O(1) time and O(1) extra space
struct Stack {
    stack<int> s;
    int minEle;

    // function to push element in the stack
    void push(int x) {
        // if stack is empty, min element will be curr element
        if(s.empty()) {
            s.push(x); 
            minEle = x;
            return;
        }

        // if element to be pushed is greater than equal min element 
        if(x >= minEle) 
            // push directly
            s.push(x);
        
        // if element to be pushed is even less than minimum element
        else {
            s.push(2*x - minEle); // push 2*x - min element
            minEle = x; // update min element
        }
    }

    // function to pop element from the stack
    int pop() {
        // if stack is empty return
        if(s.empty()) 
            return -1;
        
        // store top and pop
        int t = s.top();
        s.pop();

        // if popped element is less than min
        if(t < minEle) {
            // update t so that we can return the correct top
            t = minEle;
            // update min -> (2*min - t) // retrieving back 
            minEle = 2*minEle - t;
        }
        
        // return deleted element
        return t;
    }

    // function to get the minimum element from the stack
    int getMin(){
        // if stack is empty return -1
        if(s.empty())
            return -1;

        // return the minEle
        return minEle;
    }

    // function to get the top of the stack
    int top(){
        // if stack is empty return
        if(s.empty())
            return -1;

        // if top greater equal than min, simply return top
        if(s.top() >= minEle)
            return s.top();

        // if smaller return the minEle (actual top element)
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