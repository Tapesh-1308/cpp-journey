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

/* Utility function to check if a node is leaf or node */
bool leaf(Node* root) {
    return !root->left && !root->right;
}

/* Utility function to print all left nodes */
void printLeft(Node* root) {
    if(!root) return; // Base Case

    // print only if node is not leaf
    if(!leaf(root)) 
        cout << root->data << " ";

    // move only towards left until we have left
    if(root->left) printLeft(root->left);
    else printLeft(root->right); // then move right if we don't have
}

/* Utility function to print all leaf nodes */
void printLeaf(Node* root) {
    if(!root) return; // Base Case

    // print only if given node is leaf
    if(leaf(root))
        cout << root->data << " ";
    else {
        // if not leave traverse to find leaf nodes
        printLeaf(root->left);
        printLeaf(root->right);    
    }
}

/* Utility function to print right nodes in reverse order */
void printRight(Node* root) {
    if(!root) return; // Base Case

    // move only towards right until we have right
    if(root->right) printRight(root->right);
    else printRight(root->left); // then move left if we don't have

    // print only if it is not leaf node
    if(!leaf(root)) 
        cout << root->data << " ";
}

// Approach TC O(N) SC O(N)
void boundary_traversal(Node* root) {
    if(!root) return; // Base Case  : Empty Tree

    // Step #1 : print root
    cout << root->data << " ";

    // Step #2 : print left nodes
    printLeft(root->left);
    
    // Step #3 : print all leaf nodes (don't pass root as root can also be a leaf node and we already process root)
    printLeaf(root->left);
    printLeaf(root->right);

    // Step #4 : print right node in reverse order0
    printRight(root->right);
}

int main(){
    Node* root = new Node(20);
	root->left = new Node(8);

	root->left->left = new Node(4);
	root->left->right = new Node(12);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	root->right = new Node(22);
	root->right->right = new Node(25);

    boundary_traversal(root);
    return 0;
}