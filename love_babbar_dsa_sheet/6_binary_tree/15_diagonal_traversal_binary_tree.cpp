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

// Approach - 1 Using Recursion TC O(N) SC O(N)
void fillMap(Node* root, int dl, unordered_map<int, vector<int>> &m) {
    if(!root) return; // base case
    
    // store node data in map according to diagonal
    m[dl].push_back(root->data);
    
    // recur for left and right 

    // increment diagonal for left child
    fillMap(root->left, dl+1, m);
    fillMap(root->right, dl, m);
}

void diagonal_traversal(Node* root) {
    // create a map of key: diagnal line, value: vector of all nodes of curr diagonal 
    unordered_map<int, vector<int>> m;

    // initialize diagonal with 0 and call fill mao function to traverse diagonally
    fillMap(root, 0, m);
    
    // traverse the map and print the diagonal elements
    for (int i = 0; i < m.size(); i++)
    {
        for (int j: m[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
}

// Approach - 2 Using queue iterative TC O(N) SC O(N)
void diagonal_traversal(Node *root)
{
    if(!root) return;

    //create an empty queue and enque root
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        // get front node from queue and remove it from queue
        Node* temp = q.front();
        q.pop();

        // process all current diagonal nodes
        while(temp){
            // keep pushing left node in queue 
            if(temp->left) q.push(temp->left);
            cout << temp->data << " "; // print the curr node
            temp=temp->right; // keep moving on right nodes
        }
    }
}


int main(){
    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);
    
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    diagonal_traversal(root);
    return 0;
}