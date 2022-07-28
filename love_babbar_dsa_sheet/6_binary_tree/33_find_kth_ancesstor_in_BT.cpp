#include <bits/stdc++.h>
using namespace std;

// Structure of Tree
struct Node {
	int data;
	Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }

};

// Approach #1 - By finding path - TC O(N) SC O(2N) Stack Space + Data Structure Space

// Function to find the path from root to the target Node
bool findPath(Node* root, int key, vector<int>& path)
{
	if (root == NULL)
		return false;

	// Add current Node to the path
	path.push_back(root->data);

	// If current Node is the target Node
	if (root->data == key)
		return true;

	// If the target Node exists in
	// the left or the right sub-tree
	if (findPath(root->left, key, path) || findPath(root->right, key, path))
		return true;

	// Remove the last inserted Node as
	// it is not a part of the path
	// from root to target
	path.pop_back();
	return false;
}

int kthAncestor(Node* root, int k, int target) {
    // Vector to store the path from
	// root to the given Node
	vector<int> path;

	// Find the path from root to the target Node
	findPath(root, target, path);

	// return the Kth ancestor, if k is out range return -1
    // Kth ancestor in path is kth element from last
    return path.size() <= k ? -1 : path[path.size()-k-1];
}

// Approach #2 - Without Using Extra Space - TC O(N) SC O(N)

int kthAncestorUtil(Node *root, int &k, int target) {
    if(!root) return -1; // Base case : root is null
    
    // if we found the target return from here
    if(root->data == target) return root->data;
    
    // else search in left and right subtree 
    int left = kthAncestorUtil(root->left, k, target);
    int right = kthAncestorUtil(root->right, k, target);
    
    // if we found target in left subtree and not found in right subtree
    if(left != -1 && right == -1) {
        k--; // decrement k 

        // if we are on kth ancestor return it else return left ans
        if(k==0) return root->data;
        return left;
    }

    // if we found target in right subtree and not found in left subtree
    if(right != -1 && left == -1) {
        k--; // decrement k

        // if we are on kth ancestor return it else return right ans
        if(k==0) return root->data;
        return right;
    }
    
    // if target not found in both left and right subtree return -1
    return -1;
}

int kthAncestor(Node* root, int k, int target) {
    // find the kth ancestor using this utility function
    int ans = kthAncestorUtil(root, k, target);

    // if ans we get is the same as targt, means k is too large to find
    if(ans == target) return -1;

    // else return ans
    return ans;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
  
    int k = 2;
    int target = 5;
 
    // print kth ancestor of given node
    cout<<kthAncestor(root,k,target);

    return 0;
}
