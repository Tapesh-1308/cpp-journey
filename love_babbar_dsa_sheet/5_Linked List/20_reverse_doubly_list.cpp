#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

/* Utility function to insert node in doubly linked list */
void insert(Node* &head, Node* &tail, int data) {
    if(!head) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

/* Utility function to print list */
void printList(Node* head) {
    if(!head) return;

    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Utility function to reverse doubly linked list */
void reverse(Node* &head) {
    // create two pointer current and previous
    Node* curr = head;
    Node* prev = NULL;
    
    // traverse on the list
    while(curr) {
        // change links
        curr->prev = curr->next;
        curr->next = prev;
        // move forward
        prev = curr;
        curr = curr->prev;
    }
    // update head
    head = prev;
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

    reverse(head);

    printList(head);

    return 0;
}
