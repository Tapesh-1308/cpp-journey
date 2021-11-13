#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


//leetcode-124
int maxPath(Node* root, int& result){
    if(!root) return 0;

    int left = maxPath(root->left, result);
    int right = maxPath(root->right, result);

    int max_straight = max(max(left, right)+root->data, root->data);
    int max_casVal = max(max_straight, left+right+root->data);
    result = max(result, max_casVal);
    return max_straight;
}

int maxSum(Node* root){
    int result = INT_MIN;
    maxPath(root, result);
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(-3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    cout<<maxSum(root);
    return 0;
}