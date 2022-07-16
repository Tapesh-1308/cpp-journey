/* C++ program to construct tree using inorder and preorder traversals */
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

/*======================================= Approach - 1 ==========================================*/

// Naive Approach - TC O(N^2) SC O(N)

/* Function to find the index in inorder */
int findIndex(vector<int> &in, int data) {
    for(int i=0; i<in.size(); i++)
        if(in[i] == data) return i;
    return -1;
}

/* Recursive function to construct binary Tree */
Node *buildTree(vector<int> &pre, vector<int> &in, int &preInd, int inStrt, int inEnd)
{
    if (preInd >= pre.size() || inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder traversal using preIndex */
    Node *root = new Node(pre[preInd]);

    /* Find the index of this node in Inorder traversal */
    int index = findIndex(in, pre[preInd]);

    preInd += 1; // increment preIndex 

    /* Using index in Inorder traversal, construct left and right subtress */
    root->left = buildTree(pre, in, preInd, inStrt, index - 1);
    root->right = buildTree(pre, in, preInd, index + 1, inEnd);

    return root;
}

// This function mainly creates an unordered_map, then calls buildTree()
Node *buldTreeWrap(vector<int> &pre, vector<int> &in)
{
    int preInd = 0;
    return buildTree(pre, in, preInd, 0, in.size() - 1);
}
/*===============================================================================================*/

/*======================================= Approach - 2 ==========================================*/
// Optimized Approach (Using Map) - TC O(N) SC O(N)

/* Recursive function to construct binary Tree */
Node *buildTree(vector<int> &pre, vector<int> &in, int &preInd, int inStrt, int inEnd, unordered_map<int, int> &mp)
{
    if (preInd >= pre.size() || inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder traversal using preIndex and increment preIndex */
    Node *root = new Node(pre[preInd]);

    /* Find the index of this node in Inorder traversal */
    int index = mp[pre[preInd]];

    preInd += 1;

    /* Using index in Inorder traversal, construct left and right subtress */
    root->left = buildTree(pre, in, preInd, inStrt, index - 1, mp);
    root->right = buildTree(pre, in, preInd, index + 1, inEnd, mp);

    return root;
}


// This function mainly creates an unordered_map, then calls buildTree()
Node *buldTreeWrap(vector<int> &pre, vector<int> &in)
{
    // Store indexes of all items so that we we can quickly find later
    unordered_map<int, int> mp;

    for (int i = 0; i < in.size(); i++)
        mp[in[i]] = i;

    int preInd = 0;
    return buildTree(pre, in, preInd, 0, in.size() - 1, mp);
}

/*===============================================================================================*/

/* This function is here just to test buildTree() */
void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> in = {9, 3, 15, 20, 7};
    vector<int> pre = {3, 9, 20, 15, 7};

    Node *root = buldTreeWrap(pre, in);

    /* Let us test the built tree by printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
