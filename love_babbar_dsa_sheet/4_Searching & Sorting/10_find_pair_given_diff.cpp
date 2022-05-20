#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Brute force TC O(N^2) SC O(1)
bool findPairDiff(int arr[], int n, int x){
    // To find 1t element of pair
    for(int i=0; i<n; i++) {
        // toFind -> if arr[i] is 1st element of pair, find id 2nd is also present in array  
        int toFind = arr[i]+x;

        for(int j=0; j<n; j++) {
            // If found 
            if(i != j && arr[j] == toFind) {
                // Return true ans print ans
                cout << "Pair found at: (" << arr[i] << ", " << arr[j] << ")";
                return true;
            }
        }
    }
    // If no pair found - Return false
    cout << "No Pair Found";
    return false;
} */

/* Method - 2 Binary Search TC O(2 * nlogn) SC O(1)

// Binary Search Algorithm
int binarySearch(int arr[], int st, int end, int target) {
    int mid;
    while(st<=end) {
        mid = (st+end)/2;
        if(arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            st = mid+1;
        else end = mid-1;
    }
    return -1;
}

bool findPairDiff(int arr[], int n, int x){
    // Sort the array to apply binary search
    sort(arr, arr+n);

    // Travering array
    for(int i=0; i<n; i++) {
        // if arr[i] 1st element of pair find 2nd element using binary search
        int idx = binarySearch(arr, i+1, n-1, x+arr[i]);
        
        // If we found, verify it
        if(idx != -1 && arr[idx] - arr[i] == x) {
            // then return ans
            cout << "Pair found at: (" << arr[i] << ", " << arr[idx] << ")";
            return true;
        }
    }
    // else return false
    cout << "No Pair Found";
    return false;
} */

// Method - 3 Two Pointer TC O(nlogn + n) SC O(1)
bool findPairDiff(int arr[], int n, int x){
    sort(arr, arr+n); // Sort the array

    int i=0, j=1; // Two Pointers
    
    while(i < n && j < n) {
        // If diff between two pointer element is x return true
        if(i != j && (arr[i]-arr[j] == x || arr[j]-arr[i] == x)) {
            cout << "Pair found at: (" << arr[i] << ", " << arr[j] << ")";
            return true;         
        }

        // if diff is less than x then move j to get greater element             
        else if (max(arr[j]-arr[i] , arr[i]-arr[j]) < x)
            j++;
        
        // if diff is greater than x move i to decrease diff
        else i++;
    }
    
    // if no pair found - return false
    cout << "No Pair Found";
    return false;
}

int main(){
    int arr[] = {5, 20, 3, 2, 5, 80};
    int n = sizeof(arr)/sizeof(int);

    int x = 78; // Number to find
    findPairDiff(arr, n, x);
    return 0;
}