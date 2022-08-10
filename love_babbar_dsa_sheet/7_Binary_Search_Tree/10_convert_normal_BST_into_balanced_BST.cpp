// C++ program to convert an unbalanced BST to a balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left, *right;
};

// Approach - TC O(N) SC O(N)

/* This function traverse the BST and stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
	// Base case
	if (!root)
		return;

	// Store nodes in Inorder (which is sorted order for BST)
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node* > &nodes, int start, int end)
{
	// base case
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	Node *root = nodes[mid];

	/* Using index in Inorder traversal, construct left and right subtress */
	root->left = buildTreeUtil(nodes, start, mid-1); // left subtree - [start, mid)
	root->right = buildTreeUtil(nodes, mid+1, end); // right subtree - (mid, end]

    /* return the converted tree */
	return root;
}

// This functions converts an unbalanced BST to a balanced BST
Node* buildTree(Node* root)
{
	// Store nodes of given BST in sorted order (inorder)
	vector<Node *> nodes;
	storeBSTNodes(root, nodes);

	// Constructs BST from nodes[]
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n-1);
}

// Utility function to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

// Driver program
int main()
{
	/* Constructed skewed binary tree is
				10
			   /
			  8
			 /
			7
		   /
		  6
		 /
		5 */

	Node* root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(7);
	root->left->left->left = newNode(6);
	root->left->left->left->left = newNode(5);

	root = buildTree(root);

	cout << "Preorder traversal of balanced BST is : \n";
	preOrder(root);

	return 0;
}
