// C++ program to convert a tree into its sum tree
#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
class Node
{
	public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Approach - TC O(N) SC O(N)

// Convert a given tree to a tree where every Node contains sum of values of nodes in left and right subtrees in the original tree
int toSumTreeUtil(Node *root)
{
	// Base case
	if(!root)
	    return 0;

    // Recursively call for left and right subtrees
    int left_sum = toSumTreeUtil(root->left);
    int right_sum = toSumTreeUtil(root->right);

    // Store the curr value
    int curr_data = root->data;
    // change the node data that is the sum of leftsubtree and rightsubtree
    root->data = left_sum + right_sum;

    // Return the sum of root->data(values of nodes in left and right subtrees) and curr_data
    return curr_data + root->data;
}

void toSumTree(Node* root) {
    // Call to utility function to convert tree to sumtree
    toSumTreeUtil(root);
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder(Node* root)
{
	if (root == NULL)
		return;
	printInorder(root->left);
	cout<<root->data << " ";
	printInorder(root->right);
}


/* Driver code */
int main()
{
	Node *root = NULL;	
    
	root = new Node(10);
	root->left = new Node(-2);
	root->right = new Node(6);
	root->left->left = new Node(8);
	root->left->right = new Node(-4);
	root->right->left = new Node(7);
	root->right->right = new Node(5);
	
	toSumTree(root);
	
	// Print inorder traversal of the converted tree
	printInorder(root);

	return 0;
}