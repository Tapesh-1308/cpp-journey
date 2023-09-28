#include <bits/stdc++.h>
using namespace std;

// Approach - Using DFS - TC O(V+2E) - SC O(V)

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*> &um) {
        if(um.count(node) > 0) return um[node];
        
        Node* temp = new Node(node->val);
        um[node] = temp;
        for(auto it: node->neighbors) {
            temp->neighbors.push_back(dfs(it, um));
        }
        return um[node];
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> um;
        
        return dfs(node, um);
    }
};

void print_dfs(Node* node, unordered_set<Node*> &vis) 
{
    cout << node->val << " ";
    vis.insert(node);
    for(auto it: node->neighbors) {
        if(!vis.count(it)) {
            print_dfs(it, vis);
        }
    }
}

void print(Node* node) {
    unordered_set<Node*> vis;
    print_dfs(node, vis);
}

int main (){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node3);
    node2->neighbors.push_back(node1);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    print(node1);
    cout << endl;

    Solution obj;
    Node* newNode1 = obj.cloneGraph(node1);

    print(newNode1);

    return 0;
}