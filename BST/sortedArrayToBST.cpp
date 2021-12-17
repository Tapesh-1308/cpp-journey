//leetcode - 108
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* sortedArrayToBST_util(vector<int>& nums, int start, int end){
    if(start>end) return NULL;
    int mid = (start+end)/2;
    Node* root = new Node(nums[mid]);
    root->left = sortedArrayToBST_util(nums, start, mid-1);
    root->right = sortedArrayToBST_util(nums, mid+1, end);
    return root; 
}

Node* sortedArrayToBST(vector<int>& nums){
    int n = nums.size();
    Node* root = sortedArrayToBST_util(nums, 0, n-1);
    return root;    
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> nums = {10, 20, 30, 40, 50};
    Node* root = sortedArrayToBST(nums);
    preorder(root);
    return 0;
}