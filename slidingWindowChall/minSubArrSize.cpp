#include<bits/stdc++.h>
using namespace std;

int minSubarrSize(vector<int> nums, int x){
    int n = nums.size();
    int sum = 0, ans = n+1, start = 0, end = 0;
    while(end<n){
        while(sum<=x && end<n) sum += nums[end++];

        while(sum>x && start<n){
            if(end-start < ans) ans = end-start;
            sum -= nums[start++];
        }
    }
    return ans;    
}

int main() {
    vector<int> nums = {1,4,45,6,10,19};
    int n = nums.size();
    int ans = minSubarrSize(nums,51);
    ans==n+1 ? cout<<"No subarray exist" : cout<<ans;
    return 0;
}