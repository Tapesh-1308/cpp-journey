#include <bits/stdc++.h>
using namespace std;

// Method - 1 Linear Search TC - O(N) SC - (1) 
int valueEqualToIndex(int arr[], int n) {
    for(int i=0; i<n; i++) 
        if(arr[i] == i)
            return i;
    
    return -1;
}

// Method - 2 Binary Search TC - O(logN) SC - O(1)
int valueEqualToIndex(int arr[], int n){
    int st = 0, end = n-1, mid;
    while(st<=end) {
        mid = (st+end) / 2;
        
        if(arr[mid] == mid) { // Index == value
            return mid;
        }
        else if(arr[mid] < mid) {
            st = mid+1;
        }
        else end = mid-1;
    }
    return -1;
}
	   
int main() {
    int arr[] = {-10, -1, 2, 4};
    cout << valueEqualToIndex(arr, 4);
    
	return 0;
}