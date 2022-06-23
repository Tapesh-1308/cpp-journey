#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;
    Node(int a) {
        data = a;
        next = NULL;
        bottom = NULL;
    }
};

// A utility function to print a linked list
void printList(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Utility function to push node according to input
Node* push(Node* &head, int data) {
    Node* new_node = new Node(data);
 
    // Make bottom of new Node as head
    new_node->bottom = head;
 
    // Move the head to point to new Node
    head = new_node;
 
    return head;
}

// Custom comparator for min heap
struct compare {
    bool operator()(const Node* a, const Node* b) {
        return a->data > b->data;
    }
};

// Approach - 1 Using Merge function TC O(N*N*M) SC O(N*M)
Node* merge(Node* a, Node* b) {
    // Edge Cases
    if(!a) return b;
    if(!b) return a;
    
    // Create a dummy node
    Node* dummy = new Node(-1);
    Node* ptr1 = a; // to traverse on a
    Node* ptr2 = b; // to traverse on b
    Node* ptr3 = dummy; // to traverse on dummy
    
    
    while(ptr1 && ptr2) {
        // if ptr1->data is smaller, join ptr3->bottom with it and move ptr3 and ptr1
        if(ptr1->data < ptr2->data) {
            ptr3->bottom = ptr1;
            ptr3 = ptr1;
            ptr1 = ptr1->bottom;
        }
        // if ptr2->data is smaller, join ptr3->bottom with it and move ptr3 and ptr1
        else {
            ptr3->bottom = ptr2;
            ptr3 = ptr2;
            ptr2 = ptr2->bottom;
        }
    }
    
    // if ptr1 has some nodes remaining
    while(ptr1) {
        ptr3->bottom = ptr1;
        ptr3 = ptr1;
        ptr1 = ptr1->bottom;
    }
    
    // if ptr2 has some nodes remaining
    while(ptr2) {
        ptr3->bottom = ptr2;
        ptr3 = ptr2;
        ptr2 = ptr2->bottom;
    }

    // return by removing by dummy node
    return dummy->bottom;
}

Node* flatten(Node* head){
    // Base Case
    if(!head || !head->next)
        return head;
    
    // recursive call to flatten next list
    head->next = flatten(head->next);

    // merge curr list with next flattened list
    head = merge(head, head->next);

    // return flattened list
    return head;
}

// Approach - 2 Using Min Head TC O(N*M*log(N)) SC O(N)
Node* flatten(Node* head){
    // Edge Case
    if(!head || !head->next)
        return head;

    // create a min heap with custome comparator
    priority_queue<Node*, vector<Node*>, compare> pq;

    // push all nodes of main list
    Node* temp = head;
    while(temp) {
        pq.push(temp);
        temp = temp->next;
    }

    // create a dummy node and ptr to traverse on it
    Node* dummy = new Node(-1);
    Node* ptr = dummy;

    // traverse till pq
    while(!pq.empty()) {
        auto k = pq.top(); // store top node in k
        ptr->bottom = k; // attach with ptr
        ptr = k; // move ptr 
        
        pq.pop(); 

        // push bottom node if present
        if(k->bottom)
            pq.push(k->bottom);
    }

    // return output by remove dummy node
    return dummy->bottom;
}


int main() {
   /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
    */
    Node* head = NULL;

    push(head, 30);
    push(head, 8);
    push(head, 7);
    push(head, 5);
 
    push(head->next, 20);
    push(head->next, 10);
 
    push(head->next->next, 50);
    push(head->next->next, 22);
    push(head->next->next, 19);
 
    push(head->next->next->next, 45);
    push(head->next->next->next, 40);
    push(head->next->next->next, 35);
    push(head->next->next->next, 28);

    Node *flattened = flatten(head);

    cout << "Flattened List: ";
    printList(flattened);
    cout << endl;

    return 0;
}