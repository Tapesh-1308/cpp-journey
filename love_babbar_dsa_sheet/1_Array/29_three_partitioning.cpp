#include<iostream>
using namespace std;

//Approach - DNF Sort (Ducth Nation Flag) TC O(N) SC O(1)

// Partitions arr[0..n-1] around [lowVal..highVal]
void threeWayPartition(int arr[], int n, int lowVal, int highVal) {
	// Initialize ext available positions for smaller (than range) and greater elements
	int lo = 0, mid = 0, hi = n-1;

	// Traverse elements from left
	while(mid<=hi) {
		// If current element is smaller than range, put it on next available smaller position.
		if (arr[mid] < lowVal) {
            //if i and start are same in that case we can't swap, swap only if i is greater than start
            if(mid==lo) {
                lo++;
                mid++;
            }
            else swap(arr[mid++], arr[lo++]);
		}

		// If current element is greater than range, put it on next available greater position.
		else if (arr[mid] > highVal)
			swap(arr[mid], arr[hi--]);

		else
			mid++;
	}
}


int main() {
	int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
	int n = sizeof(arr)/sizeof(arr[0]);

	threeWayPartition(arr, n, 10, 20);

	cout << "Modified array \n";
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
}
