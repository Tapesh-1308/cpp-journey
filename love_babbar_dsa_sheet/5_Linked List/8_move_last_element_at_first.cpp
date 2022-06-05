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

void move(Node* &head) {
    // if not head or only one node 
    if(!head || !head->next) return;
   
    Node* secLast = head; // to store seclast node
    while(secLast->next->next) // moving till seclast reach second last node
        secLast = secLast->next; // moving forward
    
    // temp - stores last node
    Node* temp = secLast->next;
    secLast->next = NULL; // second last will points to NULL
    temp->next = head; // temp will points to head
    head = temp; // update head
}

int main() {

    Node *head = NULL;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printList(head);
    cout << endl;

    move(head);

    printList(head);
    cout << endl;

    return 0;
}   