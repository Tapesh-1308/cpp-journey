#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum element
int findMax(int arr[], int low, int high) {
	if (high == low)
		return arr[low];

	// Find mid
	int mid;
    while(low <= high) {
        mid = low + (high - low) / 2;
        // Check if mid reaches 0 ,it is greater than next element or not
        if(mid==0 && arr[mid]>arr[mid+1]) {
                return arr[mid];
        }

        // Check if mid itself is maximum element
        if (mid < high && arr[mid + 1] < arr[mid] && mid>0 && arr[mid]>arr[mid-1]) {
            return arr[mid];
        }

        // Decide whether we need to go to the left half or the right half
        if (arr[low] > arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return arr[mid];
}

int main() {
	int arr[] = { 7,8,9,1,2,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findMax(arr, 0, n - 1);

	return 0;
}
