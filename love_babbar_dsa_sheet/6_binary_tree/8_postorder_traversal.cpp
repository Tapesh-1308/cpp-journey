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
void postorder(Node* root) {
    // return if the current node is empty
    if(!root) return;

    // Traverse the left subtree
    postorder(root->left);
    // Traverse the right subtree
    postorder(root->right);
    // Display the data part of the root (or current node)
    cout << root->data << " ";
}

// Approach - 2 Using Stack - TC O(N) SC (N)
void postorder(Node* root) {
    // return if the tree is empty
    if (!root) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
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

    postorder(root);
    return 0;
}