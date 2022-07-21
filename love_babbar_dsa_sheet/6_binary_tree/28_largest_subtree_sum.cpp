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

// Time Complexity: O(n), where n is number of nodes. 
// Auxiliary Space: O(n), function call stack size. 

// Helper function to find largest subtree sum recursively.
int solve(Node* root, int& ans)
{
    // If current node is null then return 0.
    if (!root)     
        return 0;
      
    // Caculate subtree sum
    int currSum = root->data +  solve(root->left, ans) + solve(root->right, ans);
  
    // Update answer if current subtree sum is greater than answer so far.
    ans = max(ans, currSum);
  
    // Return current subtree sum to its parent node.
    return currSum;
}
  
// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
    // If tree does not exist, then answer is 0.
    if (!root)     
        return 0;
      
    // Variable to store maximum subtree sum.
    int ans = INT_MIN;
  
    // Call to recursive function to find maximum subtree sum.
    solve(root, ans);
  
    return ans;
}

int main()
{


	// binary tree formation
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
  
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
  
    cout << findLargestSubtreeSum(root);

	return 0;
}
