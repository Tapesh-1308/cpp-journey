/* C++ program to find minimum swaps required to convert binary ttree to BST */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

pair<bool, int> sumTreeUtil(Node* root) {
    // root is null return {isSumTree->true : sum->0}
    if( !root ) return {true, 0};

    // if curr node is leaf return {true, sum->curr node data}
    if( !root->left && !root->right) return {true, root->data};

    // call recursively for left and right subtee
    auto left = sumTreeUtil(root->left);
    auto right = sumTreeUtil(root->right);

    // check if left and right subtree sum is equal to root data
    bool sum = (left.second + right.second) == root->data;

    pair<bool, int> ans;

    // calculate sum
    ans.second = left.second + right.second + root->data;

    // ans.first will be true, if 1) left subtree return true 2) right subtree return true 3) left and right sum is equal to root->data
    if(left.first && right.first && sum)
        ans.first = true;

    return ans;
}

bool sumTree(Node* root) {
    // sumTreeUtil returns pair of bool(isSumTree) and int(sum), return bool value
    return sumTreeUtil(root).first;
}


int main() {
    /* Constructed Tree 
              26
             /  \
           10    3
          /  \    \
         4    6    3
    */
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(6);

    root->right->right = new Node(3);

    if(sumTree(root))   
        cout << "It is a sum tree\n";
    else cout << "Not a sum tree\n";
}
