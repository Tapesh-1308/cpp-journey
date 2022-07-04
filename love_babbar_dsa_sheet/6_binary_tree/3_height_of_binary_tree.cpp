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

int main(){
    Node* root = NULL;
    root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(5);

    root->left->left = new Node(7);
    root->left->right = new Node(11);

    root->right->left = new Node(17);

    return 0;
}