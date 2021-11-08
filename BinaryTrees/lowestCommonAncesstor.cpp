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

Node* LCA(Node* root, Node* p, Node* q){
    if(root->data==p->data || root->data==q->data) return root;
    if(!root->left && !root->right) return NULL;

    Node* left=NULL, *right=NULL;
    if(root->left) left = LCA(root->left, p, q);
    if(root->right) right = LCA(root->right, p, q);
    if(left and right) return root;

    return left==NULL?right:left;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* left = new Node(6);
    Node* right = new Node(7);

    
    cout<<LCA(root, left, right)->data;
    return 0;
}