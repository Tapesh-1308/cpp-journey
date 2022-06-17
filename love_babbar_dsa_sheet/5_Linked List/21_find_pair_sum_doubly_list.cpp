#include <bits/stdc++.h>
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
// Approach - 1 Brute Force - TC O(N^2) SC O(1)
void pairSum(Node* head, int target) {
    // if list is empty
    if(!head) cout << "Empty List \n";

    // creating two pointer first and second
    Node* first = head;
    Node* second = first;

    // and a check 
    bool found = false;

    // traverse list by second for every first and check if first data and second data is equal to given target 
    while(first) {
        // second points to next of first
        second = first->next;
        while (second) {
            // if sum is eqaul to target
            if(first->data + second->data == target) {
                cout << "(" << first->data << ", " << second->data << ") ";
                found = true; // marke found as true
            }
            second = second->next; // move second
        }
        first = first->next; // move first
    }
    // if no pair found
    if(!found) cout << "No pair Found \n";
}

// Approach - 2 USing Two Pointer - TC O(N) SC O(1)
void pairSum(Node* head, int target) {
    // if list is empty
    if(!head) cout << "Empty List \n";

    // creating two pointer first and last
    Node* first = head, *last = head;
    // move last pointer to last node
    while(last->next)
        last = last->next;
    
    // create a check
    bool found = false;

    // run till both collide
    while(first->data < last->data) {
        // if sum is equal to target, print
        if(first->data + last->data == target) {
            cout << "(" << first->data << ", " << last->data << ") ";
            found = true;

            first = first->next; // move first forward
            last = last->prev; // and last backward
        }
        // if sum is smaller than target then we have to move first forward
        else if (first->data + last->data < target) {
            first = first->next;
        }
        // else move last backward
        else {
            last = last->prev;
        }
    }

    // if no pair found
    if (!found) cout << " No Pair Found \n";
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

    pairSum(head, 7);

    return 0;
}
