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

// Approach - 1 Recursive - TC O(N) SC O(Auxillary STack Space: N)
Node* reverseDLLbyK(Node* head, int k) {
    if(!head || k==1) // if list is empty or k is 1 return head
        return head;

    // create three pointers curr next prev
    Node* curr = head, *next = NULL, *prev = NULL;
    int count = 0;
    
    // reverse a single group
    while(curr && count<k) {
        // reverse links
        next = curr->next;
        curr->next = prev;
        curr->prev = next;

        // update pointers
        prev = curr;
        curr = next;

        // increment count
        count++;
    }
    // recusrive call for remaining groups
    if(next) {
        head->next = reverseDLLbyK(next, k); // attach next link
        head->next->prev = head; // attaching prev link
    }
    
    return prev; // first node of reversed group
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

    Node* newHead = reverseDLLbyK(head, 2);

    printList(newHead);

    return 0;
}
