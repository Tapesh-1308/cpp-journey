#include <bits/stdc++.h>
using namespace std;

// A job has start time, finish time and profit.
struct Job {
	int start, finish, profit;
};

// A utility function that is used for sorting events according to finish time
bool jobComparator(Job s1, Job s2) {
	return (s1.finish < s2.finish);
}

// Function find the index whose element is last compaitible with curr job that is job[i], if not found then returns -1

/* Linear Search (index = n)
int latestNonConflict(Job arr[], int i) {
    // Search from 0...i-1 in left direction <-
	for (int j=i-1; j>=0; j--)
        // If we found whose finish time is lesser or equal to curr job return its index
		if (arr[j].finish <= arr[i-1].start)
			return j;
	
    // If not found return -1
	return -1;
} */

// Binary Search (index = n-1)
int latestNonConflict(Job jobs[], int index) {
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;
   
    // Perform binary Search iteratively
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
		// Check if it is compaitible 
        if (jobs[mid].finish <= jobs[index].start) {
			// If compaitible check if it latest also or not, if not search for greater mid hence lo = mid+1
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
			// If latest return mid
            else
                return mid;
        }
		// Not compaitible, search in right left side, hence high = mid-1
        else
            hi = mid - 1;
    }
   // If not found return -1
    return -1;
}
   

// Method - 1 Recursion TC O(n*2^n) SC O(n) -> TC can be reduced to O(2^n * logn) by using binary search function

// A recursive function that returns the maximum possible profit from given array of jobs. The array of jobs must be sorted according to finish time. (Recursive Function).
int findMaxProfitRec(Job arr[], int n) {
	// Base case -> if array size is 1 return its profit
	if (n == 1) return arr[n-1].profit;

	// Find profit when current job is included
	int inclProf = arr[n-1].profit; // Taking curr job into account
	int i = latestNonConflict(arr, n); // Findin latest non conflict of curr job
	if (i != -1) // <- If found != -1
	    inclProf += findMaxProfitRec(arr, i+1); // Check for all compatibles before curr 0 to i, i+1 is size of array 
    
	// Find profit when current job is excluded
	int exclProf = findMaxProfitRec(arr, n-1);

    // Return the max of both included and excluded
	return max(inclProf, exclProf);
}

// The main function that returns the maximum possible profit from given array of jobs
int findMaxProfit(Job arr[], int n) {
	// Sort jobs according to finish time
	sort(arr, arr+n, jobComparator);

    // Call recursive function
	return findMaxProfitRec(arr, n);
}

// Method - 2 Tabulation DP - TC O(N^2) SC O(N) -> Using Binary Search TC - O(NlogN)
int findMaxProfit(Job arr[], int n) {
    // Sort jobs according to finish time
    sort(arr, arr + n, jobComparator);
 
    // Create an array to store solutions of subproblems.
    // table[i] stores the profit for jobs till arr[i]
    // (including arr[i])
    int* table = new int[n];
    table[0] = arr[0].profit;
 
    // Fill entries in M[] using recursive property
    for (int i = 1; i < n; i++) {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];
 
        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i - 1]);
    }
 
    // Store result and free dynamic memory allocated for
    // table[]
    int result = table[n - 1];
    delete[] table;
 
    return result;
}

int main() {
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The optimal profit is " << findMaxProfit(arr, n);
	return 0;
}
