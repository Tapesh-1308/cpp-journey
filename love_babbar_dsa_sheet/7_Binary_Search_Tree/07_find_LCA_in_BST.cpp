// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* left, *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

/* Function to find LCA of n1 and n2. The function assumes that both n1 and n2 are present in BST */

// Approach - Recursive - TC O(H) SC O(H)
Node *lca(Node* root, int n1, int n2)
{
	if (!root) return NULL;

	// If both n1 and n2 are smaller than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	// If both n1 and n2 are greater than root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

    // case when current root->data is matching with either n1 or n2, or if one is smaller and one is larger
    // then current root is LCA
	return root;
}

// Approach - Iterative - TC O(H) SC O(1)
Node *lca(Node* root, int n1, int n2)
{
    while (root)
    {
        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;
 
        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
 
        // case when current root->data is matching with either n1 or n2, or if one is smaller and one is larger
        // then current root is LCA
        else break;
    }
    return root; // contains LCA
}
 

int main()
{
	// Let us construct the BST
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(4);
	root->left->right = new Node(12);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);

	int n1 = 10, n2 = 14;
	Node *t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data <<endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
	return 0;
}