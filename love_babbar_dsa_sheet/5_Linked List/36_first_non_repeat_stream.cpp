// Doubly Linked List Based Approach
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node* prev;

    Node(char x) {
        data = x;
        next = NULL;
        prev = NULL;
    } 
};

// A utility function to push a character x at the end of DLL.
void push(Node* &head, Node* &tail, char data) {
    // create new node
    Node* newNode = new Node(data);

    // if it is the first node update head and tail 
    if(!head) {
        head = newNode;
        tail = head;
        return;
    }
    // if not first add it to last
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// A utility function to remove a node 'curr' from DLL and also update head and tail if needed
void removeNode(Node* &head, Node* &tail, Node* curr) {
    if(!curr) return;

    // if not to be delete is on head update head first same for tail
    if(curr == head) head = head->next;
    if(curr == tail) tail = tail->prev;

    // join curr left node with curr right node
    if(curr->prev) curr->prev->next = curr->next;
    if(curr->next) curr->next->prev = curr->prev;

    // delete the node to be deleted
    delete curr;
}

// Approach - TC = O(N) SC O(N)
string findFirstNonRepeat(char stream[]) {
    // address[x] contains pointer to a DLL node if x is present in DLL. If x is not present, then address[x] is NULL
    Node* address[256] = {NULL};

    // repeated[x] is true if x is repeated two or more times. If x is not seen so far or x is seen only once, then repeated[x] is false
    bool visited[256] = {false};

    string ans = ""; // store ans 

    // to create new list
    Node* head = NULL;
    Node* tail = head;

    // consider the char stream[] 
    for(int i=0; stream[i]; i++) {
        char x = stream[i];

        // We process this character only if it has not occurred or occurred only once. repeated[x] is true if x is repeated twice or more times.
        if(!visited[x]) {
            // If the character is present in DLL, then remove this character from DLL
            if(address[x]) {
                removeNode(head, tail, address[x]);
                address[x] = NULL; // also update address array
                visited[x] = true; // Also mark it as repeated
            }

            // Otherwise add this at the end of DLL.
            else {
                push(head, tail, x);
                address[x] = tail; // and also update address array
            }
        }

        // Add the current first non-repeating character from stream in answer
        if(head)
            ans.push_back(head->data);
        else ans.push_back('#'); // if no such char add #
    }
    // return the answer 
    return ans;
}

int main(){
    char stream[] = "aabc";
    cout << findFirstNonRepeat(stream) << endl;
    return 0;
}
