#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


/* Utility function to print preorder of binary tree */
void preOrder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
// Approach 1 - Recursive - TC O(N^2) SC O(N)

// function to return the index of close parenthesis
int findIndex(string str, int si, int ei)
{
    // Base Case
	if (si > ei)
		return -1;

	// Inbuilt stack
	stack<char> st;

	for (int i = si; i <= ei; i++) {

		// if open parenthesis, push it
		if (str[i] == '(')
			st.push(str[i]);

		// if close parenthesis
		else if (str[i] == ')') {
            // remove it
			if (st.top() == '(') {
				st.pop();

				// if stack is empty, this is the required index
				if (st.empty())
					return i;
			}
		}
	}
	// if not found return -1
	return -1;
}

// Utility function to construct binary tree from given string
Node* treeFromStringUtil(string str, int si, int ei)
{
	// Base case, when starting index cross ending index
	if (si > ei)
		return NULL;

	// create new root
	Node* root = new Node(str[si] - '0');
	int index = -1; // store the index of ending bracket

	// if next char is '(' find the index of its complement ')'
	if (si + 1 <= ei && str[si + 1] == '(')
		index = findIndex(str, si + 1, ei);

	// if index found
	if (index != -1) {
		// call for left subtree
		root->left = treeFromStringUtil(str, si + 2, index - 1);

		// call for right subtree
		root->right = treeFromStringUtil(str, index + 2, ei - 1);
	}
	return root;
}

Node* treeFromString(string str) {
    // call utility function (string, starting index, ending index)
    return treeFromStringUtil(str, 0, str.length() - 1);
}

// Approach 2 - Iterative - TC O(N) SC O(N)
Node* treeFromString(string str) {
    // First character is the root of the tree
    Node* root = new Node(str[0] - '0');
 
    // Stack used to store the previous root elements
    stack<Node*> st;
 
    // Iterate over remaining characters
    for (int i = 1; i < str.length(); i++) {
 
        // If current character is '('
        if (str[i] == '(') {
            // Push root into stack
            st.push(root);
        }
 
        // If current character is ')'
        else if (str[i] == ')') {
            // Make root the top most element in the stack
            root = st.top();
            // Remove the top node
            st.pop();
        }
 
        // If current character is a number
        else {
 
            // If left is null, then put the new node to the left and move to the left of the root
            if (!root->left) {
                Node* left = new Node(str[i] - '0');
                root->left = left;
                root = root->left;
            }
 
            // Otherwise, if right is null, then put the new node to the right and move to the right of the root
            else if (!root->right) {
                Node* right = new Node(str[i] - '0');
                root->right = right;
                root = root->right;
            }
        }
    }
 
    // Return the root
    return root;
}

// Driver Code
int main()
{
	string str = "4(2(3)(1))(6(5))";
	Node* root = treeFromString(str);
	preOrder(root);
}
