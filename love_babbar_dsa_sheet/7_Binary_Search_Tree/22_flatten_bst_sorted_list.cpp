// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Approach - TC O(N) SC O(H)

// Function to print flattened binary Tree
void print(Node* root)
{
	Node* root = root;
	while (root != NULL)
		cout << root->data << " ", root = root->right;
}

// Function to perform in-order traversal recursively
void inorder(Node* root, Node*& prev)
{
	// Base case
	if (root == NULL)
		return;

    // go to left subtree
	inorder(root->left, prev);

    // join root with prev
	prev->left = NULL;
	prev->right = root;

	prev = root; // move prev forward

    // go to right subtree
	inorder(root->right, prev);
}

// Function to flatten binary tree using level order traversal
void flatten(Node* root)
{
	// Dummy Node
	Node* dummy = new Node(-1);

	// Pointer to previous element
	Node* prev = dummy;

	// Calling in-order traversal
	inorder(root, prev);

    // last node of list
	prev->left = NULL;
	prev->right = NULL;

    // update root
	root = dummy->right;

	// Delete dummy Node
	delete dummy;
}

// Driver code
int main()
{
	Node* root = new Node(5);
	root->left = new Node(3);
	root->right = new Node(7);
	root->left->left = new Node(2);
	root->left->right = new Node(4);
	root->right->left = new Node(6);
	root->right->right = new Node(8);

	// Calling required function
    flatten(root);
	print(root);

	return 0;
}
