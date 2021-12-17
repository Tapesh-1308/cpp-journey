#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int catalan(int n){
    if(n<=1) return 1;

    int res = 0;
    for(int i=0; i<=n-1; i++)
        res += catalan(i) * catalan(n-i-1);  
    return res;
}

//Finding all possible BST using catalan sequence
vector<Node*> constructTrees(int start, int end) {
    vector<Node*> trees;
    if(start>end) {
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end; i++){
        vector<Node*> leftSubTrees = constructTrees(start, i-1);
        vector<Node*> rightSubTrees = constructTrees(i+1, end);

        for(int j=0; j<leftSubTrees.size(); j++){
            Node* left = leftSubTrees[j];
            for(int k=0; k<rightSubTrees.size(); k++){
                Node* right = rightSubTrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
} 

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main() {
    // cout<<catalan(4);
    // for(int i=0; i<10; i++) cout<<catalan(i)<<endl;

    vector<Node*> totalTrees = constructTrees(1, 4);
    for(int i=0; i<totalTrees.size(); i++){
        cout<<(i+1)<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }

    return 0;
}