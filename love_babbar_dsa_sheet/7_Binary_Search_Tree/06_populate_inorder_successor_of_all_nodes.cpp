#include<bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left child and a pointer to right child */
class Node {
	public:
	int data;
	Node* left;
	Node* right;
    Node* next;
	
	/* Constructor that allocates a new Node with the given data and NULL left and right pointers. */
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
        next = NULL;
	}
};

// Approach - TC O(N) SC O(N)
/* Set next of all descendants of root by traversing them in reverse Inorder */
void populateNextRecur(Node* root, Node* &next)
{

    // First set the next pointer in right subtree
    populateNextRecur(root->right, next);

    // Set the next as previously visited
    // node in reverse Inorder
    root->next = next;

    // Change the prev for subsequent node
    next = root;

    // Finally, set the next pointer in left subtree
    populateNextRecur(root->left, next);
}

// A wrapper over populateNextRecur
void populateNext(Node* root)
{
    // The first visited node will be the rightmost node
    // next of the rightmost node will be NULL
    Node* next = NULL;
 
    populateNextRecur(root, next);
}

int main()
{

	/* Constructed binary tree is
			 10
			/  \
		   8   12
		  /
	     3
	*/
	Node* root = new Node(10);
	root->left = new Node(8);
	root->right = new Node(12);
	root->left->left = new Node(3);

	// Populates nextRight pointer in all nodes
	populateNext(root);

	// Let us see the populated values
	Node* ptr = root->left->left;
	while (ptr) {
		// -1 is printed if there is no successor
		cout << "Next of " << ptr->data << " is "
			<< (ptr->next ? ptr->next->data : -1) << endl;
		ptr = ptr->next;
	}

	return 0;
}

