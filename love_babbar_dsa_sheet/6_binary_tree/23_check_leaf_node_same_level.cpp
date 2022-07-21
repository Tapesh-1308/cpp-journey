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
bool checkUtil(struct Node *root,  int level, int &leafLevel)
{
    // Base case
    if (!root) return true;
 
    // If a leaf node is encountered
    if (!root->left && !root->right) {
        // When a leaf node is found first time
        if (leafLevel == -18) {
            leafLevel = level; // Set first found leaf's level
            return true;
        }
 
        // If this is not first leaf node, compare its level with first leaf's level
        return (level == leafLevel);
    }
 
    // If this node is not leaf, recursively check left and right subtrees
    return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}

bool checkLevelLeafNode(Node* root) {
    int leafLevel = -1;
    // call this utility function (root, curr_level, leaf node level)
    return checkUtil(root, 0, leafLevel);
}

// Approach - 2 Using Iteration TC O(N) SC O(N)
bool checkLevelLeafNode(Node* root) {
    if (!root) return true;
    
    /* Create an empty queue and push root into it */
    queue<Node* > q;
    q.push(root);
    
    /* leaf level stores the level of first encountered leaf and lvl store current level on which traversal is going */
    int leaf_level = -1;
    int lvl = 0;

    /* loop till queue is not empty */
    while(!q.empty()) {
        int size = q.size(); 
        
        // Process the current level
        for(int i=0; i<size; i++) {
            /* Get the front node of queue and remove it */
            Node* temp = q.front();
            q.pop();

            /* If front node is a leaf node */
            if(!temp->left && !temp->right) {
                // when it first leaf node was encountered
                if(leaf_level == -1) {
                    leaf_level = lvl; // Set first found leaf's level
                    continue;
                }
                // If this is not first leaf node, compare its level with first leaf's level, if not equal return false
                if(leaf_level != lvl) return false;
            }
            /* if front node is not a leaf node push left and right child in queue if exists */
            else {
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        lvl += 1; // increment the level
    }

    // if we reached here that means all nodes are on the same level
    return true;
}

int main(){
    Node* root = NULL;
    root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(5);

    root->left->left = new Node(7);
    root->left->right = new Node(11);

    root->right->left = new Node(17);
    
    if(checkLevelLeafNode(root)) cout << "All leaf nodes are on the same level";
    else cout << "Leaf Nodes are not on the same level";

    return 0;
}