#include<bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Iterative Method TC O(N) SC O(1)
struct Node* reverseList(struct Node *head) {
    Node* curr = head; // Its pointer will change
    Node* prev = NULL; // curr pointer will points to prev
    Node* agla = NULL; // agla store rest of the lnked list-after remove curr pointer from it
    
    // While we did not change all pointers
    while(curr) {
        agla = curr->next; // everytime agla points to rest of the linked list
        curr -> next = prev; // reversing pointer
        prev = curr; // now prev becomes curr 
        curr = agla; // then curr becomes agla to changes its pointer also
    }
    // After loop curr points to null and prev points to last element
    return prev;
}

// Recursive Method TC O(N) SC O(N)
struct Node* solve(Node* curr, Node* prev){
    if(!curr) { // Base case - when curr reach NUll prev is pointing towards last element so return it
        return prev;
    }
    Node* agla = curr->next; // to secure rest of the linkedlist
    curr->next = prev; // Changing pointers
    solve(agla, curr); // curr becomes agla and prev becomes curr
}

struct Node* reverseList(struct Node *head) {
    // Recursive where curr = head and prev = NULL
    return solve(head, NULL);
}

// Print linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    printList(head);
    cout << endl;
    
    head = reverseList(head);
    
    printList(head);
    cout << endl;

    return 0;
}
