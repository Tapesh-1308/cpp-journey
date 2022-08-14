#include <bits/stdc++.h>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;

    Node(int data): data(data) {}
};
 
// Function to perform inorder traversal on the tree
void inorder(Node* root)
{
    if (root == nullptr) 
        return;
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Function to find the k'th smallest node in a BST.
// Here, `i` denotes the total number of nodes processed so far
Node* kthSmallestUtil(Node* root, int *i, int k)
{
    // base case
    if (root == nullptr)
        return nullptr;
    
    // search in the left subtree
    Node* left = kthSmallestUtil(root->left, i, k);
 
    // if k'th smallest is found in the left subtree, return it
    if (left) return left;
 
    // if the current node is k'th smallest, return its value
    if (++*i == k) return root;
 
    // otherwise, search in the right subtree
    return kthSmallestUtil(root->right, i, k);
}
 
// Function to find the k'th smallest node in a BST
Node* kthSmallest(Node* root, int k)
{
    // maintain index to count the total number of nodes processed so far
    int i = 0;
 
    // traverse the tree in an inorder fashion and return k'th node
    return kthSmallestUtil(root, &i, k);
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    Node* root = nullptr;
    for (int key: keys)
        root = insert(root, key);
 
    int k = 2;
    Node* node = kthSmallest(root, k);
 
    if (node) 
        cout << node->data;
    else 
        cout << "Invalid Input";

    return 0;
}