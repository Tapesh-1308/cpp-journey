#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// custom comparator for priority queue
struct compare{
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

/* Utility function to insert node in doubly linked list */
void insert(Node *&head, Node *&tail, int data) {
    if (!head) {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

/* Utility function to print list */
void printList(Node *head) {
    if (!head)
        return;

    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Approach - 1 Brute Force TC O(N*k) SC O(1)
Node *sortedDll(Node *head, int k)
{

    // create two pointer curr (current node), kptr (always k dist far from curr)
    Node* curr = head;
    Node* kptr = head;
    
    int count = 0; // to put kptr to its location
    
    while(curr) {
        // making k diffrence between curr and kptr
        count = 0;
        kptr = curr;
        while(kptr->next && count < k) { 
            kptr = kptr->next;
            count++;
        }

        // moving kptr towards current and checking if curr data is larger than kptr or not
        while(kptr != curr) {
            if(curr->data > kptr->data) { // if greater swap data or node
                // swap by modifing data
                // swap(curr->data, kptr->data);
                
                // Swap with links     

                // Swapping next links         
                Node* temp;
                temp = curr->next;
                curr->next = kptr->next;
                kptr->next = temp;
                
                // swapping links (next) of adjacent nodes
                if (curr->next != NULL)
                    curr->next->prev = curr;
                if (kptr->next != NULL)
                    kptr->next->prev = kptr;
                
                // Swapping prev links
                temp = curr->prev;
                curr->prev = kptr->prev;
                kptr->prev = temp;

                // Swapping links (prev) of adj nodes 
                if (curr->prev != NULL)
                    curr->prev->next = curr;
                if (kptr->prev != NULL)
                    kptr->prev->next = kptr;
                    
                // swaping pointer(names)
                Node* tempp = curr;
                curr = kptr;
                kptr = tempp;
                
                // if curr was the first node then head's pos also changed so relocate head  
                if(!curr->prev) head = curr;
                
            }
            
            kptr = kptr->prev; // move kptr backward
        }
        curr = curr->next; // move curr forward
    }

    return head; // return the head of sorted dll
}


// Approach - 2 Using min heap TC O(n*logk) SC O(k)
Node* sortKSorted(Node* head, int k) {
    // newHead and tail are head and tail of output DLL, curr for current node and kptr lies k dist from curr
    Node* newHead = NULL, *tail = NULL, *kptr = head;

    int count = 0; 
    
    // create a min heap
    priority_queue<Node*, vector<Node*>, compare> pq;
    
    // store first k nodes in pq
    while(count<=k && kptr) {
        pq.push(kptr);
        kptr = kptr->next;
    }
    

    while( !pq.empty() ) {
        // if first node of output, both head and tail on same node and head-> prev will be null
        if(!newHead) {
            newHead = pq.top(); 
            newHead->prev = NULL;
            tail = newHead;
            
        }
        // if not first node
        else {
            tail->next = pq.top(); // put it on last position
            pq.top()->prev = tail;
            tail = pq.top(); // update tail
            
        }
        // remove node that is added
        pq.pop();
        
        // add another node and move kptr also
        if(kptr) {
            pq.push(kptr);
            kptr = kptr->next;
        }
        
    }

    // last node's next will be null
    tail->next = NULL;
    return newHead; // return ouput head
}


int main() {
    Node *head = NULL;
    Node *tail = NULL;

    insert(head, tail, 10);
    insert(head, tail, 9);
    insert(head, tail, 8);
    insert(head, tail, 7);
    insert(head, tail, 4);
    insert(head, tail, 70);
    insert(head, tail, 60);
    insert(head, tail, 50);

    printList(head);

    sortKSorted(head, 4);

    printList(head);

    return 0;
}
