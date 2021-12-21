#include<bits/stdc++.h>
using namespace std;


int search(vector<int>& nums, int target){
    int n = nums.size();
    int left = 0;
    int right = n-1;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>=nums[left]){
            if(nums[mid]>=target && nums[left]<=target){
                right = mid-1;
            }
            else left = mid+1;
        }
        else {
            if(nums[mid]<=target && nums[right]>=target){
                left = mid+1;
            }
            else right = mid-1;
        }
    } 
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,8,0,1,2,3};
    cout<<search(nums, 9);
    return 0;
}