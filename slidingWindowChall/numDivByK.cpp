#include<bits/stdc++.h>
using namespace std;

pair<int, int> numberDivByK(vector<int> nums, int k){
    pair<int, int> ans;
    int sum = 0;
    for(int i=0; i<k; i++) sum += nums[i];

    if(sum%3 == 0) return ans = make_pair(0, k-1);
    
    for(int i=k; i<nums.size(); i++){
        sum += nums[i] - nums[i-k];
        if(sum%3 == 0) return ans = make_pair(i-k+1, i);
    }
    return ans = make_pair(-1, 0); 
}

int main() {
    vector<int> nums = {84,23,45,12,56,82};
    pair<int, int> ans = numberDivByK(nums,3);
    for(int i = ans.first; i<=ans.second; i++) cout<<nums[i]<<" ";
    return 0;
}