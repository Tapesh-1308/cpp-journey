#include <iostream>
using namespace std;

// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1

/*Method 1 Brute Force - TC O(N^2) SC O(1)
 int smallestSubWithSum(int arr[], int n, int x) {
    //  Initialize length of smallest subarray as n+1
     int min_len = n + 1;
 
     // Pick every element as starting point
     for (int start=0; start<n; start++) {
          // Initialize sum starting with current start
          int curr_sum = arr[start];
 
          // If first element itself is greater
          if (curr_sum > x) return 1;
 
          // Try different ending points for current start
          for (int end=start+1; end<n; end++) {
              // add last element to current sum
              curr_sum += arr[end];
 
              // If sum becomes more than x and length of this subarray is smaller than 
              // current smallest length, update the smallest length (or result)
              if (curr_sum > x && (end - start + 1) < min_len)
                 min_len = (end - start + 1);
          }
     }
     return min_len;
} */

//Method 2 Two Pointer - TC O(N) SC O(1)
int smallestSubWithSum(int arr[], int n, int x) {
	// Initialize current sum and minimum length
	int curr_sum = 0, min_len = n + 1;

	// Initialize starting and ending indexes
	int start = 0, end = 0;
	while (end < n) {
		// Keep adding array elements while current sum is smaller than or equal to x
		while (curr_sum <= x && end < n)
			curr_sum += arr[end++];

		// If current sum becomes greater than x.
		while (curr_sum > x && start < n) {
			// Update minimum length if needed
			if (end - start < min_len)
				min_len = end - start;

			// remove starting elements
			curr_sum -= arr[start++];
		}
	}
	return min_len;
}

/* Driver program to test above function */
int main() {
	int arr1[] = { 1, 4, 45, 6, 10, 19 };
	int x = 51;
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int res1 = smallestSubWithSum(arr1, n1, x);
	(res1 == n1 + 1) ? cout << "Not possible\n"
					: cout << res1 << endl;

	int arr2[] = { 1, 10, 5, 2, 7 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	x = 9;
	int res2 = smallestSubWithSum(arr2, n2, x);
	(res2 == n2 + 1) ? cout << "Not possible\n"
					: cout << res2 << endl;

	int arr3[] = { 1, 11, 100, 1, 0, 200, 3, 2, 1, 250 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	x = 280;
	int res3 = smallestSubWithSum(arr3, n3, x);
	(res3 == n3 + 1) ? cout << "Not possible\n"
					: cout << res3 << endl;

	return 0;
}
