#include<bits/stdc++.h>
using namespace std;

//leetcode 347

class Solution {
    struct node
    {
        int no;
        int freq;
        node(int a, int b){
            no=a;
            freq=b;
        }
    };  
    struct compare{
        bool operator()(node const& a, node const& b){
            return a.freq < b.freq;
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int ele: nums)
            m[ele]++;

        priority_queue<node, vector<node>, compare> heap;
        for(auto it:m)
            heap.push(node(it.first, it.second));
        vector<int> ans;
        while(k--){
            node temp = heap.top();
            heap.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};

int main() {
    vector<int> nums={1,1,1,2,2,3};
    Solution obj;
    vector<int> ans = obj.topKFrequent(nums, 2);
    for(auto it : ans)
        cout<<it<<endl;
    return 0;
}