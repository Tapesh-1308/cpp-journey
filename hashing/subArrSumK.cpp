#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    if(n==0) return 0;
    unordered_map<int,int> mymap;
    int currSum = 0;
    int i = 0; 
    int count = 0;
    while(i<n){
        currSum+=nums[i];
        if(currSum==k) count+=1;
        if(mymap.find(currSum-k)!=mymap.end())
            count+=mymap[currSum-k];
        mymap[currSum]++;
        i++;
    }
    return count;
}

int main() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    cout<<subarraySum(nums, 7);
    return 0;
}