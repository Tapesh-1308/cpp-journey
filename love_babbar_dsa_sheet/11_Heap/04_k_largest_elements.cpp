// C++ code for k largest/ smallest elements in an array
#include <bits/stdc++.h>
using namespace std;

// Function to find k largest array element
void kLargest(vector<int>& v, int N, int K)
{
	// Implementation using
	// a Priority Queue
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < N; ++i) {

		// Insert elements into
		// the priority queue
		pq.push(v[i]);

		// If size of the priority
		// queue exceeds k
		if (pq.size() > K) {
			pq.pop();
		}
	}

	// Print the k largest element
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

// Function to find k smallest array element
void kSmalest(vector<int>& v, int N, int K)
{
	// Implementation using
	// a Priority Queue
	priority_queue<int> pq;

	for (int i = 0; i < N; ++i) {

		// Insert elements into
		// the priority queue
		pq.push(v[i]);

		// If size of the priority
		// queue exceeds k
		if (pq.size() > K) {
			pq.pop();
		}
	}

	// Print the k smallest element
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
}

// driver program
int main()
{
	// Given array
	vector<int> arr
		= { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
	// Size of array
	int n = arr.size();
	int k = 3;
	cout << k << " largest elements are : ";
	kLargest(arr, n, k);
	cout << k << " smallest elements are : ";
	kSmalest(arr, n, k);
}

// This code is contributed by Pushpesh Raj.
