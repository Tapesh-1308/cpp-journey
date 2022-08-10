#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Approach - Brute Force - TC O(N*H) SC O(H)
// insert node, general function
void insert(node* &root, int data) {
    if(!root) {
        root = newNode(data);
    }
    else if (root->data > data) insert(root->left, data);
    else  insert(root->right, data);
}

// The main function to construct BST from given preorder traversal.
node* constructTree(int pre[], int size)
{
    // call insert function for all elements of preorder input array
    node* root = NULL;
    for(int i=0; i<size; i++) {
        insert(root, pre[i]);
    }
    return root;
}

// Approach - Optimized - TC O(N) SC O(N)
// A recursive function to construct BST from pre[]. preIndex is used to keep track of index in pre[].
node* constructTreeUtil(int pre[], int &preIndex, int max, int size)
{
	// Base case -> if index is out of bound or curr element is not in range
	if (preIndex >= size || pre[preIndex] > max)
		return NULL;

    // Create node of current element and move index forward
	node* root = newNode(pre[preIndex++]);

    // construct left subtree -> maximum range will curr node for left nodes as it can't be greater than current node
    root->left = constructTreeUtil(pre, preIndex, root->data, size);

    // construct right subtree -> maximum range will curr node for left nodes as it can't be greater than current node
    root->right = constructTreeUtil(pre, preIndex, max, size);
    
    // return the constructed tree
    return root;
}

// The main function to construct BST from given preorder traversal.
// This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, preIndex, INT_MAX, size);
}

// A utility function to print inorder
// traversal of a Binary Tree
void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	// Function call
	node* root = constructTree(pre, size);

	cout << "Inorder traversal of the constructed tree: \n";
	printInorder(root);

	return 0;
}
