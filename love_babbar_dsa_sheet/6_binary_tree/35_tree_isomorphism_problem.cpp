#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left and right children */
struct Node
{
	int data;
	Node* left;
	Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Time Complexity: O(min(m,n))
// Space Complexity: O(min(m, n ))

bool isIsomorphic(Node* n1, Node *n2) {
    // Both roots are NULL, trees isomorphic by definition
    if (!n1 && !n2)
        return true;

    // Exactly one of the n1 and n2 is NULL, trees not isomorphic
    if (!n1 || !n2)
        return false;

    // if data not match
    if (n1->data != n2->data)
        return false;


    // There are two possible cases for n1 and n2 to be isomorphic

    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped", then case1 will be true.
    bool case1 = isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right);

    // Case 2: The subtrees rooted at these nodes have been "Flipped", then case2 will be true.
    bool case2 = isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left);
    
    // return true if any of case is true 
    return case1 || case2;
    
}

int main()
{
	Node *n1 = new Node(1);
	n1->left = new Node(2);
	n1->right = new Node(3);
	n1->left->left = new Node(4);
	n1->left->right = new Node(5);
	n1->right->left = new Node(6);
	n1->left->right->left = new Node(7);
	n1->left->right->right = new Node(8);

	Node *n2 = new Node(1);
	n2->left = new Node(3);
	n2->right = new Node(2);
	n2->right->left = new Node(4);
	n2->right->right = new Node(5);
	n2->left->right = new Node(6);
	n2->right->right->left = new Node(8);
	n2->right->right->right = new Node(7);

    cout << (isIsomorphic(n1, n2) ? "Yes" : "NO") << endl;
 
	return 0;
}
