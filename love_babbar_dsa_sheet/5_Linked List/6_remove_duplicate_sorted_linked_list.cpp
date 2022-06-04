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

// Approach - TC O(N) SC O(1)
Node* removeDuplicates(Node* head) {
    Node* temp = head; // Temperory Node to traverse

    if(!head) return NULL; // If head is null 

    // Traverse 
    while(temp->next) {
        // If they are duplicates
        if(temp->data == temp->next->data)
            temp->next = temp->next->next; // Skip next and point temp to next ka next
        else temp = temp->next; // else move temp in forward
    }
    return head; // return update list
}

int main() {

    Node *head = NULL;

    head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);

    printList(head);
    cout << endl;

    Node* output = removeDuplicates(head);

    printList(output);
    cout << endl;

    return 0;
}