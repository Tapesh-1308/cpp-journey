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
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// Approach - 1 Using Floyd's Cycle Finding Algorithm TC O(N) SC O(1)
Node* getStartingNode(Node* head) {
	// If list is empty or has only one node without loop
	if (head == NULL || head->next == NULL)
		return NULL;

	Node *slow = head, *fast = head;
	// Search for loop using slow and fast pointers
	while (slow && fast && fast->next) {
	    // Move slow and fast 1 and 2 steps ahead respectively.
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	// If loop does not exist
	if (slow != fast)
		return NULL;
	// If loop exists. Start slow from head and fast from meeting point.
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

void removeLoop(Node* head) {
    Node* startingNode = getStartingNode(head);
    if(!startingNode) 
        return;
    
    Node* temp = startingNode;
    while(temp->next != startingNode)
        temp = temp->next;
    temp->next = NULL;
}

int main() {
	Node* head = new Node(50);
	head->next = new Node(20);
	head->next->next = new Node(15);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	removeLoop(head);
    printList(head);

	return 0;
}
