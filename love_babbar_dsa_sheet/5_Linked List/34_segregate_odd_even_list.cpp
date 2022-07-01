// C++ program to segregate even and
// odd nodes in a Linked List
#include <bits/stdc++.h>
using namespace std;

/* a node of the singly linked list */
class Node
{
	public:
	int data;
	Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// TC O(N) SC O(1)
void segregateEvenOdd(Node* &head) {
    Node *end = head, *prev = NULL, *curr = head;
 
    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;
 
    Node *new_end = end;
 
    /* Consider all odd nodes before the first
    even node and move them after end */
    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 
    /* Do following steps only if there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to point to first even node */
        head = curr;
 
        /* now current points to the first even node */
        while (curr != end) {
            // if even data move prev and curr forward
            if ( (curr->data) % 2 == 0 ) {
                prev = curr;
                curr = curr->next;
            }
            // move node to last
            else {
                /* break the link between prev and current */
                prev->next = curr->next;
 
                /* Make next of curr as NULL */
                curr->next = NULL;
 
                /* Move curr to end */
                new_end->next = curr;
 
                /* make curr as new end of list */
                new_end = curr;
 
                /* Update current pointer to next of the moved node */
                curr = prev->next;
            }
        }
    }
 
    /* We must have prev set before executing lines following this statement */
    else prev = curr; 
 
    /* If there are more than 1 odd nodes and end of original list is odd then
    move this node to end to maintain same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0) {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
}
// TC O(N) SC O(1)
void segregateEvenOdd(Node* &head)
{
    // create two separate list for odd nodes and even nodes
    Node* oddList = new Node(-1), * evenList = new Node(-1);
    Node* odd = oddList, * even = evenList; // pointer to traverse

    Node* curr = head;

    while(curr) {
        // if even node then join it with evenlist
        if(curr->data % 2 == 0) {
            even->next = curr;
            even = curr;
        }
        // if odd data then join it with odd list
        else {
            odd->next = curr;
            odd = curr;
        }
        curr = curr->next;
    }
    // mark next of the last node of odd list as null
    odd->next = NULL;

    // join even with oddList(without dummy node)
    even->next = oddList->next;

    // update head to the nodenexttodummy in evenlist
    head = evenList->next;
}



/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node(new_data);

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data <<" ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Let us create a sample linked list as following
	0->2->4->6->8->10->11 */

	push(&head, 11);
	push(&head, 10);
	push(&head, 8);
	push(&head, 6);
	push(&head, 4);
	push(&head, 2);
	push(&head, 0);

	cout << "Original Linked list ";
	printList(head);

	segregateEvenOdd(head);

	cout << "\nModified Linked list ";
	printList(head);

	return 0;
}
