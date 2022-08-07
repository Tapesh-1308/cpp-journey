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

// Utility function to find minimum value node 
Node* minNode(Node* root) {
    // create a node to traverse
    Node* temp = root;

    // move to left most node
    while(temp->left)
        temp = temp->left;

    // and return it
    return temp;
}

// Function to delete node in a binary search tree
Node* deleteNode(Node* root, int key) {
    if(!root) return root; // base case

    if(root->data > key) // if key is smaller go to the left subtree
        root->left = deleteNode(root->left, key);

    else if(root->data < key) // if key is greater go to the right subtree
        root->right = deleteNode(root->right, key);

    else { // if key matches  

        // steps for node having zero or one child

        if(!root->left) { // node with only right child or no child
            // store right subtree in temp and delete root node(node with key) and return right subtree
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right) { // node with left child
            // store left subtree in temp and delete root node(node with key) and return left subtree
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // steps for node with two childs
        else {
            // find the minimum node value in the right subtree
            Node* temp = minNode(root->right);
            root->data = temp->data; // replace data with temp data
            root->right = deleteNode(root->right, temp->data); // delete temp node
        }
    }

    // return the updated tree
    return root;
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
    cout << endl;

    deleteNode(root, 8);

    inorder(root);
    cout << endl;
    

    return 0;
}