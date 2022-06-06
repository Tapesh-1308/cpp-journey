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

// Insert at Tail utility function
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data); // creating a node
    // if it was first node to be inserted
    if(!head) {
        head = temp;
        tail = temp;
        return;
    }
    // if not
    else {
        tail->next = temp;
        tail = temp;
    }
}

// Approach - TC O(N+M) SC O(min(N, M))
Node* getIntersection(Node* head1, Node* head2) {
    // To store new intersected linked list
    Node* intersection = NULL;
    Node* tail = NULL; // helps to intsert at tail

    // temp1, temp2 to traverse
    Node* temp1 = head1, *temp2 = head2;
    while(temp1 && temp2) {
        // if both data is equal
        if(temp1->data == temp2->data) {
            // then insert it into result
            insertAtTail(intersection, tail, temp1->data);
            // move temp1 and temp2 forward
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        // if temp1 data is smaller than temp2 data move temp1 forward
        else if(temp1->data < temp2->data) 
            temp1 = temp1->next;
        
        // else move temp2 forward
        else 
            temp2 = temp2->next;
        
    }
    // return the result
    return intersection;
}

int main() {

    Node *head1 = NULL;

    head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    Node *head2 = NULL;

    head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    cout << "List 1: ";
    printList(head1);
    cout << endl;

    cout << "List 2: ";
    printList(head2);
    cout << endl;

    Node* intersection = getIntersection(head1, head2);

    cout << "Intersection: ";
    printList(intersection);
    cout<<endl;

    return 0;
}