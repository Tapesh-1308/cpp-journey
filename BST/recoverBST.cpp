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

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if(!root) return;
    calcPointers(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data){
        if(!*first) {
            *first = *prev;
            *mid = root;
        }
        else *last = root;
        
    }
    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recoverTree(Node* root){
    Node *first, *last, *mid, *prev;
    first = last = mid = prev = NULL;
    calcPointers(root, &first, &mid, &last, &prev);

    //case 1
    if(first && last) swap(&(first->data), &(last->data));
    else if(first && mid) swap(&(first->data), &(mid->data));
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(9);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorder(root);
    recoverTree(root);
    cout<<endl;
    inorder(root);

    return 0;
}