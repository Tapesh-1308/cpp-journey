#include<bits/stdc++.h>
using namespace std;

// BST Node
struct Node {
    int data;
    Node* left, *right;

    Node(int data) : data(data),  left(NULL), right(NULL) {}
};

// Utility function to insert node in Binary Search Tree
void insert(Node* &root, int data) {
    if(!root) 
        root = new Node(data);
    if(root->data > data) 
        return insert(root->left, data);
    if(root->data < data) 
        return insert(root->right, data);
}

// Approach - TC O(H) SC O(H)
void findPreSuc(Node* root, Node* &pre, Node* &suc, int key)
{
    if(!root) return; // base case

    // if key is present at root    
    if(root->data == key){
        // find predecessor - the maximum value in left subtree is predecessor
        if(root->left) {
            Node* temp = root->left;
            while(temp->right) 
                temp = temp->right;
            pre = temp;
        }
        // find successor - the minimum value in right subtree is successor
        if(root->right) {
            Node* temp = root->right;
            while(temp->left) 
                temp = temp->left;
            suc = temp;
        }
    }
    
    // If key is smaller than root's key, go to left subtree
    else if(root->data > key) {
        suc = root; // update successor
        findPreSuc(root->left, pre, suc, key);
    }
    
    // go to right subtree
    else {
        pre = root; // update preddecessor
        findPreSuc(root->right, pre, suc, key);
    }
}

int main(){
    Node* root = NULL;

    insert(root, 8);
    insert(root, 10);
    insert(root, 3);
    insert(root, 14);
    insert(root, 1);
    insert(root, 6);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    Node* successor = NULL;
    Node* predecessor = NULL;
    int key = 10;

    findPreSuc(root, predecessor, successor, key);

    cout << "Inorder Predecessor: " << (predecessor ? predecessor->data : -1) << endl;
    cout << "Inorder Successor: " << (successor ? successor->data : -1) << endl;
    
    return 0;
}