// Count pairs from two BSTs whose sum is equal to a given value x
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node {
	int data;
	Node* left = NULL, *right = NULL;
    Node(int val) : data(val) {}
};

// Approach - TC O(n+m) SC O(h1+h2)

// function to count pairs from two BSTs
// whose sum is equal to a given value x
int countPairs(Node* root1, Node* root2, int x)
{
	// if either of the tree is empty
	if (!root1 || !root2) return 0;

	// stack 'st1' used for the inorder traversal of BST 1
	// stack 'st2' used for the reverse inorder traversal of BST 2
	stack<Node*> st1, st2;
	Node *top1, *top2;

	int count = 0;

	// the loop will break when either of two traversals gets completed
	while (1) {

		// to find next node in inorder traversal of BST 1
		while (root1) {
			st1.push(root1);
			root1 = root1->left;
		}

		// to find next node in reverse inorder traversal of BST 2
		while (root2) {
			st2.push(root2);
			root2 = root2->right;
		}

		// if either gets empty then corresponding tree traversal is completed
		if (st1.empty() || st2.empty())
			break;

		top1 = st1.top();
		top2 = st2.top();

		// if the sum of the node's is equal to 'x'
		if ((top1->data + top2->data) == x) {
			// increment count
			count++;

			// pop nodes from the respective stacks
			st1.pop();
			st2.pop();

			// insert next possible node in the respective stacks
			root1 = top1->right;
			root2 = top2->left;
		}

		// move to next possible node in the inorder traversal of BST 1
		else if ((top1->data + top2->data) < x) {
			st1.pop();
			root1 = top1->right;
		}

		// move to next possible node in the reverse inorder traversal of BST 2
		else {
			st2.pop();
			root2 = top2->left;
		}
	}

	// required count of pairs
	return count;
}

// Driver program to test above
int main()
{
	// formation of BST 1
    /*     5     */
    /*	 /   \   */
    /*	3	  7  */
    /* / \   / \ */
    /* 2  4 6   8 */    

	Node* root1 = new Node(5); 
	root1->left = new Node(3); 
	root1->right = new Node(7); 
	root1->left->left = new Node(2);
	root1->left->right = new Node(4); 
	root1->right->left = new Node(6);
	root1->right->right = new Node(8);

	// formation of BST 2
    /*     10
        /  \
       6    15
      / \  /  \
     3  8 11  18 */
	Node* root2 = new Node(10); 
	root2->left = new Node(6); 
	root2->right = new Node(15);
	root2->left->left = new Node(3); 
	root2->left->right = new Node(8);
	root2->right->left = new Node(11);
	root2->right->right = new Node(18);

	int x = 16;
	cout << "Pairs = " << countPairs(root1, root2, x);

	return 0;
}
