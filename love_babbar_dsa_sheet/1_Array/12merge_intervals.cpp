#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.empty()) return ans;
        
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        
        for(auto it: intervals){
            if(it[0]<=temp[1])
                temp[1] = max(temp[1], it[1]);
            else {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
        
    }
};

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    for(auto it: intervals){
        for(auto j: it){
            cout<<j<<" ";
        }
        cout<<"  ";
    }
    cout<<endl;
    Solution ob;
    vector<vector<int>> ans = ob.merge(intervals);
    for(auto it: ans){
        for(auto j: it){
            cout<<j<<" ";
        }
        cout<<"  ";
    }
    return 0;
}

