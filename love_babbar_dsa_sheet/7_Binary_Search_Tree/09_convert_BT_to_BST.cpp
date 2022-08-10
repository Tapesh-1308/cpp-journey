/* A program to convert Binary Tree to Binary Search Tree */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* 
Complexity Analysis:

Time Complexity: O(nlogn). This is the complexity of the sorting algorithm which we are using after first in-order traversal, rest of the operations take place in linear time.

Auxiliary Space: O(n). Use of data structure ‘array’ to store in-order traversal.
*/

/* A helper function that stores inorder traversal of a tree rooted with node */
void storeInorder(struct node *node, vector<int> &inorder) {
    // Base Case
    if (node == NULL)
        return;

    /* first store the left subtree */
    storeInorder(node->left, inorder);

    /* store current node data */
    inorder.push_back(node->data);

    /* finally store the right subtree */
    storeInorder(node->right, inorder);
}

/* A helper function that copies contents of arr[] to Binary Tree. This function basically does Inorder
traversal of Binary Tree and one by one copy arr[] elements to Binary Tree nodes */
void arrayToBST(struct node *&root, vector<int> inorder, int &index_ptr) {
    // Base Case
    if (!root || index_ptr >= inorder.size())
        return;

    /* first update the left subtree */
    arrayToBST(root->left, inorder, index_ptr);

    /* Now update root's data and increment index */
    root->data = inorder[index_ptr++];

    /* finally update the right subtree */
    arrayToBST(root->right, inorder, index_ptr);
}

// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct node *&root) {
    // base case: tree is empty
    if (root == NULL)
        return;

    // Create a vector and store inorder traversal of tree in inorder
    vector<int> inorder;
    storeInorder(root, inorder);

    // Sort the array using library function for quick sort
    sort(inorder.begin(), inorder.end());

    // Copy array elements back to Binary Tree
    int i = 0;
    arrayToBST(root, inorder, i);
}

/* Utility function to create a new Binary Tree node */
struct node *newNode(int data) {
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Utility function to print inorder traversal of Binary Tree */
void printInorder(struct node *node) {
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << " " << node->data;

    /* now recur on right child */
    printInorder(node->right);
}

int main() {
    struct node *root = NULL;

    /* Constructing given tree
          10
        /   \
       30    15
      /	      \
     20	       5  */

    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    // convert Binary Tree to BST
    binaryTreeToBST(root);

    cout << "Following is Inorder Traversal of the converted BST:" << endl;
    printInorder(root);

    return 0;
}
