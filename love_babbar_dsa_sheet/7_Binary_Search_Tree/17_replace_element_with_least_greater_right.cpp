// C++ program to replace every element with the least greater element on its right
#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Using BST - TC O(nlogn) SC O(n), worst case TC O(n^2)

// A binary Tree node
struct Node {
	int data;
	Node *left, *right;
};

// A utility function to create a new BST node
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;

	return temp;
}

/* A utility function to insert a new node with given data in BST and find its successor */
Node* insert(Node* node, int data, Node*& succ)
{
	
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return node = newNode(data);

	// If key is smaller than root's key, go to left
	// subtree and set successor as current node
	if (data < node->data) {
		succ = node;
		node->left = insert(node->left, data, succ);
	}

	// go to right subtree
	else if (data >= node->data)
		node->right = insert(node->right, data, succ);
	return node;
}

// Function to replace every element with the least greater element on its right
void replace(int arr[], int n)
{
	Node* root = NULL;

	// start from right to left
	for (int i = n - 1; i >= 0; i--) {
		Node* succ = NULL;

		// insert current element into BST and
		// find its inorder successor
		root = insert(root, arr[i], succ);

		// replace element by its inorder successor in BST
		if (succ)
			arr[i] = succ->data;
		else // No inorder successor
			arr[i] = -1;
	}
}

// Approach 2 - Using Set - TC O(nlogn) SC O(n)
void repace(int arr[], int n) {
    // create a set to store elements in sorted order
    set<int> s;  

    // traverse array from last
    for(int i=n-1; i>=0; i--) {
        s.insert(arr[i]); // insert curr element in set

        // for every inserted element, find its upper_bound,  
        // if fount replace arr[i] with that, 
        // otherwise update arr[1] with -1
        auto it = s.upper_bound(arr[i]);
        arr[i] = it == s.end() ? -1 : *it;
    }
}

int main()
{
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);

	replace(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
