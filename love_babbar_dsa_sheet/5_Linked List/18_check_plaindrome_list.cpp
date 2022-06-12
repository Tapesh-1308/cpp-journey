#include<bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Utility function to find middle element */
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/* Utility function to reverse the list */
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    
    while(curr!= NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Approach - 1 Using Stack TC O(N) SC O(N)
bool isPalindrome(Node* head) {
    stack<int> st;

    Node* temp = head;
    while(temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp) {
        if(st.top() != temp->data) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

// Approach - 2 By Reversing list TC O(N) SC O(1)
bool isPalindrome(Node *head)
{
    if(!head -> next) return 1;
    Node* middle = getMid(head);
    
    Node* temp = middle->next;
    middle->next = reverse(temp);
    
    Node* head1 = head;
    Node* head2 = middle->next;
    
    while(head2){
        if(head1->data != head2->data) return false;
        head1=head1->next;
        head2= head2->next;
    }
    
    temp = middle->next;
    middle->next = reverse(temp);
    return true;
}

// Approach - 3 Recursion TC O(N) SC O(N)
bool isPalindromeUtil(Node* &left, Node* right) {
    if(!right) return true;

    bool isSubListP = isPalindromeUtil(left, right->next);
    bool isCurrE = left->data == right->data;

    left = left->next;
    return isSubListP && isCurrE;
}
bool isPalindrome(Node* head) {
    return isPalindromeUtil(head, head);
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
    Node *head = NULL;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    printList(head);
    cout << endl;
    
    if(isPalindrome(head))
        cout << "List is a Palindrome\n";
    else cout << "List is NOT a Pallindrome\n";

    return 0;
}
