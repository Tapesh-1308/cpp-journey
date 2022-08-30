// Find the minimum and maximum amount to buy all N candies
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum amount
// to buy all candies
int findMinimum(int arr[], int n, int k)
{
	int res = 0, index = n-1;
	for (int i = 0; i <= index; i++) {
		// Buy current candy
		res += arr[i];

		// And take k candies for free
		// from the last
		index -= k;
	}
	return res;
}

// Function to find the maximum amount
// to buy all candies
int findMaximum(int arr[], int n, int k)
{
	int res = 0, index = 0;

	for (int i = n - 1; i >= index; i--)
	{
		// Buy candy with maximum amount
		res += arr[i];

		// And get k candies for free from
		// the starting
		index += k;
	}
	return res;
}

int main()
{
	int arr[] = { 3, 2, 1, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
    
	sort(arr, arr + n);

	// Function call
	cout << findMinimum(arr, n, k) << " "
		<< findMaximum(arr, n, k) << endl;
	return 0;
}
