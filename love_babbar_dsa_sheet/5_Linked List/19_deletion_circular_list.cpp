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

/* Utility function to delete node at head */
void deleteAtHead(Node* &head) {
    // go to the last node
    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    // store head in todel
    Node* todel = head;
    temp->next = head->next;
    head = head->next; // updating head

    delete todel; // delete
}

void deletion(Node* &head, int key) {
    // if empty list
    if(!head) return;

    // if list has only one node and its data also matches
    if(head->next == head && head->data == key) {
        delete head; // delete that node and return
        return;
    }

    // if key was on head call deleteathead
    if(head->data == key)
        return deleteAtHead(head);

    // Finding the previous from node to delete
    Node* temp = head;
    while(temp->next->data != key && temp->next != head) 
        temp = temp->next;

    // if found 
    if(temp->next->data == key) {
        Node* todel = temp->next; 
        temp->next = temp->next->next; 
        delete todel; // delete that node
    }
    // if not found 
    else cout << "Data not found \n";
}


void printList(Node *head) {
    if(!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);

    cout << endl;
}

int main() {
    Node *head = NULL;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    printList(head);

    deletion(head, 1);

    printList(head);

    return 0;
}
