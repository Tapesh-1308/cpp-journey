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

// Leetcode Problem - 199 Right view of a binary tree - Iterative way 
void rightView(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root); 
     while (!q.empty()) {
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* node = q.front();
            q.pop();
            
            if(i==n-1) cout<<node->data<<" ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
    }
}

//Iterative way - Left View 
void leftView(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root); 
     while (!q.empty()) {
        int n = q.size();
        for(int i=1; i<=n; i++){
            Node* node = q.front();
            q.pop();
            
            if(i==1) cout<<node->data<<" ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
    }
}

//Recursive way for leetcode TUF - Right View
void recursion(Node* root, int level, vector<int> &ans){
    if(root==NULL) return;
    if(ans.size() == level) ans.push_back(root->data);
    recursion(root->right, level+1, ans);
    recursion(root->left, level+1, ans);
}
vector<int> rightSide(Node* root){
    vector<int> ans;
    recursion(root, 0, ans);
    return ans;
}

//Recursive way for leetcode TUF - Left View
void recursion2(Node* root, int level, vector<int> &ans){
    if(root==NULL) return;
    if(ans.size() == level) ans.push_back(root->data);
    recursion2(root->left, level+1, ans);
    recursion2(root->right, level+1, ans);
}
vector<int> leftSide(Node* root){
    vector<int> ans;
    recursion2(root, 0, ans);
    return ans;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Right view using level order traversal  TC-O(n) 
    rightView(root);
    cout<<endl;

    // Right view using recursive way TC-O(n) | SC-O(H) - H = height of BT
    vector<int> ans = rightSide(root);
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

    // Left view using level order traversal TC-O(n)
    leftView(root);
    cout<<endl;

    // Left view using recursive way TC-O(n) | SC-O(H) - H = height of BT
    vector<int> ans2 = leftSide(root);
    for(auto i : ans2){
        cout<<i<<" ";
    }
    return 0;
}


