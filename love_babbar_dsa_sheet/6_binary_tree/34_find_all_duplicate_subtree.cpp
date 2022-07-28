#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node {
	int data;
	struct Node* left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Approach - TC O(N) SC (N)

string generateStrings(Node* root, unordered_map<string, int>& um, vector<Node*> &ans)
{
    // Base Case 
    if(!root) return "";

    // Create string in preorder fashion, use separator b/w node left and right subtree
    string s = "";
    s += to_string(root->data) + " " + generateStrings(root->left, um, ans) + " " + generateStrings(root->right, um, ans);

    // if generated string already present in map, means we are getting it again (duplicate)
    // so take it into account
    if(um[s] == 1) ans.push_back(root);

    // increment freq in map
    um[s] ++;

    // return generate string for recur call 
    return s;
}


vector<Node*> printAllDups(Node* root)
{
	unordered_map<string, int> um; // to strore {key : string -> value : frequency}
    vector<Node* > ans; // store root of duplicate subtree
	generateStrings(root, um, ans); // fill map and ans

    // return ans
    return ans;
}

/*Utility function to print preorder*/
void preorder(Node* root){
    if(!root){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
	Node* root = NULL;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(2);
	root->right->left->left = new Node(4);
	root->right->right = new Node(4);

	vector<Node* > res = printAllDups(root);

    for(int i=0; i<res.size(); i++){
        preorder(res[i]);
        cout << endl;
    }
	return 0;
}
