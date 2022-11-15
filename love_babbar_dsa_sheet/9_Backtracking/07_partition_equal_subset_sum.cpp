// A recursive C++ program for partition problem
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^n) In the worst case, this solution tries two possibilities (whether to include or exclude) for every element.
// Space Complexity: O(n^2) Maximum number of calls 

// A utility function that returns true if there is
// a subset of arr[] with sum equal to given sum
bool isSubsetSum(int arr[], int n, int sum)
{
	// Base Cases
	if (sum == 0) // if sum becomes 0, means subset exists
		return true;

    // if complete array exhausted but sum is not equal to 0, means these subset sum is not our ans
	if (n == 0 && sum != 0) // so return false
		return false;

	// If last element is greater than sum, then ignore it
	if (arr[n - 1] > sum)
		return isSubsetSum(arr, n - 1, sum);

	/* else, check if sum can be obtained by any of
		the following
		(a) excluding the last element
		(b) including the last element
	*/
	return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
	// Calculate sum of the elements in array
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// If sum is odd, there cannot be two subsets
	// with equal sum
	if (sum % 2 != 0)
		return false;

	// Find if there is subset with sum equal to
	// half of total sum
	return isSubsetSum(arr, n, sum / 2);
}

int main()
{
	int arr[] = { 3, 1, 5, 9, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	if (findPartiion(arr, n) == true)
		cout << "Can be divided into two subsets " "of equal sum";
	else
		cout << "Can not be divided into two subsets" " of equal sum";
	return 0;
}
