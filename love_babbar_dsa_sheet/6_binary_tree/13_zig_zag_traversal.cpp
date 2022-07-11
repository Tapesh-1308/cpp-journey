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

    return max(lh, rh) + 1 ; // add curr node with maxium of left height and right height and return 
}

// Approach 1 - Two Stacks - TC O(N) SC O(N)
void zig_zag_traversal(Node* root) {
    if(!root) return;

    // create two stacks for current level and or next level
    stack<Node*> curr_level;
    stack<Node*> next_level;

    // push root node into curr level
    curr_level.push(root);

    // flag to determine the direction
    bool leftToRight = true;

    while(!curr_level.empty()) {
        // get the top node and remove it from stack
        Node* temp = curr_level.top();
        curr_level.pop();

        // print the data
        cout << temp->data << " ";

        // if we are moving in left to right direction, for next level we will move right to left so push left first then right so that right can process first (LIFO)
        if(leftToRight) {
            if(temp->left) next_level.push(temp->left);
            if(temp->right) next_level.push(temp->right);
        }
        // if we are moving right to left then push right first anf then left
        else {
            if(temp->right) next_level.push(temp->right);
            if(temp->left) next_level.push(temp->left);
        }

        // if completely processed the current level then move towards next level by swapping next level with curr level and also change the direction 
        if(curr_level.empty()) {
            leftToRight = !leftToRight;
            swap(curr_level, next_level);
        }
    }
}


// Approach 2 - Recursion - TC O(N^2) SC O(N)

/* Utility function to print current level*/
void printCurrLevel(Node* root, int level, bool &righToLeft) {
    // base case
    if(!root) return;

    // if level is one then we have only one one so print that
    if(level == 1) 
        cout << root->data << " ";

     // call for left/right of root to reach that level, keep decreasing level so that it can hit condition level==1 and print data
    else {
        // if we have to move from left to right
        if(!righToLeft) {
            printCurrLevel(root->left, level-1, righToLeft);
            printCurrLevel(root->right, level-1, righToLeft);
        }
        // if we have to move from right to left
        else {
            printCurrLevel(root->right, level-1, righToLeft);
            printCurrLevel(root->left, level-1, righToLeft);
        }
    }
}

void zig_zag_traversal(Node* root) {
    int height = heightBT(root); // find the height of the tree

    // to check in which direction we have to move
    bool righToLeft = false;

    // for every level call print current level function to print all nodes of current level
    for(int i=1; i<=height; i++) {
        printCurrLevel(root, i, righToLeft);
        // change the direction
        righToLeft = !righToLeft; 
    }
}

// Approach - 3 Using queue DS - TC O(N) SC O(N)
void zig_zag_traversal(Node* root) {
    if(!root) return;
    
    // initialize a queue and enque root
    queue<Node*> q;
    q.push(root);
    
    // create a direction flag
    bool leftToRight = true;
    
    // loop till queue is not empty
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size); // to store curr level
        
        // process first level
        for(int i=0;i<size; i++){
            // get the front node and remove it from queue 
            Node* temp = q.front();
            q.pop();
            
            // index tell how to store in ans reverse or not
            int index = leftToRight ? i : size - i - 1;
            ans[index] = temp->data;

            // enque left and right child
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        // change the direction
        leftToRight = !leftToRight;
        
        // print current level
        for(auto i: ans){
            cout << i << " ";
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

    zig_zag_traversal(root);
    return 0;
}