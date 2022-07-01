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
	
//  TC = O(max(N, M)) SC O(1)
long long multiplyTwoLists (Node* first, Node* second)
{
	long long mod= 1e9+7; // output could be large take modulo 109+7.
	long long num1 = 0, num2 = 0;

    // Traverse
	while (first || second){

        // generate 1st number from linked list
        if(first) {
            num1 = ((num1)*10)% mod + first->data;
            first = first->next;
        }
        // generate 2nd number from linked list
        if(second) {
            num2 = ((num2)*10)% mod + second->data;
            second = second->next;
        }
    }

    // multiply num1 and num1 and return	
	return ((num1% mod)*(num2% mod))% mod;
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
	struct Node* second = NULL;
	
	// create first list 9->4->6
	push(&first, 6);
	push(&first, 4);
	push(&first, 9);
	printf("First List is: ");
	printList(first);
	
	// create second list 8->4
	push(&second, 4);
	push(&second, 8);
	printf("Second List is: ");
	printList(second);
	
	// Multiply the two lists and see result
	cout<<"Result is: ";
	cout<<multiplyTwoLists(first, second);
	
	return 0;
}

