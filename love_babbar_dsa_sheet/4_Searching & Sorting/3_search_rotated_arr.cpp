#include<bits/stdc++.h>
using namespace std;

// Method - 1 || 2 Iteration || TC O(2*logN) SC O(1)

int findPivot(int arr[], int st, int end) {
    // Check if it is rotated or not, return 0th arr[start] < arr[end]
    if(arr[st] < arr[end]) 
        return 0;

    // Find pivot using binary search
    int mid;
    while(st<end) {
        mid = (st+end) / 2;

        // If it satisfies pivot condition return mid
        if(arr[mid] > arr[mid+1])
            return mid;
        
        // If middle element is less than first element means graph is not strictly increaing
        // so pivot element can lie here, so search in left side
        else if(arr[mid] < arr[0])
            end = mid;
        
        // If middle element is greater then first element means graph is increasing stricly
        // so pivot element can't be lie in left of mid so search in right side
        else st = mid + 1;
    }

    return mid;
}

int binarySearch(int arr[], int st, int end, int target){ 
    // Simple binary search, start can be 0 or pivot + 1, end can be pivot , n-1
    int mid;
    while(st <= end) {
        mid = (st + end) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            st = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int search(int arr[], int n, int target) {
    if(n == 0) return -1; // If size is 0 we can't find target so return -1

    // If size is one check if it is equal to target or not 
    if(n == 1) return arr[0] == target ? 0 : -1;

    // Pivot is the element which is greater then prev and next element
    // It tells from where the array is rotated, to find call findPivot
    int pivot = findPivot(arr, 0, n-1);

    // If pivot is equal to target return pivot
    if(arr[pivot]==target)
        return pivot;

    // Else check if target is greater then the last element, if greater then
    // target must lies in between arr[0...pivot], else search in right 
    // arr[pivot+1...n-1]
    return target > arr[n-1] ? binarySearch(arr, 0, pivot, target) 
                             : binarySearch(arr, pivot+1, n-1, target); 

}

// Method 2 - 1 Iteration - TC O(logN) SC O(1)
int search(int arr[], int n, int target) {
    int st(0), end(n-1), mid;

    while(st<=end){
        mid = (st+end) / 2;

        if(arr[mid] == target)
            return mid;
        
        // Check if start to middle graph is strictly increasing 
        else if(arr[mid] >= arr[st]) {
            // Check if target can lie between start and middle if yes search st to mid 
            if(arr[mid] >= target && arr[st] <= target)
                end = mid - 1;
            // else search in mid to end
            else 
                st = mid + 1;
        }
        // If it is not strictly increasing 
        else {
            // Check if it lies in range( middle to end ), search in right side
            if(arr[mid] <= target && arr[end] >= target)
                st = mid + 1;
            // Else search in left side
            else 
                end = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(int);

    cout << search(arr, n, 0) << endl;

    return 0;
}