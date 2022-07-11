#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

/* Utility function to find the height of tree using recursion*/
int heightBT(Node* root) {
    if(!root) return 0;
    int lh = heightBT(root->left); // find left height
    int rh = heightBT(root->right); // find right height

    return max(lh, rh) + 1 ; // add curr node with maxium of left height and right height and return 
}

// Approach 1 Brute Force TC O(N^2) SC O(N)
bool isBalanced(Node* root) {
    if(!root) return 1; // Base Case

    // Calculate left and right subtree height
    int lh = heightBT(root->left);
    int rh = heightBT(root->right);

    // return true if height difference is not more than one and left and right subtree is also balanced
    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
        return 1;

    // if we reach here means trr is not balanced
    return 0;    
}


// Approach - 2 Optimized TC O(N) SC O(N)
pair<bool, int> isBalancedUtil(Node* root){
    // pair : {isBalanced, height} 
    if(!root) return {1, 0}; // base case return true with height 0
    
    // calculate left and right subtree 
    auto left = isBalancedUtil(root->left);
    auto right = isBalancedUtil(root->right);
    
    // check if left and right subtree diff is not more than one
    bool diff = abs(left.second - right.second)<=1;

    pair<bool, int> ans;
    
    // find the height 
    ans.second = max(left.second, right.second) + 1;
    
    // ans first will be true if if left subtree and right subtree is balanced and height diff is not more than one
    if(left.first && right.first && diff) 
        ans.first=1;
    // else and first will be false
    else 
        ans.first=0;

    // return pair
    return ans;
}

bool isBalanced(Node* root) {
    // return a pair, where first data contains true if trr is balanced and false if tree is not balanced
    return isBalancedUtil(root).first;
}

int main(){
    /* Constructed binary tree is
              1
            /   \
           2     3
          / \   /
         4   5 6
        /
       7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(7);
 
    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
 
    return 0;
}