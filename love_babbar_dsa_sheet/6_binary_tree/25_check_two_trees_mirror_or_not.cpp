// C++ program to check if two trees are mirror of each other
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node
{
	int data;
	Node* left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

// Approach - TC O(N) SC O(N)
/* Given two trees, return true if they are mirror of each other */
bool areMirror(Node* a, Node* b)
{
	/* Base case : Both empty */
	if (!a && !b) return true;

	// If only one is empty
	if (!a || !b) return false;

	/* Both non-empty, compare them recursively Note that in recursive calls, we pass left
	of one tree and right of other tree */

    /* if left and right subtree both returns true and curr nodes data also match then we will also return true*/
	return a->data == b->data && areMirror(a->left, b->right) && areMirror(a->right, b->left);
}

int main()
{
	Node *a = new Node(1);
	Node *b = new Node(1);
	a->left = new Node(2);
	a->right = new Node(3);
	a->left->left = new Node(4);
	a->left->right = new Node(5);

	b->left = new Node(3);
	b->right = new Node(2);
	b->right->left = new Node(5);
	b->right->right = new Node(4);

	areMirror(a, b) ? cout << "Yes" : cout << "No";

	return 0;
}
