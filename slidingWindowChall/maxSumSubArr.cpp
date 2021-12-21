#include<bits/stdc++.h>
using namespace std;

int maxSumSubarr(vector<int> nums, int k, int x){
    int n = nums.size();
    
    if(n==0 || n<k) return -1;
    if(n==1) return nums[0];

    int sum = 0, ans = 0;

    for(int i = 0; i<k; i++) sum += nums[i];
    if(sum<x) ans = sum;

    for(int i = k; i<n; i++){
        sum -= nums[i-k];
        sum += nums[i];
        if(sum<x) ans = max(ans, sum);
    }
    return ans;    
}

int main() {
    vector<int> nums = {7,5,4,6,8,9};
    cout<<maxSumSubarr(nums,3,20);
    return 0;
}