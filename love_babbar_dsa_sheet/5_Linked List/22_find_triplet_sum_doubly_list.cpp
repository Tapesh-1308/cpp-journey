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


// Approach - 1 Brute Force - TC O(N^3) SC O(1)
void tripletSum(Node *head, int target) {
    // if list is empty
    if (!head)
        cout << "Empty List \n";

    // Create three pointers
    Node *first = head, *second, *third;
    int count = 0; // to return number of triplet we found

    // trvaerse through first
    while (first) {
        // trvaerse through second for every first
        second = first->next;
        while (second) {
            // traverse through third for every second
            third = second->next;
            while (third) {
                // check if sum is equal to target, if yes print triplet and increment count
                int sum = first->data + second->data + third->data;
                if (sum == target) {
                    cout << "(" << first->data << ", " << second->data << ", " << third->data << ") ";
                    count++;
                }
                third = third->next; // move third forward
            }
            second = second->next; // move second forward
        }
        first = first->next; // move first forward
    }

    // if count is still 0 means no triplet found
    if (!count)
        cout << "No Triplet Found\n";
    else // else print count
        cout << "\nCount: " << count << endl;
}

// Approach - 2 Using HashSet - TC O(N^2) SC O(N)
void tripletSum(Node *head, int target) {
    // if list is empty
    if (!head)
        cout << "Empty List \n";

    // create two pointer and count
    Node *first = head, *second;
    int count = 0;

    unordered_map<int, Node *> um; // to store key as data and value as node ptr

    // fill unordered map
    while (first) {
        um[first->data] = first;
        first = first->next;
    }

    // reuse first
    first = head;

    // traverse list through first
    while (first) {
        // traverse list throught second for every fist
        second = first->next;
        while (second) {
            // if two sum and check if 3rd number is present in map or not (such that two sum + 3rd = target), means target - twoSum = 3rd number
            int sum = first->data + second->data;
            if (um.find(target - sum) != um.end() && // if 3rd number is present
                um[target - sum] != first &&  // if 3rd number node is first
                um[target - sum] != second &&  // and also not second
                second->data < target - sum) { // and the 3rd number should also present after second not before, to remove duplicacy in triplets (1,2,3) = (1,3,2), it will now count 1 time

                cout << "(" << first->data << ", " << second->data << ", " << target - sum << ") "; // print 
                count++; // increment count 
            }

            second = second->next; // move second forward
        }
        first = first->next; // move first forward
    }

    // if count is still zero
    if (!count)
        cout << "No Triplet Found\n";
    else // else print count value
        cout << "\nCount: " << count << endl;
}

// Approach - 3 Using Two Pointer - TC O(N^2) SC O(1)
void tripletSum(Node *head, int target) {
    // if list is empty
    if (!head)
        cout << "Empty List \n";

    // creating three pointer ptr, first and last
    Node *ptr = head, *first = head, *last = head;

    int count = 0; // create a counter

    // move last pointer to last node
    while (last->next)
        last = last->next;

    // traverse through ptr
    while (ptr) {
        int newTarget = target - ptr->data; // newTarget searched by twoPointer algo 

        // apply two pointer for every ptr
        first = ptr->next;

        // run till both collide, ptr->next can be null so do check for first
        while (first && first->data < last->data) {
            // if sum is equal to newtarget, print
            if (first->data + last->data == newTarget) {
                cout << "(" << ptr->data << ", "
                     << first->data << ", "
                     << last->data << ") ";
                count++; // increment count

                first = first->next; // move first forward
                last = last->prev;   // and last backward
            }

            // if sum is smaller than newTarget we have to move first forward
            else if (first->data + last->data < newTarget) 
                first = first->next;
            
            // else move last backward
            else last = last->prev;
            
        }
        ptr = ptr->next; // move ptr forward
    }

    // if no triplet found
    if (!count)
        cout << " No Triplet Found \n";
    else // else print count
        cout << "\nCount: " << count << endl;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    insert(head, tail, 4);
    insert(head, tail, 5);
    insert(head, tail, 6);

    printList(head);

    tripletSum(head, 9);

    return 0;
}
