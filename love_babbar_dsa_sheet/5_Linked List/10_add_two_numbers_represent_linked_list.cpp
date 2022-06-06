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


// Approach - Iterative - TC O(N+M) SC O(N+M) // Space used to store output (max length can be N+M)
Node* sumTwo(Node* head1, Node* head2) {
    
    // Reverse both lists
    reverseList(head1);
    reverseList(head2);

    // create head and tail for answer list
    Node* head = NULL;
    Node* tail = NULL;

    // temp1, temp2 to traverse
    Node* temp1 = head1, *temp2 = head2;
    int carry = 0; // stores carry
    
    // Traverse till both linked list ends and carry becomes 0
    while(temp1 || temp2 || carry) {
        // val1 and val2 are numbers to add 
        // val1 remains 0 if !temp1, val2 remains 0 if !temp2
        int val1=0, val2=0;
        if(temp1) val1 = temp1->data;
        if(temp2) val2 = temp2->data;

        // sum -> data to store in ans linked list
        int sum = val1 + val2 + carry;

        // insert at tail in answer linkedlist
        insertAtTail(head, tail, sum%10); 
        carry = sum / 10; // updating carry

        // moving temp1 and temp 2 if not null
        if(temp1)
            temp1 = temp1->next;
        if(temp2)
            temp2 = temp2->next;
    }

    // reversing ans
    reverseList(head);
    return head;
}

int main() {

    Node *head1 = NULL;

    head1 = new Node(7);
    head1->next = new Node(5);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    Node *head2 = NULL;

    head2 = new Node(8);
    head2->next = new Node(4);

    cout << "Number 1: ";
    printList(head1);
    cout << endl;

    cout << "Number 2: ";
    printList(head2);
    cout << endl;

    Node* sum = sumTwo(head1, head2);

    cout << "Sum: ";
    printList(sum);
    cout<<endl;

    return 0;
}
