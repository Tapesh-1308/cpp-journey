#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Brute Force TC O(N^4 + nlogn) SC O(1)
vector<vector<int>> find4Sum(vector<int> &nums, int target){
    vector<vector<int>> ans; // To store answer

    int n=nums.size(); 

    // Sort the array
    sort(nums.begin(),nums.end());
    int sum;
    
    // Traverse for the 1st Number
    for(int i=0;i<n-3;++i) {
        if(i>0 and nums[i]==nums[i-1])  
            continue;   //Skip same values for index i to avoid duplicates

        // Traverse for 2nd Number
        for(int j=i+1;j<n-2;++j) {
            if(j>i+1 and nums[j]==nums[j-1])    
                continue;   //Skip same values for index j to avoid duplicates

            // Traverse for 3rd Number
            for(int k=j+1;k<n-1;++k) {
                if(k>j+1 and nums[k]==nums[k-1])    
                    continue;   //Skip same values for index k to avoid duplicates

                // Traverse for the 4th Number
                for(int l=k+1;l<n;++l) {
                    if(l>k+1 and nums[l]==nums[l-1])    
                        continue;   //Skip same values for index l to avoid duplicates

                    // Calulate sum
                    sum=nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum>target) // It means we do not have to traverse further because we traverse we will only greater sum than this
                        break;

                    // If we get any quadruplets
                    else if(sum==target) {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        t.push_back(nums[l]);
                        ans.push_back(t);        
                    }
                }
            }
        }
    }
    return ans;
} */

/* Method - 2 Two Pointer TC O(N^3 + nlogn) SC O(1)
vector<vector<int>> find4Sum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());

    int sum;
    
    // For 1st Number
    for(int i=0;i<n-3;++i) {
        if(i>0 and nums[i]==nums[i-1])  
            continue;   //Skip same values for index i to avoid duplicates
        
        // For 2nd number
        for(int j=i+1;j<n-2;++j) {
            if(j>i+1 and nums[j]==nums[j-1])  
                continue;   //Skip same values for index j to avoid duplicates

            int left=j+1,right=n-1;
            
            // Apply Two Pointer for 3rd and 4th number
            while(left<right)   {
                // Claulate sum
                sum=nums[i]+nums[j]+nums[left]+nums[right];
                // If sum is greate decrease sum by decrementing right
                if(sum>target)
                    right-=1;
                // If sum is equal, means we get any quadruplets
                else if(sum==target) {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    t.push_back(nums[left]);
                    t.push_back(nums[right]);
                    ans.push_back(t);

                    while(left < right && nums[left] == t[2]) // Skip duplicates
                        left++;
                    while(right > left && nums[right] == t[3]) // Skip duplicate
                        right--;
                }
                // Increment left when we get sum smaller than target
                else
                    left+=1;
            }
        }
    }
    return ans;
} */

// Method - 3 HashMap TC O(N^2 logn) Worst Case: O(N^4) SC O(1)
 vector<vector<int>> find4Sum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    // n is smaller than 4 return empty ans
    if(n<4)
        return ans;
    
    sort(nums.begin(),nums.end());
    unordered_map<int,vector<pair<int,int>>> m;    // key->SUM...Value->(i,j) pair of index where i<j
    
    //Store all 2 sum pairs in map
    for(int i=0;i<n-1;++i)
        for(int j=i+1;j<n;++j)
            m[nums[i]+nums[j]].push_back(make_pair(i,j));
    
    // Find other 2 numbers such that there sum = target - (nums[i] + num[j])
    for(int i=0;i<n-1;++i) {
        if(i>0 and nums[i]==nums[i-1])  continue; // skip duplicates
        for(int j=i+1;j<n;++j) {
            if(j>i+1 and nums[j]==nums[j-1])  continue; // skip duplicates

            // Calculate sum
            int sum = target-nums[i]-nums[j];

            // If sum is present in the array
            if(m.find(sum)!=m.end()) {
                // Loop for all occurances of that sum
                for(auto it: m[sum]) {
                    int k=it.first; // 3rd number index
                    int l=it.second; // 4th number index

                    if(k>j) {   //Maintain the increasing order of index (i,j,k,l).....i<j<k<l

                        //Skip if all elements are same than previos ->  invalid cases
                        if(!ans.empty() and ans.back()[0]==nums[i] and 
                            ans.back()[1]==nums[j] and ans.back()[2]==nums[k] 
                            and ans.back()[3]==nums[l])
                            continue;

                        // Push in ans
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    return ans;
}


int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> ans = find4Sum(nums, target);
    for(auto i: ans) {
        for(auto k: i) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}