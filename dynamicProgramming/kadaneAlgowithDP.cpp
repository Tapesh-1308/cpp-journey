#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxx = nums[0];
    for(int i=1; i<nums.size();i++){
        nums[i] = max(nums[i], nums[i]+nums[i-1]);
        maxx = max(nums[i], maxx);
    }
    return maxx;
}

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
    return 0;
}
