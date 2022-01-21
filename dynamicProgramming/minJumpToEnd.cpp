// Minimum Jump To Reach End O(n^2) Solution
#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9+10;

int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(auto &it:nums) cin>>it;

    vector<int> jumps(n, inf);
    if(nums[0]==0) {
        cout<<inf;
        return -1;
    }
    jumps[0] = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            if(i<=(j+nums[j]))
                jumps[i] = min(jumps[i], 1+jumps[j]);
    cout<<jumps[n-1];
    return 0;
}