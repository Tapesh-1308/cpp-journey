// Maximum sum of absolute difference
#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Using Separate vector - TC O(nlogn) SC O(n)
int MaxSumDifference(int a[], int n)
{
	// final sequence stored in the vector
	vector<int> finalSequence;

	// sort the original array so that we can retrieve
	// the large elements from the end of array elements
	sort(a, a + n);

	/*
     * In this loop first we will insert one smallest element in final sequence
	 * and then enter a highest element in final sequence so that we have large 
     * difference value. This process is repeated till all array has completely 
     * entered in sequence. Here, we have loop till n/2 because we are inserting 
     * two elements at a time in loop. 
     */ 

	for (int i = 0; i < n / 2; ++i) {
		finalSequence.push_back(a[i]);
		finalSequence.push_back(a[n - i - 1]);
	}

	// If there are odd elements, push the middle element (remaining) at the end.
	if (n % 2 != 0)
		finalSequence.push_back(a[n/2]);

	// variable to store the maximum sum of absolute difference
	int MaximumSum = 0;

	// In this loop absolute difference of elements for the final sequence is calculated.
	for (int i = 0; i < n - 1; ++i) {
		MaximumSum = MaximumSum + abs(finalSequence[i] - finalSequence[i + 1]);
	}

	// absolute difference of last element and 1st element
	MaximumSum = MaximumSum + abs(finalSequence[n - 1] - finalSequence[0]);

	// return the value
	return MaximumSum;
}

// Approach 2 - Two Pointers - TC O(nlogn) SC O(1)
int MaxSumDifference(int a[], int n)
{
    // sort the imput
    sort(a, a + n);

    // first and last index
    int i = 0, j = n - 1;

    // if true we will increment i and  if false we will decrement j
    bool flag  = true;
    int MaximumSum = 0;

    // find sum of abs differnce 
    while (i < j) {
        // calc sum
        MaximumSum += abs(a[i] - a[j]);

        // increment i if flag is true else decrement j
        if (flag) i++;
        else j--;
        
        // update flag true -> false, flase -> true
        flag = !flag;
    }

    // absolute difference of last element and 1st element
    MaximumSum += abs(a[i] - a[0]);

    // return the value
    return MaximumSum;
}


int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << MaxSumDifference(a, n) << endl;
}
