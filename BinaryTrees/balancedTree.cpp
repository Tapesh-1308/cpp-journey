#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root){
    if(root == NULL) return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}

//O(n^2)
bool isBalanced(Node* root){
    if(root==NULL) return true;

    if(isBalanced(root->left)==false) return false;
    if(isBalanced(root->right)==false) return false;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1) return true;  
    else return false;
}

//let's optimize it
bool isBalanced2(Node* root, int* height){
    int lh=0, rh=0;

    if(root==NULL) return true;

    if(isBalanced2(root->left, &lh)==false) return false;
    if(isBalanced2(root->right, &rh)==false) return false;

    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1) return true;
    else return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //Time complexity O(n^2)
    if(isBalanced(root)) cout<<"Balanced Tree\n";
    else cout<<"UnBalanced Tree\n";

    //Time complexity O(n)
    int height = 0;
    if(isBalanced2(root, &height)) cout<<"Balanced Tree\n";
    else cout<<"UnBalanced Tree\n";

    return 0;
}