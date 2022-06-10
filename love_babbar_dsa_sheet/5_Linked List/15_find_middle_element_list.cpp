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

// A utility function to print a linked list
void printList(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* Utility Function to find length of linked list */
int getLen(Node* head) {
    int len = 0;
    Node* temp = head;
    while(temp) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Approach - 1 TC O(N) SC O(1)
Node* findMid(Node* head){
    // Corner Case
    if(!head || !head->next)
        return head;

    // find length
    int len = getLen(head);
    Node* temp = head;

    // trvaers till we reached half of length
    int midIdx = len/2;
    while(midIdx--) {
        temp = temp->next;
    }
    // temp will be storing middle element
    return temp;
}

// Approach - 2 TC O(N/2) SC O(1)
Node* findMid(Node* head){
    // Corner case
    if(!head || !head->next)
        return head;

    // Initialize two pointer slow and fast
    Node* slow = head;
    Node* fast = head;

    // traverse till fast or fast->next reach null
    while(fast && fast->next) {
        slow = slow->next; // move slow by 1
        fast = fast->next->next; // move fast by 2
    }
    // when fast reach null slow pointer will be on middle
    return slow;
}

int main() {
    Node *first = NULL;

    first = new Node(4);
    first->next = new Node(1);
    first->next->next = new Node(8);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(5);

    cout << "List ";
    printList(first);
    cout << endl;

    Node *middle = findMid(first);

    cout << "Sorted Array: " << middle->data << endl;

    return 0;
}