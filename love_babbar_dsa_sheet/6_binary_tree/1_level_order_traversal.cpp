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

// Approach 1 - Recusrion - TC O(N^2) SC O(N)

/* Utility function to print current level*/
void printCurrLevel(Node* root, int level) {
    // base case
    if(!root) return;

    // if level is one then we have only one one so print that
    if(level == 1) 
        cout << root->data << " ";

     // call for left/right of root to reach that level, keep decreasing level so that it can hit condition level==1 and print data
    else {
        printCurrLevel(root->left, level-1);
        printCurrLevel(root->right, level-1);
    }
}

void level_order_traversal(Node* root) {
    int height = heightBT(root); // find the height of the tree

    // for every level call print current level function to print all nodes of current level
    for(int i=1; i<=height; i++) {
        printCurrLevel(root, i);
    }
}

// Approach - 2 Using queue DS - TC O(N) SC O(N)
void level_order_traversal(Node* root) {
    // Base Case
    if(!root) {
        cout << "Empty tree ";
        return;
    }

    // Create an empty queue for level order traversal
    queue<Node*> q;
    // Enqueue Root
    q.push(root);


    // Run loop while queue is not empty 
    while(!q.empty()) {
        // Print front of queue and remove it from queue
        Node* temp = q.front();
        q.pop();
        
        cout << temp->data << " ";

        /* Enqueue left and right child */
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

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

    level_order_traversal(root);
    return 0;
}