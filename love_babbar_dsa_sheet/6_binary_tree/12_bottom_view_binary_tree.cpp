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

// Approach - 1 Using Recursion - TC O(NlogN) SC O(N)

// function to fill the map
void fillMap(Node* root, int hd, int l, map<int, pair<int, int> >& m) {
    // Base case
    if (!root)
        return;

    // map {curr node, curr level} with hd only if, this is the first node of curr hd or curr level is greater than or equal the level already present in map 
    if (m.find(hd) == m.end() || m[hd].second <= l) {
        m[hd] = {root->data, l};
    }

    // recur for left and right child, decrement hd for left and increment for right, increment level for both
    fillMap(root->left, hd - 1, l + 1, m);
    fillMap(root->right, hd + 1, l + 1, m);
}

void bottom_view(struct Node* root) {
    // map to store the pair of node value and its level with respect to the vertical distance from root.

    //{ vertical, node->data, level } 
    map<int, pair<int, int> > m;

    // fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);

    // print the bottom view
    for (auto it : m) {
        cout << it.second.first << " ";
    }
}

// Approach - 2 Using queue DS - TC O(NlogN) SC O(N)
void bottom_view(Node* root) {
    if(!root) return;

    // create a map {key: horizontal distance value: node}, to get node in sorted order 
    map<int, int> m;

    // create a queue of pair of node and horizontal distance ans enque root with hd 0
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    // run a loop till queue is not empty    
    while(!q.empty()){
        // get front pair and remove it from queue
        auto temp = q.front(); 
        q.pop();

        // get node and hd from pair
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        // map frontNode with key hd
        m[hd] = frontNode->data;
        
        // push left and right child in queue for left decrease hd and for right increase hd
        if(frontNode->left) q.push({frontNode->left, hd-1});
        if(frontNode->right) q.push({frontNode->right, hd+1});
    }
    
    // print bottom view which is contained me map 
    for(auto i: m)
        cout << i.second << " ";

}

int main(){
    Node* root = NULL;
    root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(5);

    root->left->left = new Node(7);
    root->left->right = new Node(11);

    root->right->left = new Node(17);

    bottom_view(root);
    return 0;
}