#include <iostream>
using namespace std;

// Creating Node
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

//Inserting element at first
void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}

//Inserting element at last
void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

//Displaying linked list
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//Searching elements in linked list
bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//Deleting first element in linked list
void deleteAtHead(Node *&head)
{
    Node *todelete = head;
    head = head->next;
    delete todelete;
}

//Deleting elements in linked list
void deleteKey(Node *&head, int key)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    while (temp->next->data != key)
    {
        temp = temp->next;
    }

    Node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

// Delete element at last
void deleteAtTail(Node *&head)
{
    Node *temp = head;
    Node *todelete = temp->next;
    while (todelete->next != NULL)
    {
        temp = temp->next;
        todelete = todelete->next;
    }
    temp->next = NULL;
    delete todelete;
}

//Reverse Linked List
Node *reverse(Node *&head)
{
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;

    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

// Reversing linked list using recursion
Node *reverseRec(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Reversing ll with k node
Node *reverseK(Node *&head, int k)
{
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;

    int count = 0;

    while (currPtr != NULL && count < k)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }

    if (nextPtr != NULL)
        head->next = reverseK(nextPtr, k);

    return prevPtr;
}

Node *detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // cout<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node *detectCycleFirst(Node *&head)
{
    Node *meet = detectCycle(head);
    Node *start = head;

    while (start != meet)
    {
        start = start->next;
        meet = meet->next;
    }
    cout << start->data << endl;
    return start;
}

void removeLoop(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int length(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

//Question k append
Node *kappend(Node *&head, int k)
{
    Node *newHead;
    Node *newTail;
    Node *tail = head;

    int l = length(head);
    k = k % l;
    int count = 1;

    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

// Question intersection point of 2 LL
int intersection(Node *&head1, Node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    Node *ptr1;
    Node *ptr2;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {

        if (ptr1 == ptr2)
        {
            return ptr2->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void intersect(Node *&head1, Node *&head2, int pos)
{
    Node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

// Question Merge 2 sorted LL
Node *merge(Node *&head1, Node *&head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *dummy = new Node(-1);
    Node *p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummy->next;
}

// Recursively
Node* mergeRecu(Node* &head1, Node* & head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRecu(head1->next, head2);
    } else{
        result = head2;
        result->next = mergeRecu(head1, head2->next);
    }

    return result;
}

// odd 1st then even
void evenAfterOdd(Node *& head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenStart = even;
    while(odd->next!=NULL & even->next!=NULL){
        odd->next = even->next;
        odd=odd->next;
        even->next = odd->next;
        even=even->next;
    }
    odd->next = evenStart;
    if(odd->next==NULL){
        even->next = NULL;
    }
}

int main()
{
    // Node *head = NULL;
    // insertAtHead(head, 1);
    // insertAtTail(head, 2);
    // insertAtTail(head, 3);
    // insertAtTail(head, 4);
    // insertAtTail(head, 5);
    // insertAtTail(head, 6);
    // display(head);
    // // cout << search(head, 3) << endl;
    // // deleteAtHead(head);
    // // deleteKey(head, 3);
    // // deleteAtTail(head);
    // // Node* newhead = reverse(head);
    // // Node* newhead = reverseRec(head);
    // // display(newhead);

    // // int k = 2;
    // // Node* newhead = reverseK(head, k);
    // // display(newhead);
    // head->next->next->next->next->next->next = head->next->next;
    // // display(head);
    // cout<<detectCycle(head)<<endl;
    // // detectCycleFirst(head);
    // removeLoop(head);
    // cout<<detectCycle(head)<<endl;
    // display(head);

    // Node* head = NULL;
    // int arr[6] = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < 6; i++)
    // {
    //     insertAtTail(head, arr[i]);
    // }
    // display(head);
    // Node* newHead = kappend(head, 3);
    // display(newHead);

    // Node *head1 = NULL;
    // Node *head2 = NULL;
    // insertAtHead(head1, 1);
    // insertAtTail(head1, 2);
    // insertAtTail(head1, 3);
    // insertAtTail(head1, 4);
    // insertAtTail(head1, 5);
    // insertAtTail(head1, 6);
    // insertAtTail(head2, 9);
    // insertAtTail(head2, 10);
    // intersect(head1, head2, 5);
    // display(head1);
    // display(head2);
    // cout << intersection(head1, head2);

    // Node* head1 = NULL;
    // Node* head2 = NULL;
    // int arr1[4] = {1, 3,  5, 7};
    // int arr2[3] = {2, 4, 6};
    // for (int i = 0; i < 4; i++)
    // {
    //     insertAtTail(head1, arr1[i]);
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     insertAtTail(head2, arr2[i]);
    // }
    // display(head1);
    // display(head2);
    // // Node* newHead = merge(head1, head2);
    // Node* newHead = mergeRecu(head1, head2);
    // display(newHead);

    Node* head = NULL;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);
    evenAfterOdd(head);
    display(head);

    return 0;
}