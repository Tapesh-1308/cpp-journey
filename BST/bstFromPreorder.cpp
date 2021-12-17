//leetcode - 1008
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

int constructBST(vector<int> &preorder, int n, int pos, Node* root, int min, int max){
    if(pos==n || preorder[pos]<min || preorder[pos]>max) return pos;
    if(preorder[pos]<root->data) {
        root->left = new Node(preorder[pos]);
        pos++;
        pos = constructBST(preorder, n, pos, root->left, min, root->data-1);
    }
    if(pos==n || preorder[pos]<min || preorder[pos]>max) return pos;
    root->right = new Node(preorder[pos]);
    pos++;
    pos = constructBST(preorder, n, pos, root->right, root->data+1, max);
    return pos;
}

Node* bstFromPreorder(vector<int> preorder){
    int n = preorder.size();
    if(n==0) return NULL;
    Node* root = new Node(preorder[0]);
    if(n==1) return root;
    constructBST(preorder, n, 1, root, INT_MIN, INT_MAX);
    return root;
}

void preorderPrint(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    // Node *root = new Node(4);
    // root->left = new Node(2);
    // root->right = new Node(5);
    // root->left->left = new Node(1);
    // root->left->right = new Node(3);
    // root->right->right = new Node(6);
    vector<int> preorder = {9,8,7,6,5,4,3,2,1};
    Node* root = bstFromPreorder(preorder);
    preorderPrint(root);


    return 0;
}