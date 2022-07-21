// C++ implementation to find the sum of nodes on the longest path from root to leaf node
#include <bits/stdc++.h>

using namespace std;

// Node of a binary tree
struct Node {
	int data;
	Node* left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Approach - 1  Recursion - TC O(N) SC O(N)  

// function to find the sum of nodes on the longest path from root to leaf node
void sumOfLongRootToLeafPathUtil(Node* root, int sum, int len, int& maxLen, int& maxSum)
{
	// if true, then we have traversed a root to leaf path
	if (!root) {
		// update maximum length and maximum sum according to the given conditions
		if (maxLen < len) {
			maxLen = len;
			maxSum = sum;
		} 
        else if (maxLen == len)
			maxSum = max(maxSum , sum);
		
        return;
	}

	// recur for left subtree, update sum and length
	sumOfLongRootToLeafPathUtil(root->left, sum + root->data, len + 1, maxLen, maxSum);

	// recur for right subtree, update sum and length
	sumOfLongRootToLeafPathUtil(root->right, sum + root->data, len + 1, maxLen, maxSum);
}

// utility function to find the sum of nodes on the longest path from root to leaf node
int sumOfLongRootToLeafPath(Node* root)
{
	// if tree is NULL, then sum is 0
	if (!root)
		return 0;

	int maxSum = INT_MIN, maxLen = 0;

	// finding the maximum sum 'maxSum' for the maximum length root to leaf path
	sumOfLongRootToLeafPathUtil(root, 0, 0, maxLen, maxSum);

	// required maximum sum
	return maxSum;
}

// Approach - 2 Iterative - TC O(N) SC O(N)

int sumOfLongRootToLeafPath(Node* root)
{
    /* maxSum stores maximum sum so far in the path maxLen stores maximum level so far */
    int maxSum = root->data, maxLen = 0;

    /* queue to implement level order traversal */
    /* Each element variable stores the current Node, sum in the path, it's level */
    queue<pair<Node*, pair<int, int> > > q;

    /* push the root element*/
    q.push({root, {root->data, 0}});


    /* do level order traversal on the tree*/
    while(!q.empty()){

        auto front = q.front();
        q.pop();
 
        // Get the 3 required elements
        Node* curr = front.first;
        int sum = front.second.first;
        int len = front.second.second;

        /* if the level of current front element is greater than the maxLen so far then update maxSum*/
        if(len > maxLen){
            maxSum = sum;
            maxLen = len;
        }
        /* if another path completes then update if the sum is greater than the previous path of same height*/
        else if(len == maxLen)
            maxSum = max(maxSum, sum);

        /* push the left element if exists with updated sum and length */  
        if(curr->left){
            q.push({curr->left, {curr->left->data + sum, len+1}});
        }
        /*push the right element if exists with updated sum and length */
        if(curr->right){
            q.push({curr->right, {curr->right->data + sum, len+1}});
        }

    }

    /*return the answer*/
    return maxSum;
}

int main()
{
     
 /* * Input : Binary tree:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
    
    * Output : 13 */

	// binary tree formation
	Node* root = new Node(4);	
	root->left = new Node(2);	
	root->right = new Node(5);	 
    root->left->left = new Node(7); 
	root->left->right = new Node(1); 
	root->right->left = new Node(2);
	root->right->right = new Node(3); 
	root->left->right->left = new Node(6);

	cout << "Sum = " << sumOfLongRootToLeafPath(root);

	return 0;
}
