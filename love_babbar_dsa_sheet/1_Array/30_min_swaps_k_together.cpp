// Find minimum swaps required to club all elements less than or equals to k together
#include <bits/stdc++.h>
using namespace std;



int minSwap(int arr[], int n, int k) {

    /* Method 1 Brute Force TC O(N^2) SC O(1)
    int goodCount=0; 
    for (int i = 0; i < n; i++)
        if(arr[i]<=k) 
            goodCount++;
    
    int ans=INT_MAX;
    int badCount;
    for (int i = 0; i < n-goodCount+1; i++){
        badCount=0;
        for (int j = i; j < i+goodCount; j++)
            if(arr[j]>k)  
                badCount++;
        
        ans = min(ans, badCount);
    }
    return  ans; */

    //Method 2 Sliding Window TC O(N) SC O(1)
	// Find count of elements which are less than equals to k
	int count = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] <= k)
			count++;
	
	// Find unwanted elements in current window of size 'count'
	int bad = 0;
	for (int i = 0; i < count; i++)
		if (arr[i] > k)
			bad++;
	
	// Initialize answer with 'bad' value of current window
	int ans = bad; 
    int i=0, j=count;

	while(j<n){
		// Decrement count of previous window
		if (arr[i] > k)
			bad--;
		
		// Increment count of current window
		if (arr[j] > k)
			bad++;
		
		// Update ans if count of 'bad' is less in current window
		ans = min(ans, bad);

        i++; j++;
	}
	return ans;
}


int main() {
	
	int arr[] = {2, 1, 5, 6, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << minSwap(arr, n, k) << "\n";
	
	int arr1[] = {2, 7, 9, 5, 8, 7, 4};
	n = sizeof(arr1) / sizeof(arr1[0]);
	k = 5;
	cout << minSwap(arr1, n, k);
	return 0;
}
