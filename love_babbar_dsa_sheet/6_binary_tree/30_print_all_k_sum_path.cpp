#include <bits/stdc++.h>
using namespace std;

// binary tree node
struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

// utility function to print contents of a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
	for (int j = i; j < v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}

// Approach - TC O(N^2) - SC O(N)

// This function prints all paths that have sum k
void printKPathUtil(Node* root, vector<int> path, int k)
{
	// empty node
	if (!root)
		return;

	// add current node to the path
	path.push_back(root->data);

	// check if there's any k sum path in the left sub-tree.
	printKPathUtil(root->left, path, k);

	// check if there's any k sum path in the right sub-tree.
	printKPathUtil(root->right, path, k);

	// check if there's any k sum path that terminates at this node
	// Traverse the entire path as there can be negative elements too
	int sum = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		sum += path[j];

		// If path sum is k, print the path
		if (sum == k)
			printVector(path, j);
	}
}

// A wrapper over printKPathUtil()
void printKPath(Node* root, int k)
{
	vector<int> path;
	printKPathUtil(root, path, k);
}

int main()
{
    /* 
    Input : k = 5  

               1
            /     \
          3        -1
        /   \     /   \
       2     1   4     5                        
            /   / \     \                    
           1   1   2     6    
                       
    Output :
    3 2 
    3 1 1 
    1 3 1 
    4 1 
    1 -1 4 1 
    -1 4 2 
    5 
    1 -1 5  */

	Node* root = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(1);
	root->left->right->left = new Node(1);
	root->right = new Node(-1);
	root->right->left = new Node(4);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(2);

	int k = 5;
	printKPath(root, k);

	return 0;
}
