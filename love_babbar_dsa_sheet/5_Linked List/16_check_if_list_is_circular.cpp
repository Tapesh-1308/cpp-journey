#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int a) {
        data = a;
        next = NULL;
    }
};

// A utility function to print a linked list
void printList(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* Utility Function to find length of linked list */
int getLen(Node* head) {
    int len = 0;
    Node* temp = head;
    while(temp) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Approach  TC O(N) SC O(1)
bool circular(Node* head) {
    // Considering empty list is consider
    if(!head) return true;

    // initializing temp on 2nd checking
    Node* temp = head->next;

    // traverse till temp reach null or become equal to head
    while(temp && temp != head)
        temp = temp->next;

    // if become equal to head means circular then returns true else false
    return temp==head;
}

int main() {
    Node *first = NULL;

    first = new Node(4);
    first->next = new Node(1);
    first->next->next = new Node(8);
    first->next->next->next = new Node(4);
    first->next->next->next->next = first;
    
    
    if(circular(first)) cout << "Circular list\n";
    else cout<<"Not a Circular list\n";

    return 0;
}