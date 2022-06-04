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

// Approach - 1 Brute Force - TC O(N^2) SC O(1)
Node* removeDuplicates(Node* head) {
    // p1 and p2 are two pointers
    // for every p1 -> p2 search for p1->data in rest of linkedlist
    
    Node* p1 = head;// creating p1 

    // Traversing linkedlist 
    while(p1) {
        Node* p2 = p1; // creating p2 and initalizing with p1
        // traversing linkedlist by p2 
        while(p2->next) { // Because Checking next always
            // if p2->next ka data is equal to p1->data then we have to skip it 
            if(p2->next->data == p1->data)
                p2->next = p2->next->next; // so directly point p2 to p2->next->next
            else p2 = p2->next; // if not same then simply move forward
        }
        // Moving p1
        p1 = p1->next;
    }
    // return the updated linkedlist
    return head;
}

// Approach - 2 HashSet - TC O(N) SC O(N)
Node* removeDuplicates(Node* head) {
    // Create two points curr and prev
    Node *curr = head, *prev = head;
    unordered_set<int> uset; // create a unordered set to store data

    // traverse linked list
    while(curr) {
        // if uset already contains curr data 
        if(uset.find(curr->data) != uset.end()){
            prev->next = curr->next; // then prev will point to curr next so that we can delete curr
            delete(curr); // remove duplicate
        }
        // If uset doesnot contains curr data
        else {
            // put curr data in uset
            uset.insert(curr->data);
            prev = curr; // and update prev, moving forward
        }
        // moving curr next to prev
        curr = prev->next;
    }

    // return the updated linkedlist
    return head;
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