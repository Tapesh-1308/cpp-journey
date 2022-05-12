#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Method - Binary Search 
         // TC : O(NlogN)
        //  SC : O(1)

// function to check if we cut trees from mid than wood we get is greater or smaller than required
bool isMax(vector<int> &height, int n, int mid, int m){
    int sum = 0; // Stores height 

    // Traverse on all trees
    for(int i=0; i<n; i++){
        // If height is greater than mid, means we can cut this trees
        if(height[i] > mid)
            // Wood we get is height - mid, add it to sum
            sum += height[i] - mid;

        // If sum becomes greater or equal to m then return true so that we can increase mid
        if(sum >= m)
            return true;
    }
    
    // Return false we sum is smaller than m
    return false;
}

int32_t main() {
    // N is number of trees
    // M is wood required (meters)
    int n, m;
    cin >> n >> m;

    // height -> contains height of N trees (meters)
    vector<int> height(n);
    for(int i=0; i<n; i++)
        cin >> height[i];
    
    // Search space [0.....maxHeight]
    int st = 0, end = 0;
    for(int i=0; i<n; i++)
        end = max(end, height[i]);
    
    int mid, res=0;
    while(st <= end) {
        mid = st + (end-st)/2;
        
        // If we cut trees from mid height and wood we get is greater than required then to decrease it we have to increase mid, hence start = mid + 1, store result also  
        if(isMax(height, n, mid, m)) {
            res = mid;
            st = mid+1;
        }
        // If we get smaller than required so to increase it we have to decrease mid, hence end = mid - 1
        else end = mid-1;
    }
    // Print answer
    cout << res << endl;

    return 0;
}