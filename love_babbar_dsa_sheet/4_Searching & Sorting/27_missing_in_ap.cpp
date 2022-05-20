#include <bits/stdc++.h>
using namespace std;

// Method - 1 Linear search TC O(N) SC O(1)
int findMissing(int arr[], int n) {
    // a is the first element and l is the last element
    // sum stores sum of ap without a missing number
    // s store sum of given array with missing number
    int a = arr[0], l = arr[n-1], sum=0, s=0;
    
    // Sum of Ap formula = n/2 *  (a+l)
    // Here we use n+1 because the array size we are given is smaller by 1 as one element is missing

    // If (a+l) is even
    if((a+l)%2 == 0) 
        // We will divide (a+l) by  2 not n+1
        sum = (a+l)/2 * (n+1);
    
    // If a+l is odd
    else 
        // We will divide n+1 by 2 not a+l
        sum = (n+1)/2 * (a+l);
    
    // Calculating input array sum
    for(int i=0; i<n; i++)
        s += arr[i];

    // return the differnce of sum which is missing value
    return sum-s;
}

// Method - 2 Binary Search TC O(logN) SC O(1)
int findMissing(int arr[], int n) {
    // diff -> common difference // formula -> (l-a) / n-1
    // Here we use only n because we are already given 1 lesser size

    int a = arr[0], l = arr[n-1];
	int diff = (l - a) / n;

    // Search space from 0th element to last element
    int lo = 0, hi = n-1;
    int mid;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2 ;
        
        // If neighbour is missing number 
        // -> Formula - arr[mid+1] - arr[mid] = diff  
        if(arr[mid]+diff != arr[mid+1]) // if not equal
            return arr[mid] + diff; 

        // If arr[mid] - arr[mid-1] not equal to diff
        if(mid > 0 && arr[mid]-diff != arr[mid-1])
            return arr[mid]-diff;
        
        // If middle element not in neighbours then only we execute this statement
        // if middle element is on correct position arr[mid] = a + (n-1) * d, n-1 is mid
        if(arr[mid] == a + diff*mid)
            lo = mid + 1; // then search in right side because from 0 to mid all elements are on correct pos means we to search in right side
        else 
            // If arr[mid] is not  on its correct position means from 0 to mid someone is missing so search in left side
            hi = mid - 1;
        
    }

    // Answer will be on ar[hi] + diff or ar[lo] - diff as lo > hi  
    return arr[hi]+diff;
}

int main() {
	int arr[] = {2,4,8,10,12,14,16,18};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<< "Missing Number is: " << findMissing(arr, n);
	return 0;
}
