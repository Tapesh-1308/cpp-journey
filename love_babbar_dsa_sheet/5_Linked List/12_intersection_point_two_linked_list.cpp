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

// Utility Function to calculate the length of linked list
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;

    while(temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Approach 1 - Brute Force TC O(M*N) SC O(1)
Node* intersectionPresent(Node* head1,Node* head2) {
    while(head2) {
        Node* temp = head1;
        while(temp) {
            //if both Nodes are same
            if(temp == head2) 
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

// Approach - HashSet TC O(M+N) SC O(N)
Node* intersectionPresent(Node* head1,Node* head2) {
    unordered_set<Node*> st; // create a set to store nodes of list1
    // storing all nodes
    while(head1) {
       st.insert(head1);
       head1 = head1->next;
    }
    // checking in list2 if any node is already present
    while(head2) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;

}

// Approach 3 TC O(M+N) SC O(1)
Node* getIntersectionPoint(Node* head1, Node* head2) {
    // Calculate length of head1 and head2 and store in l1 and l2
    int l1 = getLength(head1), l2 = getLength(head2);

    // Create two pointer ptr1 -> head1, ptr2 -> head2
    Node *ptr1 = head1, *ptr2 = head2;
    
    // if head1 length is greater than head2
    if(l1 > l2) {
        // then calculate the diff and move ptr1 by diff, so that ptr1 ptr2 aligns
        int diff = l1-l2;
        while(diff--) {
            ptr1 = ptr1->next;
        }
    }
    // if head2 length is greater then do same for ptr2
    if(l2 > l1) {
        int diff = l2-l1;
        while(diff--) {
            ptr2 = ptr2->next;
        }
    }

    // now move both pointer forward till they become equal
    while(ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // if they became equal then return any one, if not then they reach null
    return ptr1;
}

// Approach - 4 TC O(M+N) SC O(1)
Node* getIntersectionPoint(Node* head1, Node* head2)
{
    // if not head1 or head2 then no intersection so return null
    if(!head1 || !head2) return NULL;

    // create teo pointer to traverse
    Node* ptr1 = head1, *ptr2 = head2;
    
    // move both ptr, if ptr1 reach null send it to head2 and if ptr2 reach null send it to head1 otherwise keep moving them forward, after doing so they will meet at intersection, so break out of loop 
    while(ptr1 != ptr2) {
        ptr1 = !ptr1 ? head2 : ptr1->next;
        ptr2 = !ptr2 ? head1 : ptr2->next;
    }
    
    // return intersection point or null if not found intersection
    return ptr1;
}

int main() {

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

    Node* intersectionPoint = getIntersectionPoint(head1, head2);

    if(!intersectionPoint) 
        cout << " No Intersection Point \n";
    else cout << "Intersection Point: " << intersectionPoint->data << endl;

    return 0;
}