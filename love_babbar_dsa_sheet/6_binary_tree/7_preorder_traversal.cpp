#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

// Approach - 1 Using Recusrion - TC O(N) SC O(N)
void preorder(Node* root) {
    // return if the current node is empty
    if(!root) return;

    // Display the data part of the root (or current node)
    cout << root->data << " ";
    // Traverse the left subtree
    preorder(root->left);
    // Traverse the right subtree
    preorder(root->right);
}

// Approach - 2 Using Stack - TC O(N) SC (N)
void preorder(Node* root) {
     // return if the tree is empty
    if (root == nullptr)
    return;
 
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        Node* curr = stack.top();
        stack.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
        }
 
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}

int main() {
    Node* root = NULL;
    root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(5);

    root->left->left = new Node(7);
    root->left->right = new Node(11);

    root->right->left = new Node(17);

    preorder(root);
    return 0;
}