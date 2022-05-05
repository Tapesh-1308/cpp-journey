#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int st, int end, int target) 
{
    int mid;
    while(st<=end) {
        mid = (st+end) / 2;

        // If we arr[mid] is not greater than target then search for big numbers in right side
        if(arr[mid] <= target)
            st = mid+1;
        // If we found big numbers then we have to search in left direct to get small number, but not smaller than target <- this will be taken care by previous condition
        else end = mid-1;
    }
    return st; // Return start point where st is on next greater element of m
}

int main() {
    int n; cin>>n; // N is the number of soldiers

    // arr -> power of N soldiers
    vector<int> arr(n);
    for(int i=0; i<n; i++) 
        cin >> arr[i];
    
    // Number of rounds in fight
    int q; cin>>q;

    /* Method - 1 Linear Search TC O(Q*N) SC O(1) 
    // Runs for all rounds
    while(q--) {
        // M is the power of bishu at each round
        int m; cin>>m;

        // Count -> Store number of soldiers Bishu can kill
        // Sum -> Stores the sum of power of soldiers that he killed
        int count(0), sum(0);

        // Calculating Count and sum
        for(auto i:arr) {
            if(i <= m) { // If arr[i] is less than bishu's power then he can kill
                count++; // So increment count
                sum+=i; // ans update sum
            }
        }

        // Print ans for this round
        cout<<count <<" "<<sum<<endl;
    }
    */

    // Method - 2 Using Binary Search TC O(QlogN + NlogN) SC O(N)
    sort(arr.begin(), arr.end()); // Sort the array to apply BS

    // Prefix array stores sum from arr[0]+arr[i]+...+arr[i] = prefix[i]
    vector<int> prefix(n, 0);
    // Storing data in prefix
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum+=arr[i];
        prefix[i] = sum;
    }

    // Runs for every round
    while(q--) {
        int m; cin>>m;
        // Find index where arr[idx] == upperbound of m, arr[idx] is just greater element from m
        int idx = binarySearch(arr, 0, n-1, m);
        // If idx is means bishu has not enough power to kill anyone
        if(idx == 0)
            cout << 0 << " " << 0 << endl; // Return ans as 0 0
        // Else print idx and sum from arr[0] to  arr[idx-1] = prefix[idx-1]
        else cout << idx << " " <<prefix[idx - 1] << endl;
    } 
    return 0;
}