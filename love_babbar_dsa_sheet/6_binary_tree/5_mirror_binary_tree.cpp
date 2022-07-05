#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

// To Create a mirror tree from the given binary tree
// Recursive Solution TC O(N) SC O(H)
void create_mirror_tree(Node* root, Node* &mirror) {
    // Base case
    if(!root) {
        mirror = NULL;
        return;
    }

    // create a copy node of root in mirror
    mirror = new Node(root->data);

    // call for (left of root with right of mirror) and (right of root with left of mirror)
    create_mirror_tree(root->left, mirror->right);
    create_mirror_tree(root->right, mirror->left);
}

// To Convert a Binary Tree into its Mirror Tree

// Approach - 1 Using Recursion - TC O(N) SC O(H) (height of tree)
void convert_tree(Node* root) {
    // Base Case
    if(!root) {
        return;
    }

    // Swap  left child with right child
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // call recursively for left and right subtree
    if(root->left) convert_tree(root->left);
    if(root->right) convert_tree(root->right);
}

// Approach - 2 Iterative Using Queue - TC O(N) SC O(N)
void convert_tree(Node* root) {
    // create an empty queue and push root node
    queue<Node*> q;
    q.push(root);

    // run while queue is not empty
    while(!q.empty()) {
        // get front node and remove it from queue
        Node* temp = q.front();
        q.pop();

        // swap left with right child of temp
        swap(temp->left, temp->right);

        // push left and right child in queue
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

/* Utility Function to get the inorder of a binary tree */
void inorder (Node* root) {
    // Base Case
    if(!root) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    cout << endl;

    // Create new tree
    // Node* mirror = NULL;
    // create_mirror_tree(root,mirror);
    // inorder(mirror);

    // Convert input tree
    convert_tree(root);
    inorder(root);

    return 0;
}