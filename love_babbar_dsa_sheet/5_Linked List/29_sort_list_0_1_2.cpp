#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
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

void push(Node** head, int data) {
    Node* temp = new Node(data);
    temp->next = *head;
    *head = temp;
}

// Approach - 1 By Changing data TC O(N) SC O(1)
void sortList(Node* &head) {
    // Edge Case
    if(!head || !head->next)
        return;
        
    // Create three counter to store 0's Count 1's Count and 2's Count
    int zero = 0, one = 0, two = 0;

    Node* temp = head;
    while(temp) {
        // if data is zero increment 0 count
        if(temp->data == 0)
            zero++;
        // if 1 increment 1 count
        else if (temp->data == 1)
            one++;
        else 
            // if 2 increment 2 count
            two++;
        temp = temp->next;
    }
    temp = head;

    // 1) fill the list with 0, till zero > 0
    while(zero--) {
        temp->data = 0;
        temp = temp->next;
    }
    // 2) fill the list with 1, till one > 0
    while(one--) {
        temp->data = 1;
        temp = temp->next;
    }
    // 3) fill the list with 0, till two > 0
    while(two--) {
        temp->data = 2;
        temp = temp->next;
    }
}

// Approach - 2 By Changing links TC O(N) SC O(1)
void sortList(Node* &head) {
    // Edge Case
    if(!head || !head->next)
        return;

    // Create three dummy nodes to point to beginning of three linked lists. 
    Node* zero = new Node(-1), *one = new Node(-1), *two = new Node(-1);

    // Initialize pointers for three lists.
    Node* ptr0 = zero, * ptr1 = one, *ptr2 = two;

    // Traverse list
    Node* temp = head;
    while(temp) {
        // if data is 0 join with ptr0
        if(temp->data == 0) {
            ptr0->next = temp;
            ptr0 = temp;
        }
        // if data is join with ptr1
        else if (temp->data == 1) {
            ptr1->next = temp;
            ptr1 = temp;
        }
        // if data is two join with ptr2
        else {
            ptr2->next = temp;
            ptr2 = temp;
        }
        temp = temp->next;
    }
    
    // Attach three lists
    ptr0->next = (one->next) ? one->next : two->next;
    ptr1->next = two->next;
    ptr2->next = NULL;
    
    // Updated head
    head = zero->next;

    // Delete dummy nodes
    delete zero;
    delete one;
    delete two;
}

int main() {
   
    Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
 
    cout << "Linked List Before Sorting\n";
    printList(head);
 
    sortList(head);
 
    cout << "Linked List After Sorting\n";
    printList(head);

    return 0;
}