#include<bits/stdc++.h>
using namespace std;

// BST Node
struct Node {
    int data;
    Node* left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
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

// Utility function to print the inorder
void inorder(Node* root) {
    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to search a node in BST. Recursive Approch TC O(H) SC O(H)
bool search(Node* root, int x) {
    if(!root) return false; // base case 

    if(root->data == x) return true; // if value found 
    
    // if value to find is smaller than root, search in left
    if(root->data > x) return search(root->left, x);

    // else search in right
    return search(root->right, x);
}

// Function to search a node in BST. Iterative Approch TC O(H) SC O(1)
bool search(Node* root, int x) {
    if(!root) return false; // base case
    
    // create a temp node to traverse on tree
    Node* temp = root;
    while(temp) {
        // if value found
        if(temp->data == x) return true;
        // if value to find is smaller then move towards left
        else if(temp->data > x) temp = temp->left;
        // if value to find is greater then move towards right
        else temp = temp->right;
    }

    // when value not found
    return false;
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

    inorder(root);

    cout << ( search(root, 6)  ? "Found\n" : "Not Found\n" );

    return 0;
}