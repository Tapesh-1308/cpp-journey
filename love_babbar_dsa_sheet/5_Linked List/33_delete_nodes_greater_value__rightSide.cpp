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

// Utility function to reverse linked list
void reverse(Node* &headref)
{
    Node* current = headref, * prev = NULL,* next;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    headref = prev;
}

// Approach - 1 Brute Force TC O(N^2) SC O(1)
Node* deleteRightGreater(Node* head) {
    // if empty list or having one node
    if(!head || !head->next) return head;
    
    // first -> pointer for outer loop
    Node*first = head, *prev = first; // prev helps to delete node

    // second -> pointer for inner loop
    Node* second;
    
    // traverse
    while(first) {
        // for every first traverse list to end
        second = first->next;
        while(second) {
            // if first can be deleted break the loop
            if(second->data > first->data) {
                break;
            }
            second = second->next;
        }
        // if we break the previous loop
        if(second) {
            // if first is pointing to head then we have to manage the head pointer
            if(first == head) {
                head = first->next;
                continue;
            }
            
            // if it is not the head then delete first
            Node* toDelete = first;
            prev->next = first->next;
            first = first->next;
            delete toDelete;
        }
        // if we don;t have to delete node then we just move pointer forward
        else {
            prev = first;
            first = first->next;
        }
    }
    // return updated list
    return head;
}

// Approach - 2 Reverse List TC O(N) SC O(1)
Node* deleteRightGreater(Node* head) {
    if(!head || !head->next) return head;
    reverse(head); // reverse the given list

    // make current and previous pointer
    Node* curr = head, *prev = curr;
    int max = INT_MIN; // store maximum node till current

    // traverse
    while(curr) {  
        // if found a node that is less than max then we have to delete as there exist a node on right(left after reverse) with greater data  
        if(curr->data < max) { 
            // delete node           
            Node* toDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete toDelete;
        }
        // if curr data is greater than max then we don't delete it just update the max with curr node data and pointers
        else {
            max = curr->data;
            prev = curr;
            curr = curr->next;
        }
    }
    // revesex updated list and return 
    reverse(head);
    return head;
}

// Approach - 3 Recursively TC O(N) SC O(N)
Node* deleteRightGreater(Node* head) {
    // base case
    if(!head || !head->next) return head;

    // move to the last node (we do this to traverse right to left)
    Node* nextNode = deleteRightGreater(head->next);

    // if next node to current having data greater than current, then we have to delete this node so instead of returning curr node return nextNode
    if(nextNode->data > head->data) 
        return nextNode;
    
    // if nextnode of current having smaller data then it just point to nextNode (nextNode can be its next node or it can be the greater node )
    head->next = nextNode;

    // return current node
    return head;
}
	
// A utility function to print a linked list
void printList(struct Node *node) {
	while(node != NULL) {
		cout<<node->data <<"->";
		node = node->next;
	}
	cout<<"\n";
}
	
int main() {
	struct Node* first = NULL;
	
	// create first list 12->15->10->11->5->6->2->3->x
	push(&first, 3);
	push(&first, 2);
	push(&first, 6);
	push(&first, 5);
	push(&first, 11);
	push(&first, 10);
	push(&first, 15);
	push(&first, 12);
	printf("List is: ");
	printList(first);
	
	cout<<"Updated List is: ";
	printList(deleteRightGreater(first));
	
	return 0;
}