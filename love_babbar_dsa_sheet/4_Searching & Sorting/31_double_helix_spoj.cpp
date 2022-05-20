#include<bits/stdc++.h>
using namespace std;

#define int long long int

// Method - Two Pointer - TC O(N+M) SC O(1)
int findMaxSum(int arr1[], int arr2[], int n, int m){
    // i -> 1st array pointer, sum1 -> sum of array1
    // j -> 2nd array pointer, sum2 -> sum of array2
    int i=0, j=0, sum1=0, sum2=0;
    int maxSum=0; // Overall maxSum

    while(i<n && j<m) {
        // if a1[i] < ar[j]  then we put sum in sum1 and if it is greater then add it in sum2
        // by doing so when their is a common element i and j both pointing ot that same element
        if(arr1[i]<arr2[j]) 
            sum1 += arr1[i++]; // storing sum till next common element
        else if(arr2[j]<arr1[i])
            sum2 += arr2[j++]; // storing sum till nex common element

        // If both element are same
        else {
            // add max of sum1 and sum2 with curr element
            maxSum += max(sum1, sum2) + arr1[i]; 
            sum1 = sum2 = 0; // update it with zero to get sum form curr element to next common ele
            i++; j++;
        }
    }

    // If arr1 is not completely traversed (n>m)
    while(i<n) 
        sum1 += arr1[i++];
    
    // If arr2 is not completely traversed (m>n)
    while(j<m)
        sum2 += arr2[j++];

    maxSum += max(sum1, sum2);

    return maxSum;
}

int32_t main(){
    int arr1[] = {3,5, 7 ,9,20,  25 ,30,40, 55 ,56, 57 ,60,62};
    int arr2[] = {1,4, 7 ,11,14, 25 ,44,47, 55 ,    57 ,100};

    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);

    cout << findMaxSum(arr1, arr2, n, m) << endl;
    return 0;
}