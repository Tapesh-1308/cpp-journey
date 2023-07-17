// C++ program to find minimum sum of two numbers
// formed from digits of the array.

#include <bits/stdc++.h>
using namespace std;

// TC -> O(nlogn)
// SC -> (n)


// Function to find and return minimum sum of
// two numbers formed from digits of the array.
int solve(int arr[], int N)
{
	// Sort the array
	sort(arr, arr + N);

	// Let two numbers be a and b
	int a = 0, b = 0;
	for (int i = 0; i < N; i++) {
		// fill a and b with every alternate digit
		// of input array
		if (i & 1)
			a = a * 10 + arr[i];
		else
			b = b * 10 + arr[i];
	}

	// return the sum
	return a + b;
}

// Driver's code
int main()
{
	int arr[] = { 6, 8, 4, 5, 2, 3 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Sum is " << solve(arr, N);
	return 0;
}
