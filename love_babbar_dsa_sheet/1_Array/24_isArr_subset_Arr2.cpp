// C++ program to find whether an array is subset of another array
#include <bits/stdc++.h>
using namespace std;

/* Method 1 TC O(n^2) SC O(1)

bool isSubset(int arr1[], int arr2[], int m, int n) {
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) 
			if (arr2[i] == arr1[j])
				break;
		
		//If the above inner loop was not broken at all then arr2[i] is not present in arr1[] 
		if (j == m)
			return 0;
	}

	//If we reach here then all elements of arr2[] are present in arr1[] 
	return 1;
} 
*/

/* Method 2 Sorting+Binary Search TC O(mlogm + nlogm) SC O(1)

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low)  {
        int mid = (low + high) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && (arr[mid] == x))
            return mid;
        else if (x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x);
        else
            return binarySearch(arr, low, (mid - 1), x);
    }
    return -1;
}

bool isSubset(int arr1[], int arr2[], int m, int n) {
    int i = 0;
 
    sort(arr1,arr1+m-1);
    for (i = 0; i < n; i++) {
        if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
            return 0;
    }
    // If we reach here then all elements of arr2[] are present in arr1[]
    return 1;
} */

/* Method 3 Sorting+TwoPointer TC O(mlogm + nlogn + n + m) SC O(1)
bool isSubset(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
 
    if (m < n)
        return 0;
 
    // Sort both the arrays
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
 
    // Iterate till they donot exceed their sizes
    while (i < n && j < m) {
        // If the element is smaller than Move ahead in the first array
        if (arr1[j] < arr2[i])
            j++;
        // If both are equal, then move both of them forward
        else if (arr1[j] == arr2[i]) {
            j++;
            i++;
        }
        // If we donot have a element smaller or equal to the second array then break
        else if (arr1[j] > arr2[i])
            return 0;
    }
 
    return (i < n) ? false : true;
} */

/* Method 4 Hashing TC (m+n) SC (m)  */
bool isSubset(int arr1[], int arr2[], int m, int n) {
 
    // Using STL set for hashing
    unordered_set<int> hashset;
 
    // hset stores all the values of arr1
    for (int i = 0; i < m; i++)
        hashset.insert(arr1[i]);
 
    // loop to check if all elements of arr2 also lies in arr1
    for (int i = 0; i < n; i++) 
        if (hashset.find(arr2[i]) == hashset.end())
            return false;
    
    return true;
}

int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		printf("arr2[] is subset of arr1[] ");
	else
		printf("arr2[] is not a subset of arr1[]");

	return 0;
}
