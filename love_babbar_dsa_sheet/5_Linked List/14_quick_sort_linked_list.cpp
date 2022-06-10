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

/* Utility function to make partition over pivot index (middle) */
vector<Node *> partition(Node *head, int pivotIdx) {
    // find pivot node using pivot index
    Node *curr = head, *pivot;
    int idx = 0;
    // traverse on list
    while (curr) {
        // if index becomes equal to pivot index
        if (idx == pivotIdx) {
            // then make pivot node equal to current node
            pivot = curr;
            break;
        }
        // move forward and increment index
        curr = curr->next;
        idx++;
    }

    // Create two dummy nodes 1) Smaller 2) Larger
    // Smaller list store all nodes smaller than pivot node
    // Larger list store all nodes larger than pivot node
    Node *smaller = new Node(-1), *larger = new Node(-1);
    Node *ps = smaller, *pl = larger; // ps and pl helps to traverse (ptr smaller, ptr larger)

    // re-intialize curr
    curr = head;

    while (curr) {
        // if curr is equal to pivot then just move curr forward
        if (curr != pivot) {
            // if current node data is smaller than pivot 
            if (curr->data <= pivot->data) {
                // then points it with smaller  
                ps->next = curr;
                ps = curr; // move ps
            }
            else {
                // points it with larger
                pl->next = curr;
                pl = curr; // move pl
            }
        }
        // move curr
        curr = curr->next;
    }
    // Now we have all 3 partition (left, pivot, right) just detach all, last node of every partition points to null
    ps->next = NULL;
    pl->next = NULL;
    pivot->next = NULL;

    // return in the form of vector
    return {smaller->next, pivot, larger->next};
}

/* Utility functon to get length of list */
int findLength(Node *head) {
    int len = 0;
    Node *curr = head;

    // increment len and move curr forward till curr reach null
    while (curr) {
        len++;
        curr = curr->next;
    }

    // return length
    return len;
}

/* Utility function to rejoin left part, pivot node and right part */
vector<Node *> rejoinLists(vector<Node *> left, Node *pivot, vector<Node *> right) {
    // create head and tail to return
    Node *head = NULL, *tail = NULL;

    // if both left part and right part is empty, means we have one pivot node
    if (!left[0] && !right[0]) {
        // then head and tail both points on pivot and return
        head = pivot;
        tail = pivot;
        return {head, head};
    }

    // if only left part is empty
    else if (!left[0]) {
        // then join pivot with right part head and pivot become head tail become right part tail
        head = pivot;
        pivot->next = right[0];
        tail = right[1];
    }

    // if only right party is empty
    else if (!right[0]) {
        // then join left tail with pivot node and left head become head and pivot become tail
        head = left[0];
        left[1]->next = pivot;
        tail = pivot;
    }

    // if no one is empty
    else {
        // then left tail points to pivot, pivot points to right head
        // head will be left head and tail will right tail
        head = left[0];
        left[1]->next = pivot;
        pivot->next = right[0];
        tail = right[1];
    }
    // return new head and tail
    return {head, tail};
}

/* quick sort utility function */
vector<Node *> quickSortUtil(Node *head) {
    // base case, if there is one or zero element
    // then head tail both points on head
    if (!head || !head->next)
        return {head, head};

    // finding length to get pivotidx at mid of list
    int len = findLength(head);

    // Partioning list over middle element -> returns
    // { left_part_head_pointer, pivot_node, right_part_head_pointer }
    vector<Node *> partitioned = partition(head, len / 2);

    // Recursive call over left and right part to get head and tail after sorting
    vector<Node *> left = quickSortUtil(partitioned[0]);  //[0] -> leftparthead
    vector<Node *> right = quickSortUtil(partitioned[2]); // [2] -> rightparthead

    // rejoin partitioned list and return rejoined list head and tail in vector
    return rejoinLists(left, partitioned[1], right);
}

/*      Approach          Best Case         Average Case         Worst Case
    * Time Complexty   ->  O(NlogN)          >O(NlogN)            O(N^2)
    * Space Complexity ->  O(logN)           >O(logN)             O(N)
*/
Node *quickSort(Node *head) {
    // if empty list or one node then return it
    if (!head || !head->next)
        return head;

    // call quick sort utility function which return a vector of node {headPtr, tailPtr}
    // just return headptr
    return quickSortUtil(head)[0];
}

int main() {
    Node *first = NULL;

    first = new Node(4);
    first->next = new Node(1);
    first->next->next = new Node(8);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(5);

    cout << "List 1: ";
    printList(first);
    cout << endl;

    Node *sorted = quickSort(first);

    cout << "Sorted Array: ";
    printList(sorted);
    cout << endl;

    return 0;
}