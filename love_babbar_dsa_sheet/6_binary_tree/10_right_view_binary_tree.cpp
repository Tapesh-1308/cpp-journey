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

// Approach - 1 Using Recursion - TC O(N) SC O(N)
void right_view_util(Node* root, int level, int &max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (max_level < level)
    {
        cout << root->data << " ";
        max_level = level;
    }
 
    // Recur for left subtree first, then right subtree
    right_view_util(root->right, level + 1, max_level);
    right_view_util(root->left, level + 1, max_level);
    
}


void right_view(Node* root) {
    int max_level = 0;
    right_view_util(root, 1, max_level);
}

// Approach - 2 Using queue DS - TC O(N) SC O(N)
void leftView(Node* root) {
    // return if the tree is empty
    if (root) {
        return;
    }
 
    // create an empty queue and enqueue the root node
    queue<Node*> queue;
    queue.push(root);
 
    // loop till queue is empty
    while (!queue.empty()) {
        // calculate the total number of nodes at the current level
        int size = queue.size();
        int i = 0;
 
        // process every node of the current level and enqueue their non-empty left and right child
        while (i++ < size) {
            Node* curr = queue.front();
            queue.pop();
 
            // if this is the first node of the current level, print it
            if (i == 1) 
                cout << curr->data << " ";
 
            // push right and then left child if present
            if (curr->right) 
                queue.push(curr->right);
            if (curr->left) 
                queue.push(curr->left);
        }
    }
}

int main(){
    Node* root = NULL;
    root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(5);

    root->left->left = new Node(7);
    root->left->right = new Node(11);

    root->right->left = new Node(17);

    right_view(root);
    return 0;
}