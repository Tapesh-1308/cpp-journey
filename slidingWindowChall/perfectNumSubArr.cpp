#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> nums, int n, int k){
    if(n<k) return -1;

    int res=0;
    for(int i=0; i<k; i++)
        res += nums[i];

    int sum=res;
    for(int i=k; i<n; i++){
        sum += nums[i] -  nums[i-k];
        res=max(res, sum);
    }
    return res;
}

bool isNumberPerfect(int num){
    if(num<0 || num==1) return false;
    int sum=1;
    for(int i=2; i<sqrt(num); i++){
        if(num%i==0) 
        i==num/1 ? sum += i  : sum += i + num/i;
    }
    return sum==num && num!=1; 
    
}

int maxPerfectNum(vector<int> nums, int k){
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(isNumberPerfect(nums[i])) nums[i]=1;
        else nums[i]=0;
    }

    return maxSum(nums, n, k);
}

int main() {
    vector<int> nums = {28,2,3,6,496,99,8128,24};
    cout<<maxPerfectNum(nums, 4);
    return 0;
}