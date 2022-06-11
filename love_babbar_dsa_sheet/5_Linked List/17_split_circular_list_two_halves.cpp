#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int a) {
        data = a;
        next = NULL;
    }
};

// A utility function to print a circular linked list
void printList(Node *head) {
    if(!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);

    cout << endl;
}

// Time complexity = O(N) Space Complexity = O(1)
void splitCircular(Node* head, Node* &head1, Node* &head2) {
    if(!head) return; 

    // create two pointer slow and fast to find mid
    Node* slow = head, *fast = head->next;
    while(fast != head && fast->next != head) { // while fast or fast->next meet head 
        slow = slow->next; // move by one
        fast = fast->next->next; // move by two
    }
    
    head1 = head; // 1st half head points to head
    head2 = slow->next; // head2 will be 2nd half i.e. mid->next
    slow->next = head1; // making 1st half circular
    Node* last = head2; // finding last node to make 2nd half circular
    while(last->next != head)
        last = last->next;
    last->next = head2; // making 2nd half circular
}

int main() {
    Node *first = NULL;

    first = new Node(1);
    first->next = new Node(2);
    first->next->next = new Node(3);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(4);
    first->next->next->next->next->next = first;
    

    printList(first);

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitCircular(first, head1, head2);
    
    printList(head1);

    printList(head2);
    
    return 0;
}