#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};


class Solution {
    map<int, map<int, multiset<int>>> mymap;
    void solve(TreeNode* curr, int col, int row){
        if(!curr) return;
        mymap[col][row].insert(curr->val);
        solve(curr->left, col-1, row+1);
        solve(curr->right, col+1, row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);
        vector<vector<int>> ans;
        for(auto m1:mymap){
            ans.push_back(vector<int>());
            for(auto m2:m1.second){
                for(auto m3:m2.second)
                    ans.back().push_back(m3);
            }
        } return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    Solution obj;
    vector<vector<int>> vec = obj.verticalTraversal(root);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
    }
    cout<<endl;
    return 0;
}