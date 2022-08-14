#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class Node
{
	public:
	int data;
	Node* left;
	Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

//--------------------------------------------------- Approach #1 ---------------------------------------------------//

// Using Array - TC O(M+N) SC O(M+N)

// A utility function to merge two sorted arrays into one
vector<int> merge(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
	// mergedArris going to contain result
	vector<int> mergedArr(m + n);
	int i = 0, j = 0, k = 0;

	// Traverse through both arrays
	while (i < m && j < n)
	{
		// Pick the smaller element and put it in mergedArr
		if (arr1[i] < arr2[j])
			mergedArr[k++] = arr1[i++];

		else
			mergedArr[k++] = arr2[j++];
		
	}

	// If there are more elements in first array
	while (i < m)
		mergedArr[k++] = arr1[i++];
	

	// If there are more elements in second array
	while (j < n)
		mergedArr[k++] = arr2[j++];

	return mergedArr;
}

// A helper function that stores inorder
// traversal of a tree in inorder array
void storeInorder(Node* node, vector<int> &inorder)
{
	if (!node)
		return;

	/* first recur on left child */
	storeInorder(node->left, inorder);

	inorder.push_back(node->data);

	/* now recur on right child */
	storeInorder(node->right, inorder);
}

/* A function that constructs Balanced Binary Search Tree from a sorted array
See https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
Node* sortedArrayToBST(vector<int> &arr, int start, int end)
{
	/* Base Case */
	if (start > end)
	    return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	Node* root = new Node(arr[mid]);

	/* Recursively construct the left subtree and make it left child of root */
	root->left = sortedArrayToBST(arr, start, mid-1);

	/* Recursively construct the right subtree and make it right child of root */
	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}

/* This function merges two balanced BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively */
Node* mergeTrees(Node* root1, Node* root2, int m, int n)
{
	// Store inorder traversal of first tree in an array arr1
	vector<int> arr1;
	storeInorder(root1, arr1);

	// Store inorder traversal of second tree in another array arr2
	vector<int> arr2;
	storeInorder(root2, arr2);

	// Merge the two sorted array into one
	vector<int> mergedArr = merge(arr1, arr2, m, n);

	// Construct a tree from the merged array and return root of the tree
	return sortedArrayToBST (mergedArr, 0, m + n - 1);
}

// --------------------------------------------------- Approach #2 --------------------------------------------------- //

// Using Linked List (inplace merge)
// TC O(M+N) SC O(h1 + h2), h -> height of tree

/* Function to convert bst to doubli linked list, takes root of the tree and head of list */
void bstTodll(Node* root, Node* &head){
    // base case
    if(!root) return;

    /* convert right subtree recursively*/
    bstTodll(root->right, head);
    
    // connect root with right subtree and right subtree with root
    root->right = head;
    if(head) head->left = root;

    // update head
    head = root;
    
    /* convert left subtree recursively*/
    bstTodll(root->left, head);
}

/* Function to merge two sorted linked list, takes the head of both linked list and return the head of merge list*/
Node* mergeLinkedList(Node* head1, Node* head2){

    /*Create head and tail for result list*/
    Node* head = NULL;
    Node* tail = NULL;
    
    /* traverse both to merge */
    while(head1 && head2){
        /* if head1 is smaller than head2, join head1 with resultant list*/
        if(head1->data < head2->data){
            // if first node in list
            if(!head) 
                head = head1;
            else {
				// else join with tail 
				tail->right = head1;
                head1->left = tail;
            }

			// move tail and head forward
            tail = head1;
            head1 = head1->right;
        }
        /* if head2 is smaller, join head2*/
        else {
            // if first node
            if(!head) 
                head = head2;
            else {
				tail->right = head2;
                head2->left = tail;
            }

            tail = head2;
            head2 = head2->right;
        }
    }

    /* if more nodes in first list*/
    while(head1){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    
    /* if more nodes in second list */
    while(head2){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    
    /* return the head of merged list */
    return head;
} 


/* function to convert list to bst, takes pointer of input list*/
Node *sortedListToBST(Node* &head, int n){
    // base case - no element left or head is null
    if(n<=0 || !head) 
        return NULL;

    /* make first half of list a left subtree */
    Node *left = sortedListToBST(head, n/2);

    /* root will be the middle node. join left subtree with root and move head forward */
    Node *root = head;
    root->left = left;
    head = head->right;

    /* make second half of list - right subtree */
    root->right = sortedListToBST(head, n-(n/2)-1); 

    /* return the tree */
    return root;
}

/* This function merges two balanced BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively */
Node* mergeTrees(Node* root1, Node* root2, int m, int n)
{
	// Convert BSTs into sorted Doubly Linked Lists

    // first bst
    Node* head1 = NULL; 
    bstTodll(root1, head1);
    head1->left = NULL;

    // second bst
    Node* head2 = NULL; 
    bstTodll(root2, head2);
    head2->left = NULL;

	// Merge the two sorted lists into one
	Node* head = mergeLinkedList(head1, head2);

	// Construct a tree from the merged linked list and return root of the tree
	return sortedListToBST(head, m + n);
}

// A utility function to print inorder traversal of a given binary tree
void printInorder(Node* node)
{
	if (!node)
		return;

	/* first recur on left child */
	printInorder(node->left);

	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Driver code*/
int main()
{
	/* Create following tree as first balanced BST
		100
		/ \
	  50 300
	 / \
	20 70   */
	        
	Node* root1 = new Node(100);
	root1->left	 = new Node(50);
	root1->right = new Node(300);
	root1->left->left = new Node(20);
	root1->left->right = new Node(70);

	/* Create following tree as second balanced BST
		 80
		/ \
	   40 120
	*/
	Node* root2 = new Node(80);
	root2->left	 = new Node(40);
	root2->right = new Node(120);

	Node* mergedTree = mergeTrees(root1, root2, 5, 3);

	cout << "Following is Inorder traversal of the merged tree \n";
	printInorder(mergedTree);

	return 0;
}
