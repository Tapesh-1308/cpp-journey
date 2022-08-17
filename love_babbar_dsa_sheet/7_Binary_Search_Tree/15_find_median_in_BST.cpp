/* C++ program to find the median of BST in O(n) time and O(1) space*/
#include<bits/stdc++.h>
using namespace std;

/* A binary search tree Node has data, pointer
to left child and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with given key in BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Function to count nodes in a binary search tree */
int countNodes(struct Node *root)
{

    // base case
    if(!root)
        return 0;

    // recursive call to left child and right child and
    // add the result of these with 1 ( 1 for counting the root)
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Approach - TC O(N) SC O(H)

// utility function to find n/2th node (n/2)+1 th node in prev and curr
void findMedianUtil(Node* root, Node* &prev, Node* &curr, int &count, int k) {
    // base case
    if (!root) return;

    // search in left subtree
    findMedianUtil(root->left, prev, curr, count, k);

    // process only if curr not found
    if(count != k) {
        count++; // increment count

        // if we are on kth node update curr else update prev
        if (count == k) curr = root;
        else prev = root;
    }

    // search in right subtree
    findMedianUtil(root->right, prev, curr, count, k);    
}

/* Function to find median in O(n) time and O(1) space */
float findMedian(struct Node *root)
{
    int n = countNodes(root); // count the number of nodes

    // count tells number of nodes processed so far, k is the index of node to find
    int count = 0, k = (n/2)+1;

    // curr stores (n/2)+1 th node and prev stores n/2 th node
    Node *curr = NULL, *prev = NULL;

    // this function find 2 nodes -> prev and curr
    findMedianUtil(root, prev, curr, count, k);
    
    // if count is odd return curr (n/2 + 1 th node) 
    return n&1 ? (curr->data) * 1.0 
               : (curr->data + prev->data) / 2.0; // else return curr + prev/2 -> (n/2 + n/2+1)/2
}

int main()
{

	/* Let us create following BST
			  50
			/	 \
		  30	  70
		 /  \    /  \
		20  40  60   80 */

	struct Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	cout << "Median of BST is " << findMedian(root);
	return 0;
}
