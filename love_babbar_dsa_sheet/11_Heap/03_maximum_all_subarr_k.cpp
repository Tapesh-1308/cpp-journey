#include <bits/stdc++.h>
using namespace std;

/**
 * Approach #1 : Brute Force
 * TC : O(N * K)
 * SC : O(1)
*/
void printKMax(int arr[], int N, int K)
{
	int j, max;

	for (int i = 0; i <= N - K; i++) {
		max = arr[i];

		for (j = 1; j < K; j++) {
			if (arr[i + j] > max)
				max = arr[i + j];
		}
		cout << max << " ";
	}
}

/**
 * Approach #2 : Using Deque
 * TC : O(N)
 * SC : O(K)
*/

void printKMax(int arr[], int N, int K)
{
 
 /**
  * Create a Double Ended Queue, Qi that will store indexes of array elements 
  * The queue will store indexes of useful elements in every window 
  * It will maintain decreasing order of values from front to rear in Qi, 
  * i.e., arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
 */
   
    deque<int> Qi(K);
 
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < K; ++i) {
        // For every element, the previous smaller elements are useless so remove them from Qi
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            // Remove from rear
            Qi.pop_back();
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < N; ++i) {
        // The element at the front of the queue is the largest element of previous window, so print it
        cout << arr[Qi.front()] << " ";
 
        // Remove the elements which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - K)
            // Remove from front of queue
            Qi.pop_front();
 
        // Remove all elements smaller than the currently being added element (remove useless elements)
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
        // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element of last window
    cout << arr[Qi.front()];
}


/**
 * Approach #3 : Using Max-Heap
 * TC : O(NlogK)
 * SC : O(K)
*/

void printKMax(int arr[], int N, int K)
{
    priority_queue<pair<int, int> > heap;
 
    // Initialize the heap with the first k elements
    for (int i = 0; i < K; i++)
        heap.push({ arr[i], i });
 
    // The maximum element in the first window
    cout << heap.top().first << " ";
 
    // Process the remaining elements
    for (int i = K; i < N; i++) {
        // Remove elements that are outside the current window
        while (!heap.empty() && heap.top().second <= i - K)
            heap.pop();
 
        // Add the current element to the heap
        heap.push({ arr[i], i });
 
 
        // The maximum element in the current window
        cout << heap.top().first << " ";
    }
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	// Function call
	printKMax(arr, N, K);
	return 0;
}

