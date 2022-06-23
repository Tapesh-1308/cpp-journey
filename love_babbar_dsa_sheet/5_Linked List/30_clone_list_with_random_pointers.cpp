#include <bits/stdc++.h>
using namespace std;

// Structure of linked list Node
struct Node {
    int data;
    Node* next, * random;
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};

// Utility function to print the list.
void print_list(Node* head) {
    Node* ptr = head;
    while (ptr) {
        cout << "Data = " << ptr->data << ", Random = "
            << ptr->random->data << endl;
        ptr = ptr->next;
    }
    cout << endl;
}

// Approach - 1 Using HashMap TC O(N) SC O(N)
Node* clone(Node* head) {
    // Create a hashmap {key = i/p list node : value = clone list corresponding node}
    unordered_map<Node*, Node*> um;
    Node* curr = head; // to trvaerse on head

    // create a dummy node newHead and ptr to traverse 
    Node* newHead = new Node(-1);
    Node* ptr = newHead;

    // Traverse
    while (curr) {
        // Create new node same as curr data and join it with ptr
        Node* node = new Node(curr->data);
        ptr->next = node;

        um[curr] = node; // also map curr with new node

        // move both forward
        ptr = ptr->next;
        curr = curr->next;
    }

    // remove dummy node from new clone list
    newHead = newHead->next;

    // reuse pointers
    curr = head;
    ptr = newHead;

    // Traverse again fro random pointers
    while (curr) {
        // if random is not pointing to null then the node to which it is pointing will available in out map
        if (curr->random)
            ptr->random = um[curr->random]; // um[curr->random] is node in clone list corresponding to curr->random node in i/p list 

        // move both forward
        curr = curr->next;
        ptr = ptr->next;
    }

    // return newList
    return newHead;
}

// Approach - 2 Without Space TC O(N) SC O(1)
Node* clone(Node *head) {
    // create two pointers for current node and next to current node
    Node* curr = head, *next = NULL;

    // Traverse and make update list such that 1->2->3 ==> 1->1->2->2->3->3
    while(curr) {
        next = curr->next; // adjusting next position

        // create new node same as curr as join between curr and next
        Node* node = new Node(curr->data);
        curr->next = node;
        node->next = next;

        curr = next; // move curr forward
    }
    
    curr = head; // reuse curr

    // Traverse again for random pointers
    while(curr) {
        // if random exists
        if(curr->random)
            curr->next->random = curr->random->next; // *important, this will points duplicate random pointer to its correct position
         
        curr = curr->next->next; // move curr forward by skipping duplicate nodes
    }
    
    curr = head; // reuse curr

    // Now, separate input list and duplicate nodes list

    // create a dummy node newhead and ptr to traverse on newHead
    Node* newHead = new Node(-1);
    Node* ptr = newHead;
    
    // Traverse
    while(curr) {
        // separating    
        // 1->1->2->2->3->3 to  curr = 1->2->3
        //                      newHead = -1 ->1->2->3
        ptr->next = curr->next; 
        curr->next = curr->next->next;

        // move both forward
        ptr = ptr->next;
        curr = curr->next;
    }
    
    // return by removing dummy node
    return newHead->next;
}

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // 1's random points to 3
    head->random = head->next->next;

    // 2's random points to 1
    head->next->random = head;

    // 3's and 4's random points to 5
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;

    // 5's random points to 2
    head->next->next->next->next->random = head->next;

    cout << "Original list : \n";
    print_list(head);

    cout << "Cloned list : \n";
    Node* cloned_list = clone(head);
    print_list(cloned_list);

    return 0;
}
