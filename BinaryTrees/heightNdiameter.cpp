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

//Finding height of binary tree - Time Complexity O(n)
int height(Node* root){
    if(root == NULL) return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}

//Finding diameter of binary tree - Time Complexity O(n^2)
int diameter(Node* root){
    if(root==NULL) return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));

}

//Let's optimize it - O(n) 
int calcDiameter(Node* root, int* height){
    if(root == NULL) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(root->left, &lh);
    int rDiameter = calcDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // cout<<height(root)<<endl;

    // cout<<diameter(root)<<endl;

    int height = 0;
    cout<<calcDiameter(root, &height)<<endl;
    return 0;
}