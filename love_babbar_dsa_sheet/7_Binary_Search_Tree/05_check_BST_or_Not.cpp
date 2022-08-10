#include<bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left child and a pointer to right child */
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	/* Constructor that allocates a new Node with the given data and NULL left and right pointers. */
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Approach - TC O(N) SC O(H)

/* Returns true if the given tree is a BST and its values are > min and < max. */
int isBSTUtil(Node* root, int min, int max) {
	/* an empty tree is BST */
	if (!root) return 1;
			
	/* false if this node violates the min/max constraint */
	if (root->data < min || root->data > max)
		return 0;
	
	/* otherwise check the subtrees recursively, tightening the min or max constraint */
	return
		isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max); 
}

/* Returns true if the given tree is a binary search tree */
int isBST(Node* root) {
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	
	if(isBST(root)) cout<<"Is BST";
	else cout<<"Not a BST";
		
	return 0;
}
