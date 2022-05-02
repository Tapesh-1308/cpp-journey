#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Brute Force TC O(N^3) SC O(1)
int countTriplets(vector<int> &nums, int sum) {
    int n = nums.size();

    // Initialize result
    int ans = 0;
 
    // Fix the first element as A[i]
    for (int i = 0; i < n-2; i++) {
       // Fix the second element as A[j]
       for (int j = i+1; j < n-1; j++) {
           // Now look for the third number
           for (int k = j+1; k < n; k++)
               if (nums[i] + nums[j] + nums[k] < sum)
                   ans++;
       }
    }
 
    return ans;
} */

// Method - 2 Two Pointer TC O(N^2) SC O(1)
int counter(vector<int> &nums, int sum) {
    int n = nums.size();

    // Initialize result
    int count=0;

    // Sort the array
    sort(nums.begin(), nums.end());

    // Fix 1st number
    for(int i=0; i<n-2; i++) {
        if(nums[i] >= sum) break; // if 1st number become greater we can't find triplets(sorted array)

        // 2 pointer technique to fix 2nd and 3rd number
        int left = i+1, right = n-1;
        while(left < right) {
            if(nums[left]+nums[right]+nums[i] >= sum) // If sum is greater or equal -> to decrease sum shift right
                right--;
            else {
                // To count all triplets between right and left
                count+=(right-left);
                left++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> nums = {-2,0,1,3};
    int sum = 2;

    cout << counter(nums, sum) << endl;
    return 0;
}