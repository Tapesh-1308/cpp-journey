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

//building tree using preorder - inorder

int search(int inorder[], int start, int end, int curr){
    for (int i = start; i <= end; i++) {
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end){
        static int idx = 0;
        if(start>end)
            return NULL;

        int curr = preorder[idx];
        idx++;
        Node* node = new Node(curr);

        if(start==end)
            return node;
        int pos = search(inorder, start, end, curr);
        node->left = buildTree(preorder, inorder, start, pos-1);
        node->right = buildTree(preorder, inorder, pos+1, end);

        return node;
}

//building tree using postorder - inorder

int search2(int inorder[], int start, int end, int curr){
    for (int i = start; i <= end; i++) {
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}

Node* buildTree2(int postorder[], int inorder[], int start, int end){
        static int idx = 4;
        if(start>end)
            return NULL;

        int curr = postorder[idx];
        idx--;
        Node* node = new Node(curr);

        if(start==end)
            return node;
        
        int pos = search2(inorder, start, end, curr);
        node->right = buildTree2(postorder, inorder, pos+1, end);
        node->left = buildTree2(postorder, inorder, start, pos-1);

        return node;    
}

void inOrderPrint(struct Node* root){
    if(root==NULL)
        return;
    inOrderPrint(root->left);   
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

int main() {
    int preorder[] = {1,2,4,3,5};
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    //Building tree preorder-inorder
    Node* root = buildTree(preorder, inorder, 0, 4);
    inOrderPrint(root);

    cout<<endl;

    //Building tree postorder-inorder
    Node* root2 = buildTree2(postorder, inorder, 0, 4);
    inOrderPrint(root);
    
    return 0;
}