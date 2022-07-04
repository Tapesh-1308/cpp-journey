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

    return max(lh, rh) + 1; // add curr node with maxium of left height and right height and return 
}

// Approach - 1 Naive Approach - TC O(N^2) SC O(N)
int diameter(Node* root) {
    // base case where tree is empty
    if(!root) return 0;

    // get the height of left and right sub-trees
    int left_height = heightBT(root->left);
    int right_height = heightBT(root->right);

    // get the diameter of left and right sub-trees
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1 (curr diameter)

    int curr_diameter = left_height + right_height + 1;

    return max(curr_diameter, max(left_diameter, right_diameter));
}

//Approach - 2 Optimized - TC O(N) SC O(N) 

pair<int, int> solve(Node* root) {
    /* pair.first -> maximum diameter
    pair.second -> height */

    // base case
    if(!root) return {0,0};

    // calculate left and right diameter and height together
    auto left = solve(root->left);
    auto right = solve(root->right);

    // extract left and right diameter
    int left_diameter = left.first;
    int right_diameter = right.first;

    // current diameter will be leftheight + rightheight + 1
    int curr_diameter = left.second + right.second + 1;


    pair<int, int> ans;

    // new diameter
    ans.first = max(curr_diameter, max(left_diameter, right_diameter));
    // new height
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root) {
    // return only diameter 
    return solve(root).first;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    // Function Call
    cout << "Diameter of the given binary tree is " <<
        diameter(root);
    return 0;
}