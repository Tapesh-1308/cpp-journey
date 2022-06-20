#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

/* Utility function to insert node in doubly linked list */
void insert(Node *&head, Node *&tail, int data) {
    if (!head) {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

/* Utility function to print list */
void printList(Node *head) {
    if (!head)
        return;

    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Approach - 1 Using Circular List - TC O(N) SC O(1)
Node* rotateDLL(Node* head, int k) {
    // create a last pointer and move it to last node
    Node* last = head;
    while(last->next) 
        last = last->next;
    
    // make list circular
    last->next = head;
    head->prev = last;
    
    // then move forward last and head k times
    while(k--) {
        last = last->next;
        head = head->next;
    }

    // make it uncircular at kth node
    last->next = NULL;
    head->prev = NULL;
    
    // return update list
    return head;
}

// Approach - 2 TC O(N) SC O(1)
Node* rotateDLL(Node* head, int k) {
    Node* toRotate = head; // kth node

    // move to rotate to kth position
    int count=1;
    while(count < k && toRotate) {
        toRotate = toRotate->next;
        count++;
    }

    // break the list after torotate
    Node* temp = toRotate->next;
    toRotate->next = NULL;
    temp->prev = NULL;
    
    // go to the last node
    Node* last = temp;
    while(last->next)
        last = last->next;
        
    // join last node with first node
    last->next = head;
    head->prev = last;
    
    // update head
    head = temp;

    return head;
}


int main() {
    Node *head = NULL;
    Node *tail = NULL;

    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    insert(head, tail, 4);
    insert(head, tail, 5);
    insert(head, tail, 6);

    printList(head);

    Node* newHead = rotateDLL(head, 2);

    printList(newHead);

    return 0;
}
