// Design a stack with operations on middle element
#include<bits/stdc++.h>
using namespace std;

// doubly linked list node
struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int x){
        data = x;
        prev = next = NULL;
    }
};

// Time Complexity 
// push        -> O(1)
// pop         -> O(1)
// findMid()   -> O(1)
// deleteMid() -> O(1)

struct Stack{
    Node* head; // acts as top element
    Node* mid; // always points to middle of stack
    int size; // number of elements in stack

    Stack() {
        head = mid = NULL;
        size = 0;
    }


    // function to push element in stack
    void push(int x) {
        Node* temp = new Node(x);
        if(!head) {
            head = mid = temp; // for the first node set mid as head
            size++;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
        size++;

        // if stack size becomes even move mid one step back
        // 3->2->1->* (mid = 2), // 4->3->2->1->* (mid = 3)
        if(size%2 == 0) 
            mid = mid->prev;
    } 

    // function to pop element from the stack
    int pop() {
        if(!head) {
            cout << "Empty Stack" << endl;
            return -1;
        }

        Node* temp = head;
        int x = temp->data;

        head = head->next;

        if(head)
            head->prev = NULL;

        size--;

        // if stack size becomes odd move mid one step forward
        // 4->3->2->1->* (mid = 3), // 3->2->1->* (mid = 2)
        if(size%2 == 1)
            mid = mid->next;

        delete temp;
        return x; 
    }

    // function to print the middle element
    int findMid(){
        // if empty
        if(!head) {
            return -1;
        }

        // else print mid data
        return mid->data;
    }

    // function to print stack
    void printStack(){
        if(!head) {
            cout << "Empty Stack" << endl;
            return;
        }
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // function to delete middle element from the stack
    int deleteMid(){
        // if stack is empty
        if(!head) {
            cout << "Empty Stack" << endl;
            return -1;
        }

        // temp -> node to be deleted 
        Node* temp = mid;
        int x = temp->data;

        // if stack has only one element
        if(size == 1)  
            head = mid = NULL; // both head and new mid becomes null

        // if stack has two elements
        else if(size == 2) {
            // move head and mid forward
            head = head->next; 
            mid = mid->next;
            head->prev = NULL; // head prev is now null
        }

        // else condn
        else {
            // if size is even move mid to next
            // 4->3->2->1->* (mid = 3), // 4->2->1->* (mid = 2)
            if(size%2 == 0)
                mid = mid->next;
            // else move mid to prev
            // 3->2->1->* (mid = 2), // 3->1->* (mid = 3)
            else mid = mid->prev;

            // remove temp connections
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        // decrement size and delete temp
        size--;
        delete temp;

        return x; // return deleted data
    }
};

int main(){
    Stack s;

    cout << "Adding elements: " << endl;
    for(int i=1; i<=5; i++) {
        s.push(i);
        s.printStack();
        cout << "Middle Element: " << s.findMid() << endl;
    }

    cout << "Removing elements" << endl;

    for(int i=1; i<=5; i++) {
        // cout << "Element removed: " << s.pop() << endl;
        // cout << "Mid Deleted: " << s.deleteMid() << endl;
        s.printStack();
        cout << "Middle Element: " << s.findMid() << endl;
    }


    return 0;
}