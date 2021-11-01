// Approach 1 with 2 stacks
/* #include<iostream>
#include<stack>
using namespace std;

class queue {
    stack<int> input;
    stack<int> output;

public:
    void push(int x){
        input.push(x);
    }
    int pop(){
        if(input.empty() and output.empty()){
            cout<<"No element to pop\n";
            return -1;
        }
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop(); 
            }
        }
        int topVal = output.top();
        output.pop();
        return topVal;
    }

    bool empty(){
        if(input.empty() and output.empty())
            return true;
        return false;
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.empty()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty();
    return 0;
} */

// Approach 2 with 1 stack and second is call stack
#include<iostream>
#include<stack>
using namespace std;

class queue {
    stack<int> input;

public:
    void push(int x){
        input.push(x);
    }
    int pop(){
        if(input.empty()){
            cout<<"No element to pop\n";
            return -1;
        }
        int x = input.top();
        input.pop();
        if(input.empty())
            return x;
            
        int item = pop();
        input.push(x);
        return item;
    }

    bool empty(){
        if(input.empty())
            return true;
        return false;
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.empty()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty();
    return 0;
}