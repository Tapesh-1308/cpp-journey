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

//search
Node* searchInBST(Node* root, int key){
    if(!root) return NULL;
    if(root->data==key) return root;
    if(root->data>key) return searchInBST(root->left, key);
    return searchInBST(root->right, key);
}

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left) curr = curr->left;
    return curr;    
}

//delete
Node* deleteBST(Node* root, int key){
    if(!root) return NULL;
    if(key<root->data) 
        root->left = deleteBST(root->left, key);
    else if(key>root->data) 
        root->right = deleteBST(root->right, key);
    else {
        if(!root->left){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        
        else if(!root->right){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }   
    return root;    
}


int main() {
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    if(searchInBST(root, 7)==NULL) cout<<"Key does not exist";
    else cout<<"Key exist";

    return 0;
}