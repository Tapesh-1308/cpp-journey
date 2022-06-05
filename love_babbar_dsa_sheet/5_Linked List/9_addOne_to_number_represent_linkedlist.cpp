#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
    Node(int a) {
        data = a;
        next = NULL;
    }
};


// A utility function to print a linked list
void printList(Node* head) {
	while (head != NULL) {
		cout << head->data;
		head = head->next;
	}
	cout << endl;
}

// Iterative Method TC O(N) SC O(1)
void reverseList(struct Node* &head) {
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
    head = prev;
}

// Iterative Approach TC O(N) SC O(1)
void addOne(Node* &head) {
    if(!head) return; // If not head then just return 

    // Reversing the list
    reverseList(head);

    // curr -> current element, prev -> previous element of curr
    Node* curr = head, *prev;
    int carry = 1; // carry store carry, initializing with 1 as we need to add one in every case

    // Add till carry and linkedlist remains 
    while(carry && curr) {
        // If we can add without carry problem
        if(curr->data < 9) {
            // Just add and make carry to 0 so that we can come out to loop
            curr->data += carry;
            carry=0;
        }
        // If this number also generates carry means it is 9
        else {
            // after adding 1 it become 0 = ( 9 + 1 = 10 - 1 is carry)
            curr->data = 0;
        }
        // move prev and curr
        prev = curr;
        curr = curr->next;
    }
    // in case carry remains but linkedlist end ex 9->9->9->9->* -> 1->0->0->0->0->*
    if(carry > 0) {
        prev->next = new Node(carry); // create new node and connect with last element
    }

    // reverse it again
    reverseList(head);
}

int main() {

    Node *head = NULL;

    head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(9);

    printList(head);
    cout << endl;

    addOne(head);

    printList(head);
    cout << endl;

    return 0;
}