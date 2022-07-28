// C++ Program for Lowest Common Ancestor in a Binary Tree
#include<bits/stdc++.h>
using namespace std;

// A Binary Tree node
struct Node
{
	int data;
	Node *left, *right;

	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(Node *root, vector<Node* > &path, int k)
{
	// base case
	if (root == NULL) return false;

	// Store this node in path vector. The node will be removed if not in path from root to k
	path.push_back(root);

	// See if the k is same as root's data
	if (root->data == k) return true;

	// Check if k is found in left or right sub-tree
	if ( (root->left && findPath(root->left, path, k)) ||
		(root->right && findPath(root->right, path, k)) )
		return true;

	// If not present in subtree rooted with root, remove root from path[] and return false
	path.pop_back();

	return false;
}

// Approach - 1 By finding path TC O(3 * N) SC O(2*N + 2*N) // to store path + auxillary stack space

// Returns LCA if node n1, n2 are present in the given binary tree, otherwise return -1
Node* findLCA(Node *root, int n1, int n2)
{
	// to store paths to n1 and n2 from the root
	vector<Node*> path1, path2;

	// Find paths from root to n1 and root to n2. If either n1 or n2 is not present, return -1
	if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
		return NULL;

	/* Compare the paths to get the first different value */
	int i;
	for (i = 0; i < path1.size() && i < path2.size() ; i++)
		if (path1[i]->data != path2[i]->data)
			break;

	// return the lowest common ancesstor
	return path1[i-1];
}

// Approach - 2 Using single Traversal TC O(N) SC O(N)

// This function returns pointer to LCA of two given values n1 and n2.
// This function assumes that n1 and n2 are present in Binary Tree
Node *findLCA(Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's data, report
    // the presence by returning root (Note that if a data is
    // ancestor of other, then the ancestor data becomes LCA
    if (root->data == n1 || root->data == n2)
        return root;
 
    // Look for keys in left and right subtrees
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one data
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;

	return 0;
}
