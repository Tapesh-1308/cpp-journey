// ARRANGE - Arranging Amplifiers - SPOJ
#include<iostream>
#include<algorithm>
using namespace std;

// TC -> O(nlogn)
// SC -> O(1)

int main() {
    // t - testcases
    int t; cin>>t;

    while(t--) {
        // n - number of amplifiers
        int n; cin>>n;

        // array - denote the values with which the amplifiers are loaded.
        int arr[n];

        int one_count = 0; // count number of ones in arr

        // take input and count ones in arr
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            if(arr[i] == 1) one_count++;
        }

        // sort in decreasing order
        sort(arr, arr+n, greater<int>());

        // print 1 first, to get strongest result
        for(int i=0; i<=one_count; i++)
            cout<<"1 ";

        // in 2 size array(excluding ones), this order will give [2 3] -> 3^2 = 9, not this [3 2] -> 2^3 = 8
        if(n-one_count == 2 and (arr[0] == 3 && arr[1] == 2))
            cout << "2 3 ";

        else {
            // print the arr before ones [6,5,4,1,1,1] -> print 6 5 4 only
            for(int i=0; i<n-one_count; i++) 
                cout<<arr[i]<<" ";
        }
        cout<<endl;

    }

    return 0;
}