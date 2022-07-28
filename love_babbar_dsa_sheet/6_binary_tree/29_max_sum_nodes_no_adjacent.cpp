/* Maximum sum of nodes in Binary tree such that no two are adjacent */
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Approach - 1 Using Pair TC O(N) SC O(N)

/* Utility function to find non adjacent max sum nodes */
pair<int, int> maxSumHelper(Node *root)
{
    // Base Case
	if (!root) {
		return {0, 0};
	}
    
    // recur for left and right subtree
	auto left_sum = maxSumHelper(root->left);
	auto right_sum = maxSumHelper(root->right);

    // store curr included or excluded sum
	pair<int, int> ans;
 
	// ans.first -> sum if current node is included
    // then sum will be curr node + excluded leftsum + excluded right sum
	ans.first = left_sum.second + right_sum.second + root->data;

    // ans.second -> sum if current node is excluded
    // then sum of included or excluded (whichever is maximum will included) left_sum ans right_sum
	ans.second = max(left_sum.first, left_sum.second) + max(right_sum.first, right_sum.second);

	return ans;
}

int maxSum(Node *root)
{
    // call the utility function to get max sum
	pair<int, int> res = maxSumHelper(root);

    // return max of included and excluded  
	return max(res.first, res.second);
}

// Approach - 2 Using hashmap/DP - TC O(N) SC O(N) 

// declare map /dp array as global
unordered_map<Node*, int> umap;
int maxSum(Node* root) {
    // base case
    if (!root) return 0;
 
    // if the max sum from the node is already in map,return the value
    if (umap[root]) return umap[root];
 
    // if the current node(root) is included in result then find maximum sum
    int inc = root->data;
 
    // if left of node exists, add their grandchildren
    if (root->left) 
        inc += maxSum(root->left->left) + maxSum(root->left->right);
    
    // if right of node exist,add their grandchildren
    if (root->right) 
        inc += maxSum(root->right->left) + maxSum(root->right->right);
    
 
    // if the current node(root) is excluded, find the maximum sum
    int ex = maxSum(root->left) + maxSum(root->right);
 
    // store the maximum of including & excluding the node in map
    return umap[root] = max(inc, ex);
}

int main()
{
	Node *root= new Node(10);
	root->left= new Node(1);
	root->left->left= new Node(2);
	root->left->left->left= new Node(1);
	root->left->right= new Node(3);
	root->left->right->left= new Node(4);
	root->left->right->right= new Node(5);
	cout << maxSum(root);
	return 0;
}
