/* Check if a binary tree is subtree of another binary tree */

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

// Approach - TC O(N) SC O(N)

/* Utility function generate strings of subtrees */
string solve(Node* root, unordered_map<string, int> &um) {
    // base case : if root is null return a string with any unique value (helps to resolve edge case)
    if(!root) return "$";
    
    // create an empty string
    string s = "";

    // if we have a leaf node, return its data in string 
    // Note : we are not storing leaf node generate string in map
    if(!root->left && !root->right)
        return s + to_string(root->data);
        
    // current string will be curr node + string of left subtree + string of right subtree
    s += to_string(root->data) + solve(root->left, um) + solve(root->right, um);
    
    um[s] ++; // store the generated string in unordered_map
    
    return s; // return string for recursive calls
}

int duplicate_subtree(Node *root) {
    // create a unordered map to store generated string with there frequency 
    unordered_map<string, int> um;
    
    // fill unordered map + generate strings 
    solve(root, um);
    
    // check in map if we get same string 2 or more time (that means duplicate subtree exist)
    for(auto i: um)
        if(i.second >= 2) return true;
        
    // return false if no duplicates found
    return false;
}

int main(){
    /*
    Input :  Binary Tree 
               1
             /    \ 
           2        3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
    Output : Yes
    */

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(2);

    root->right->right->left= new Node(4);
    root->right->right->right = new Node(5);


    if(duplicate_subtree(root)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}