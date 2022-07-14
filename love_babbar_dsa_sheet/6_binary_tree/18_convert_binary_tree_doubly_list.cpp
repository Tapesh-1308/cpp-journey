#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Approach - 1  Using Inorder Traversal - TC O(N^2) SC O(N)

/* This is the core function to convert tree to list. */
Node* bintree2listUtil(Node* root)
{
	// Base case
	if (!root) return root;

	// Convert the left subtree and link to root
	if (root->left) {
		// Convert the left subtree
		Node* left = bintree2listUtil(root->left);

		// Find inorder predecessor. After this loop, left will point to the inorder predecessor
        while(left->right)
            left = left->right;

		// Make root as next of the predecessor
		left->right = root;

		// Make predecessor as previous of root
		root->left = left;
	}

	// Convert the right subtree and link to root
	if (root->right) {
		// Convert the right subtree
		Node* right = bintree2listUtil(root->right);

		// Find inorder successor. After this loop, right will point to the inorder successor
        while(right->left)
            right = right->left;

		// Make root as previous of successor
		right->left = root;

		// Make successor as next of root
		root->right = right;
	}

	return root;
}

// The main function that first calls bintree2listUtil()
Node* bintree2list(Node* root) {
	// Base case
	if (root) return root;

	// Convert to DLL using bintree2listUtil()
	root = bintree2listUtil(root);

	// bintree2listUtil() returns root node of the converted DLL. We need pointer to the leftmost node which is head of the constructed DLL, so move to the leftmost node
	while (root->left)
		root = root->left;

	return root;
}

// Approach - 2 Keeping track of previously processed node TC O(N) SC O(N)
void solve(Node* root, Node* &prev, Node* &head) {
    if(!root) return; // Base Case
    
    // Process left subtree
    solve(root->left, prev, head);
    
    // Process current node

    // if `prev` is null, then update the head of doubly linked list
    // as this is the first node in inorder
    if(!prev) 
        head = root;
    // adjust pointers
    else {
        // set the curr node's left child to `prev`
        root->left = prev;
        // make the previous node's right child as `root`
        prev->right = root;
    }
    // after the current node is visited, update the previous pointer
    // to the current node
    prev = root;
    
    // Process right subtree
    solve(root->right, prev, head);
}

Node* bintree2list(Node* root) {
    // `prev` keeps track of the previously processed node in the inorder traversal
    // `head` stores first node of doubly linked list
    Node* prev = NULL, *head = NULL;
    
    // convert the above binary tree into doubly linked list (using inorder traversal)
    solve(root, prev, head);

    return head;
}

/* Function to print nodes in a given doubly linked list */
void printList(Node* root) {
	while (root != NULL) {
		cout << root->data << " ";
		root = root->right;
	}
}

/* Driver code*/
int main() {
    
	Node* root = new Node(10);
	root->left = new Node(12);
	root->right = new Node(15);
	root->left->left = new Node(25);
	root->left->right = new Node(30);
	root->right->left = new Node(36);

	// Convert to DLL
	Node* head = bintree2list(root);

	// Print the converted list
	printList(head);

	return 0;
}