#include<bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Approach 1 - HashMap TC O(N) SC O(N)
bool detectLoop(Node *head) {
    // Map store key as Node and value as boolean, it tell whether we visited a not or not
    unordered_map<Node*, bool> visited;

    // Traverse on the linked list
    while(head) {
        // If already visited, means we return a node again
        if(visited[head]) return true;

        // Mark curr node as visited
        visited[head] = true;

        // moving head to next node
        head = head->next;
    } 

    // return false because head reaches null means no loop present
    return false;
}

// Approach 2 - Changing Links TC O(N) SC O(1)
bool detectLoop(Node *head) {
    // creating temporary node
    Node* temp = new Node(-1);

    // Traversing linked list
    while(head) {
        // If head is already pointing towards temp then return true
        if (head->next == temp) return true;

        // Create a next node which is on head->next
        Node* next = head->next;
        // change head -> next to temp
        head->next = temp;
        // then move head to next(head = head->next)
        head = next;
    }
    // no loop present
    return false;
}

// Approach 3 - Floyd's Cycle Finding Algorithm
bool detectLoop(Node *head) {
    // Creating two pointer slow and fast 
    Node *slow = head, *fast = head;

    // run till any one reaches null
    while(slow && fast && fast->next) {
        slow = slow->next; // Moving slow by one
        fast = fast->next->next; // and fast by two

        if(slow == fast) return true; // if both points on same node then return true
    }

    // no loop present
    return false;
}

// Print linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

int main() {
    int k = 3;
    Node *head = NULL;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = head->next->next;

    if(detectLoop(head)) cout << "Loop Detected\n";
    else cout << "Loop Not Found\n";

    return 0;
}