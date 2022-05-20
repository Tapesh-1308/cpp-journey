#include<bits/stdc++.h>
using namespace std;

// Method TC -> O(nlogn) SC -> O(n)

int minSwapsToSort(vector<int> &nums, int n) {
    int n = nums.size(), ans(0);
    
    //It will store (nums[i], i), means element and its index
    vector<pair<int, int>> arr(n);
    
    //Storing data in arr
    for(int i=0; i<n; i++)
        arr[i] = make_pair(nums[i], i);
    
    // Sort arr -> so that it can tell before sorting what is its previous index -> pair.second - stores before sorting position of elements
    sort(arr.begin(), arr.end());
    
    //Boolean array to check whether cycle is completed or not
    vector<bool> visited(n, 0);

    // Traverse on arr
    for(int i=0; i<n; i++) {
        // If it is already visited or it is on its correct place before or after sorting, means we don't need any swap here
        if(visited[i] || arr[i].second == i)
            continue;
            
        // clen -> stores length of cycle, j to traverse to make cycle
        int clen(0), j(i);

        // while cycle is not completed
        while(!visited[j]) {
            // mark this elment as true, if we again come on it means cycle will complete then
            visited[j] = true;
            
            // Jump j to curr element actual position means position before sorting
            j = arr[j].second;

            // Increment cycle length
            clen++;
        }
        // clen - 1 => for 4 length of cycle we need 3 swaps to make it sorted, for 3 we need 2, for 2 we need 1
        ans += clen-1;
    }
    return ans;
}

int main(){
    vector<int> nums = {2, 8, 5, 4};
    int n = nums.size();

    cout << minSwapsToSort(nums, n);
    return 0;
}