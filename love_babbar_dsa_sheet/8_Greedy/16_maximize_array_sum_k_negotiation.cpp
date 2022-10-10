// C++ program to maximiz array sum after k negotiations
#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(nlogn)
// Space Complexity - O(1)

// Function to calculate sum of the array
long long int sumArray(long long int* arr, int n)
{
	long long int sum = 0;

	// Iterate from 0 to n - 1
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

// Function to maximize sum
long long int maximizeSum(long long int arr[], int n, int k)
{
	sort(arr, arr + n);
	int i = 0;

	// Iterate from 0 to n - 1
	for (i = 0; i < n; i++) {
        // convert neg numbers to pos, k times
		if (k && arr[i] < 0) {
			arr[i] *= -1;
			k--;
			continue;
		}
		break;
	}
    // if reach end, move i 1 step back to use k
	if (i == n)
		i--;

    // if k is even or 0, calculate sum
	if (k == 0 || k % 2 == 0)
		return sumArray(arr, n);

    // find minimum of current and prev and point i to minimum 
	if (i != 0 && abs(arr[i]) >= abs(arr[i - 1]))
		i--;

    // make minimum number neg 
	arr[i] *= -1;

    // calculate sum
	return sumArray(arr, n);
}

// Driver Code
int main()
{
	int n = 5;
	int k = 4;
	long long int arr[5] = { -2, 0, 5, -1, 2 };
	// Function Call
	cout << maximizeSum(arr, n, k) << endl;
	return 0;
}

