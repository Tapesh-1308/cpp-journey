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

// Approach - 1 Recusrion TC O(N) SC O(N/K) 

// Recursive Function
Node *solve(Node* head, int k) {
    // Changing links of nodes using curr prev and next
    Node *curr = head, *prev = NULL, *next=NULL;
    int count = 0; 
    
    // Chaing links and incrementing count to ensure we just change links less than k times
    while(curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // If next becomes null then we complete the reverse else we have to reverse next groups so call function from next and points it will head->next
    if(next)
        head->next = solve(next, k);
    
    // Prev will be our new head
    return prev;
}

struct Node *reverse (struct Node *head, int k) { 
    if(!head || k==1) return head; // If k is 1 then after reverse in k groups it remains same
    // Calling utility function
    return solve(head, k);
}

// Approach - 2 Iterative || TC O(N) -> N * N/K = N || SC O(1)
// Converted Leetcode#25 code 
struct Node *reverse (struct Node *head, int k) { 
    if(!head || k==1) return head; // If k is 1 then after reverse in k groups it remains same
    
    // Creating dummy node and pointint it to head
    Node* dummy = new Node(-1);
    dummy->next = head;
    
    // 3 Pointer -> curr, prev, next
    Node* prev=dummy, *curr=dummy, *next=dummy;

    // Calculating length of linked list and storing in count
    int count = 0;
    while(curr) {
        curr = curr->next;
        count++;
    }

    // Iterating till next is not NULL
    while(next) {
        // 3 pointers are pointing 
        // prev -> curr -> next
        curr = prev->next; 
        next = curr->next;

        // We have to run this below for loop k-1 times, but for last remaining elements we have to run this loop for remaining element count-1
        int toLoop = count > k ? k : count - 1; 
        for(int i=1; i<toLoop; i++){
            // These 4 steps will reverse a single group after running k-1 times
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr; // Prev after a group reversal points on curr then curr can be next of prev at starting of iteration
        count -= k; // Updating count so that we can calulate the condition for for-loop
    }
    // dummy->next will be our new head of linked list
    return dummy->next;
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
    int k = 3;
    Node *head = NULL;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    printList(head);
    cout << endl;
    
    head = reverse(head, k);
    
    printList(head);
    cout << endl;

    return 0;
}
