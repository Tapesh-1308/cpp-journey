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
void inorder(Node* root) {
    // return if the current node is empty
    if(!root) return;

    // Traverse the left subtree
    inorder(root->left);
    // Display the data part of the root (or current node)
    cout << root->data << " ";
    // Traverse the right subtree
    inorder(root->right);
}

// Approach - 2 Using Stack - TC O(N) SC (N)
void inorder(Node* root) {
    // create an empty stack
    stack<Node*> st;
    // start from the root node (set current node to the root node)
    Node* curr = root;

    // if the current node is null and the stack is also empty, we are done
    while(!st.empty() || curr) {
        // if the current node exists, push it into the stack (defer it) and move to its left child
        if(curr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack, print it, and finally set the current node to its right child
            curr = st.top();
            st.pop();

            cout << curr->data << " ";

            curr = curr->right;
        }
    }
}

int main(){
    Node* root = NULL;
    root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(5);

    root->left->left = new Node(7);
    root->left->right = new Node(11);

    root->right->left = new Node(17);

    inorder(root);
    return 0;
}