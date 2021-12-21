#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    int left = 0, right = n-1, mid;
    if(n==0) return 0;
    if(n==2) return nums[0] > nums[1] ? 0 : 1;
    while(left<=right){
        mid = (left+right)/2;
        if((mid==0 || nums[mid]>=nums[mid-1]) && (mid==n-1 || nums[mid]>=nums[mid+1]))
            return mid;
        
        else if(mid>0 && nums[mid]>nums[mid-1]) left = mid+1;
        
        else right = mid;
    }
    return -1;
}

int main() {
    vector<int> nums = {3,4,3,2,1};
    cout << findPeakElement(nums);
    return 0;
}