// Implementation of Stack using Array and Linkedlist
#include <iostream>
using namespace std;

/*
Operations  	Complexity
push()            O(1)
pop()   	      O(1)
isEmpty() 	      O(1)
size()	          O(1)
*/

// Using Array
class Stack {
    int size; // size of stack
    int *arr; // array
    int top; // peek element 

public:
    // constructor
    Stack() {
        top = -1; // denoting empty
        size = 1000; // basic size
        arr = new int[size]; // dynamic array memory allocation
    }

    // function to insert element in the stack
    void push(int x) {
        top++; // increment top
        arr[top] = x; // add element to array
    }

    // function to remove top element from the stack
    int pop() {
        if(top == -1)  // if stack is empty
            return -1;

        int x = arr[top]; // access top element
        top--; // decrement top
        return x; // return deleted element
    }

    // function to get the top element of the stack
    int Top() {
        return arr[top]; 
    }

    // function to get the size of stack
    int Size() {
        return top + 1; // last index + 1
    }
    
    // function to check whether stack is empty or not
    bool empty(){
        return top == -1;
    }
};

// using linked list

// linked list node structure
struct stackNode {
    int data;
    stackNode *next;
    int size;
    stackNode(int d)
    {
        data = d;
        next = NULL;
    }
};

// linked list base stack structure 
struct stack {
    stackNode *top; // top node -> tells peek element
    int size; // tells the size of stack

    // constructor
    stack() {
        top = NULL;
        size = 0;
    }

    // function to insert element in the stack
    void push(int x) {
        stackNode *element = new stackNode(x); // node to be inserted
        element->next = top; // add element on begining of linked list
        top = element; // update top

        size++; // increment size
    }

    // function to pop element from stack
    int pop() {
        // if stack is empty
        if (top == NULL) {
            return -1;
        }

        // access data to be deleted
        int topData = top->data;
        stackNode *temp = top; // store top temp node 
        top = top->next; // top now points to next node
        
        delete temp; // delete temp node
        size--; // decrement size
        
        return topData; // return deleted node data
    }

    // function to get the size of the stack
    int Size() {
        return size;
    }

    // function to check whether stack is empty or not
    bool empty() {
        return top == NULL;
    }

    // function to return the top node
    int Top() {
        // check if stack is empty
        if (top == NULL)
            return -1;

        // return top node data
        return top->data;
    }
};

int main()
{

    // using array
    Stack s1;
    s1.push(6);
    s1.push(3);
    s1.push(7);
    cout << s1.Top() << endl;
    cout << s1.Size() << endl;
    cout <<  s1.pop() << endl;
    cout << s1.empty() << endl;

    // using linked list
    stack s2;
    s2.push(6);
    s2.push(3);
    s2.push(7);
    cout << s2.Top() << endl;
    cout << s2.Size() << endl;
    cout <<  s2.pop() << endl;
    cout << s2.empty() << endl;


    return 0;
}