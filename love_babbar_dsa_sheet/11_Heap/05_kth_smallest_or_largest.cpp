// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;

/**
 * Approach : Kth Smallest - Using MAX-Heap
 * 			  Kth Largest  - Using MIN-Heap
 * Time Complexity : O(NlogK)
 * Space Complexity : O(K)
*/

// Function to find the kth smallest array element
int kthSmallest(int arr[], int N, int K)
{

	// For finding min element we need (Max heap)priority
	// queue
	priority_queue<int> pq;

	for (int i = 0; i < K; i++) {
		// First push first K elements into heap
		pq.push(arr[i]);
	}
	// Now check from k to last element
	for (int i = K; i < N; i++) {

		// If current element is < top that means
		// there are other k-1 lesser elements
		// are present at bottom thus, pop that element
		// and add kth largest element into the heap till
		// curr at last all the greater element than kth
		// element will get pop off and at the top of heap
		// there will be kth smallest element
		if (arr[i] < pq.top()) {
			pq.pop();
			// Push curr element
			pq.push(arr[i]);
		}
	}

	// Return top of element
	return pq.top();
}

// Function to find the kth largest array element
int kthLargest(int arr[], int N, int K)
{

	// For finding min element we need (Min heap)priority
	// queue
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < K; i++) {
		// First push first K elements into heap
		pq.push(arr[i]);
	}
	// Now check from k to last element
	for (int i = K; i < N; i++) {
		if (arr[i] > pq.top()) {
			pq.pop();
			// Push curr element
			pq.push(arr[i]);
		}
	}

	// Return top of element
	return pq.top();
}

// Driver's code:
int main()
{
	int N = 10;
	int arr[N] = { 10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
	int K = 4;

	// Function call
	cout << "Kth Smallest Element is: "
		<< kthSmallest(arr, N, K);
}
