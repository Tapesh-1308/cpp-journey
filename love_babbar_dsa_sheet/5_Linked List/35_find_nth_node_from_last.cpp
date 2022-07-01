#include<bits/stdc++.h>
using namespace std;
	
// Linked list node
struct Node {
	int data;
	Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
		
// Function to insert a node at the beginning of the Linked List
void push(struct Node** head_ref, int new_data)
{
	// allocate node
	struct Node* new_node = new Node(new_data);
	
	// link the old list off the new node
	new_node->next = (*head_ref);
	
	// move the head to point to the new node
	(*head_ref) = new_node;
}
	
// A utility function to print a linked list
void printList(struct Node *node) {
	while(node != NULL) {
		cout<<node->data <<"->";
		node = node->next;
	}
	cout<<"\n";
}

// Approach 1 - Using length - TC O(N) SC O(1)
int getNthFromLast(Node* head, int n) {
    int len = 0, i;
    Node* temp = head;
 
    // count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
 
    // check if value of n is not more than length of the linked list
    if (len < n)
        return -1;
 
    temp = head;

    // get the (len-n)th node from the beginning
    for (i = 0; i < len - n; i++)
        temp = temp->next;
 
    cout << temp->data;
 
    return;
}

// Approach 2 - Using length - TC O(N) SC O(1)
int getNthFromLast(Node* head, int n) {
    // create two pointers first and second
    // initially pointing to head.
    Node* first = head;
    Node* second = head;

    // if list is empty, return
    if (!head) {
        return -1;
    }

    // move second to the n-th node from beginning.
    for (int i = 1; i < n; i++) {
        second = second->next;
        if (second == NULL) {
            return -1;
        }
    }

    // move second and first by one node until
    // second reaches end of the list.
    while (second && second->next) {
        second = second->next;
        first = first->next;
    }
    return first->data;
}

int main() {
	struct Node* head = NULL;
	
	// create head list 12->15->10->11->5->6->2->3->x
	push(&head, 3);
	push(&head, 2);
	push(&head, 6);
	push(&head, 5);
	push(&head, 11);
	push(&head, 10);
	push(&head, 15);
	push(&head, 12);
	printf("List is: ");
	printList(head);
	
	cout<<"Nth node is: " << getNthFromLast(head, 3);
	
	return 0;
}