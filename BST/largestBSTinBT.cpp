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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBst;
};

Info largestBSTinBT(Node* root){
    if(!root) 
        return {0, INT_MIN, INT_MAX, 0, true};

    if(!root->left && !root->right) 
        return{1, root->data, root->data, 1, true};

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = 1+leftInfo.size+rightInfo.size;

    if(leftInfo.isBst && rightInfo.isBst && leftInfo.max < root->data && rightInfo.min > root->data){
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBst = true;
        return curr;
    } 
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBst = false;
    return curr;

};




int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->right->right = new Node(9);

    cout<<largestBSTinBT(root).ans;

    return 0;
}