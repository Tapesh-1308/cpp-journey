#include<bits/stdc++.h>
using namespace std;

// Method - TC O(N) SC O(1)
vector<pair<int,int>> getSubArr0Sum(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, vector<int>> um; // Key -> sum Value -> vector of all index where sum is same

    // Store starting and ending index of subarray for every subarray sum 0
    vector<pair<int, int>> ans;

    int sum=0;
    // Traverse on array
    for(int i=0; i<n; i++) {
        sum += nums[i]; // Calulate sum

        // If sum become 0 means arr[0...i] sum is 0
        if(sum == 0) 
            ans.push_back({0,i}); // so push it in ans

        // If sum is already present in map, means here a[i] is the last index of subarr with 0 sum 
        if(um.find(sum) != um.end()) {
            auto vec = um[sum]; // it will store vec
            for(auto it:vec) // Traverse for every index in vector
                ans.push_back({it+1, i}); // it+1 -> starting of subarr, i->ending of subarr
        }    
        // Push index in map 
        um[sum].push_back(i);
    }
    // return answer
    return ans;
}

int main(){
    vector<int> nums = {6,3,-1,-3,4,-2,2,4,6,-12,-7};

    vector<pair<int, int>> ans = getSubArr0Sum(nums);

    // Printing output
    for(auto i:ans) 
        cout << i.first << " " << i.second <<endl;

    // Printing all subarrays
    for(auto i:ans) {
        for(int j=i.first; j<=i.second; j++)
            cout << nums[j] <<" ";
        cout << endl;
    }

    return 0;
}