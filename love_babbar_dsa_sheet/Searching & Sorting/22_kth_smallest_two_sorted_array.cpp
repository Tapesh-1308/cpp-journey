#include <bits/stdc++.h>
using namespace std;

// Method - 1 Merge Two Sorted Arrays - TC O(m+n) SC O(m+n)
int kthElement(int arr1[], int arr2[], int m, int n, int k) {
	int sorted1[m + n]; // To store merged array
	int i = 0, j = 0, d = 0;
	// i -> arr1, j -> arr2, d -> sortedArr

	// Merge two sorted array technique
	while (i < m && j < n) {
		if (arr1[i] < arr2[j])
			sorted1[d++] = arr1[i++];
		else
			sorted1[d++] = arr2[j++];
	}
	while (i < m)
		sorted1[d++] = arr1[i++];
	while (j < n)
		sorted1[d++] = arr2[j++];
	
	// return k-1 from merged sorted array
	return sorted1[k - 1];
}

// Method - 2  Two Pointer - TC O(k) SC O(1)
int kthElement(int arr1[], int arr2[], int m, int n, int k) {
    int i=0, j=0, count=0;
    // i->arr1, j->arr2, count->count number element we traversed
	// We have to traverse only k element
    while( i<m && j<n ) {
		// if array1 element is less than array2 element increment count and array1 pointer
		// Also check if we traversed all k element i.e. count == k, then return array1 of i
        if(arr1[i] < arr2[j]) {
            count++;
            if(count == k)
                return arr1[i];
            i++;
        }
		// Same thing if array2 element is smaller than array1 element
        else {
            count++;
            if(count == k)
                return arr2[j];
            j++;
        }
    }
    
	// If array2 is completely traverse and some elements remaining in array1
    while(i<m) {
        count++;
        if(count == k)
            return arr1[i];
        i++;
    }
    
	// If array1 is completely traverse and some elements remaining in array2
    while(j<n) {
        count++;
        if(count == k)
            return arr2[j];
        j++;
    }
    return -1;
}

// Method - 3 Binary Search - TC O(log(min(n, m))) SC O(1)
int kthElement(int arr1[], int arr2[], int m, int n, int k) {
	// to run only for smaller array length
    if(m > n) {
        return kthElement(arr2, arr1, n, m, k); 
    }
    // low -> minimum element we can take left side 
	// if 2nd array length is less than k than we can't take 0 element in array1 so take max of 0, k-m

	// high -> maximum element we can take right side
	// if k is lesser than array1 size than we can't take all elements of array1 in one side, so high = minimum of k, n
    int low = max(0,k-m), high = min(k,n);
        
	// Binary search
    while(low <= high) {
		// cut1 is the separating point for array1
        int cut1 = (low + high) >> 1; // mid of low and high
		// cut2 is the separating point for array2
        int cut2 = k - cut1; // cut1 + cut2 = k -> k - cut1 = cut2

		// rightmost point of array1 in leftside of cut1 -> l1
		// rightmost point of array2 in leftside of cut2 -> l2
		// -> intmin if cut is on first of array
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
		// leftmost point of array1 in rightside of cut1 -> r1
		// leftmost point of array2 in rightside of cut2 -> r2
		// -> intmax if cut is on last of array
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
		// Validity condition of cuts
        if(l1 <= r2 && l2 <= r1) {
			// If valid return maximum of l1 and l2
            return max(l1, l2);
        }
		// If l1 is greater than r2 which means we need less element, smaller element will be on left side so remove right side high = cut1-1
        else if (l1 > r2) {
            high = cut1 - 1;
        }
		// Else remove left part 
        else {
            low = cut1 + 1; 
        }
    }
    return -1; 
}

int main() {
	int arr1[5] = {2, 3, 6, 7, 9};
	int arr2[4] = {1, 4, 8, 10};
	int k = 5;
	cout << kthElement(arr1, arr2, 5, 4, k);
	return 0;
}
