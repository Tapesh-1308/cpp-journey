#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int num){
    int temp = num, number = 0;
    while(temp>0){
        number = number*10 + temp%10;
        temp = temp/10;
    }
    if(number==num) return true;
    return false;
}

int findPalindromicArr(vector<int> nums, int k){
    int num=0;
    for(int i=0; i<k; i++) num = num*10 + nums[i];

    if(isPalindrome(num)) return 0;
    
    for(int i=k; i<nums.size(); i++){
        num = (num % (int)pow(10, k-1))*10 + nums[i];
        if(isPalindrome(num)) return i-k+1;
    }
    return -1; 
}

int main() {
    vector<int> nums = {2,3,5,1,1,5};
    int k = 3;
    int ans = findPalindromicArr(nums,k);
    if(ans==-1)cout<<"Doesn't exist";
    else{
        for(int i = ans; i<ans+k; i++) cout<<nums[i]<<" ";
    }
    
    return 0;
}