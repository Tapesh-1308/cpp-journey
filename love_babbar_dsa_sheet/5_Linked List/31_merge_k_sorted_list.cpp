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

// 'compare' function used to build  up the priority queue
struct compare {
    bool operator()(struct Node* a, struct Node* b) {
        return a->data > b->data;
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

// A utility function to merge two sorted linked list
Node* mergeTwoSortedList(Node* l1, Node* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    Node* dummy = new Node(-1), *curr = dummy;
    
    Node* ptr1 = l1, *ptr2 = l2;
    
    while(ptr1 && ptr2) {
        if(ptr1->data < ptr2->data) {
            curr->next = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            curr->next = ptr2;
            ptr2 = ptr2->next;
        }
        curr = curr->next;
    }
    
    curr->next = ptr1 ? ptr1 : ptr2;
    
    return dummy->next;
}

// Approach - 1 Brute Force TC O(NK^2) SC O(1)
Node* mergeKSortedLists(Node* arr[], int k) {
    Node* newList = arr[0]; // Create a new list to store result

    // Traverse for every list
    for(int i=1; i<k; i++) {
        // merge curr list with previously merged list (newlist) and update new List
        newList = mergeTwoSortedList(newList, arr[i]);
    }
    return newList;
}

// Approach - 2 Min-Heap TC O(NK logK ) SC O(k)
Node* mergeKSortedLists(Node* arr[], int k) {
    // Priority_queue 'pq' implemented as min heap with the help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;
  
    // Push the head nodes of all the k lists in 'pq'
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);
      
    // Handles the case when k = 0 or lists have no elements in them    
    if (pq.empty())
        return NULL;

    Node *dummy = new Node(0);
    Node *last = dummy;
    
    // Loop till 'pq' is not empty
    while (!pq.empty())  
    {
        // Get the top element of 'pq'
        Node* curr = pq.top();
        pq.pop();
  
        // Add the top element of 'pq' to the resultant merged list
        last->next = curr;
        last = last->next;  
        
        // Check if there is a node next to the 'top' node in the list of which 'top' node is a member
        if (curr->next != NULL)
            // Push the next node of top node in 'pq'
            pq.push(curr->next);
    }
  
    // Address of head node of the required merged list
    return dummy->next;
}

// Approach - 3 Divide and Conquer TC O(NK logK ) SC O(1)
Node* mergeKlistsUTIL(Node* arr[], int st, int en) {
    // Base Case 
    if(st > en) return NULL; // if no list left
    if(st == en) return arr[st]; // if only one list left

    // find mid
    int mid = (st + en) / 2;

    // divide the list intow two parts and store in l1 and l2
    Node* l1 = mergeKlistsUTIL(arr, st, mid);
    Node* l2 = mergeKlistsUTIL(arr, mid+1, en);
    
    // then merge both
    return mergeTwoSortedList(l1, l2);
}

Node* mergeKSortedLists(Node* arr[], int k) {
    // call recusrive function with arr and starting index and ending index
    return mergeKlistsUTIL(arr, 0, k-1);
}


int main() {
   
    // Number of linked lists
    int k = 3; 
  
    // An array of pointers storing the head nodes of the linked lists
    Node* arr[k];
  
    // Creating k = 3 sorted lists
    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);
  
    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);
  
    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
  
    // Merge the k sorted lists
    Node* head = mergeKSortedLists(arr, k);
  
    // Print the merged list
    printList(head);

    return 0;
}