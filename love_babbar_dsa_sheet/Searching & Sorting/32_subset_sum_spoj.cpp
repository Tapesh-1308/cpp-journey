#include<bits/stdc++.h>
using namespace std;

// Method BitMask & BinarSearch TC O(2^(N/2) + nlogn) SC O(N)

// Store all subset sum of input array in vector
void solve(vector<int> &arr, int st, int end, vector<int> &v){
    int sum = 0; // Stores sum of subsets
    int n = end-st+1; // Size 

    // Making bit mask for all possible subsets 2^n (1<<n)
    for(int mask=0; mask<(1<<n); mask++){
        sum=0;
        // checking for all bits for every mask 
        for(int i=0;i<n;i++)
            if(mask & (1<<i)) // Checking if ith bit is set or not
                sum+=arr[i+st]; // storing sum arr[i+st], means actual element position, if we have right half array  then n/2 + i will be the correct position
        v.push_back(sum); // storing in vector
    }

    /* Recursive method
    // Base case
    if (st > end) {
        v.push_back(sum);
        return;
    }
    solve(arr, st + 1, end, v, sum + arr[st]); // Including curr into sum
    solve(arr, st + 1, end, v, sum); */ // Not including curr into sum
}

int subsetSum(vector<int> &arr, int A, int B) {
    int n = arr.size();
    vector<int> v1, v2; // v1 -> left half of arr subset sum, v2 -> right half of arr subset sum

    //Calulating subsets sum for left half and right half
    solve(arr, 0, (n/2)-1, v1); // 0...n/2-1
    solve(arr, n/2, n-1, v2); // n/2...n-1

    int count=0; // Stores ans -> number of subsets lies in given range
    sort(v2.begin(), v2.end()); // Sorting v2 to apply binary search
    
    // for every element of v1 search A - v1[i] and B - v1[i] in v2
    for(int i=0; i<v1.size(); i++) {
        int low = lower_bound(v2.begin(), v2.end(), A-v1[i]) - v2.begin(); // Lower bound A-v1[i]
        int high = upper_bound(v2.begin(), v2.end(), B-v1[i]) - v2.begin(); // upper bound B-v2[i]
        count += (high - low); // Add the differnce of high and low in count, all elements between high and low gives sum in given range 
    }

    // Return answer
    return count;
}

int main(){
    // vector<int> arr = {1,5,3,4,2,6};
    // int A = 6, B = 10;

    // cout << subsetSum(arr, A, B) << endl; 

    int n, A, B; // A -> starting of range, B -> ending of range
    cin>>n>>A>>B;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout << subsetSum(arr, A, B) << endl;
    return 0;
}