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

// Approach - TC O(H) SC O(H)

// Function to find the minimum element in the given BST.
int minValue(Node* root) {
    if(!root) return -1;
    Node* temp = root;

    // find the left most node
    while(temp->left)
        temp = temp->left;
    return temp->data;
}

// Function to find the maximum element in the given BST.
int maxValue(Node* root) {
    if(!root) return -1;
    Node* temp = root;
    // find the right most node
    while(temp->right)
        temp = temp->right;
    return temp->data;
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

    cout << "Minimum Value: " << minValue(root) << endl;
    cout << "Maximum Value: " << maxValue(root) << endl;

    return 0;
}