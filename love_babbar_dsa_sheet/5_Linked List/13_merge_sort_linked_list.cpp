#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
    Node(int a) {
        data = a;
        next = NULL;
    }
};

// A utility function to print a linked list
void printList(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// ############################ Two Merge Functions ###################################### //

// Approach - 1 Merge Function TC O(N+M) SC O(N+M) 
Node* merge (Node* first, Node* second) {
    // Edge Cases
    if(!first) return second;
    if(!second) return first;

    // Create a dummy node
    Node* ans = new Node(-1);
    Node* temp = ans; // and temp pointer to traverse for ans


    // traverse
    while(first && second) {
        // if first-data is smaller than second-data
        if(first->data < second->data) {
            // add first in temp
            temp->next = first; 
            temp = first;
            // move first forward
            first = first->next;
        }
        else { // if greater
            // add second in temp
            temp->next = second;
            temp = second;
            // move second
            second = second->next;
        }
    }

    // if second list exhausted, add all first's node in temp
    while(first) {
        temp->next = first;
        temp = first;
        first = first->next;
    }
    // if first list exhauseted, add all second's node in temp
    while(second) {
        temp->next = second;
        temp = second;
        second = second->next;
    }

    // return ans by removing dummy node
    return ans->next;
}
//------------------------------------------------------------------------------------------//

/* Utility Function for In-Place merge sort */
Node* solve(Node* first, Node* second) {
    
    /* * In this function first starts with smaller 
       * element ans second starts with greater element 
    */

    // If there is only one element
    if(!first->next) {
        first->next = second; // just points its next to second and return 
        return first;
    }
    
    // Curr1 and next1 are two pointers for first list
    Node* curr1 = first;
    Node* next1 = curr1->next;
    
    // Cuur2 and next2 are two pointers for second list
    Node* curr2 = second;
    Node* next2 = curr2->next;
    
    // traverse 
    while(next1 && curr2) {
        // if we can add curr2 node in between curr1 and next1
        if((curr1->data <= curr2->data) &&
           (next1->data >= curr2->data)) {

            // then add
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            
            // and after this move pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            // if we can't add then just move pointers
            curr1 = next1;
            next1 = next1->next;
            
            // if first list end then just points its last element with curr2 and return first
            if(!next1) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    // return merged list
    return first;
}

// Approach - 2 In-Place Merge Sort TC O(N+M) SC O(1)
Node* merge(Node* first, Node* second) {
    // Edge Cases
    if(!first) return second; 
    if(!second) return first;
    
    // we always merge in list starting with smaller element

    // if first-data is smaller than second-data, then send first before, then second
    if(first->data <= second->data)
        return solve(first, second);
    // else send second before and first after
    return solve(second, first);
}

// ##################################### Merge Functions End #################################### //

/* Utility Function to find Middle Element */
Node* findMid(Node* head) {
    // Take 2 Pointer slow and fast
    Node* slow = head;
    Node* fast = slow->next;

    // move slow with spped 1 unit and fast with speed 2 unit
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // when fast reach null slow covered half distance, means at middle
    return slow;
}
/********************************************/

// Main Merge Sort Function - TC O(NLogN) SC O(logN) - By Using INplace merge function
Node* mergeSort(Node* head) {
    // Base Case
    if(!head || !head->next) return head;

    // Find Middle Element using findMid 
    Node* mid = findMid(head);

    // Divide list in two parts using mid
    Node* first = head; // first half
    Node* second = mid->next; // second half

    mid->next = NULL; // first half ends with null

    // recursive call for both first half and second half
    first = mergeSort(first);
    second = mergeSort(second);

    // merge first half and second half
    Node* result = merge(first, second);
    return result;
}

int main(){
    Node *first = NULL;

    first = new Node(4);
    first->next = new Node(1);
    first->next->next = new Node(8);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(5);

    cout << "List 1: ";
    printList(first);
    cout << endl;


    Node* sorted = mergeSort(first);

    cout << "Sorted List: ";
    printList(sorted);
    cout << endl;

    return 0;
}