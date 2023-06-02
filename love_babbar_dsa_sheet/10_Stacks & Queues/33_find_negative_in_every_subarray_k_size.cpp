// C++ implementation to find the first negative
// integer in every window of size k
#include <bits/stdc++.h>
using namespace std;

// Approach using queue TC O(N) SC O(K)

// function to find the first negative
// integer in every window of size k
void printFirstNegativeInteger(int arr[], int n, int k) {
    // A Queue q that will store indexes of
    // useful array elements for the current window of size
    // k. The useful elements are all negative integers.
    queue<int> q;

    // Process first k (or first window) elements of array
    int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of q
        // if it is a negative integer
        if (arr[i] < 0)
            q.push(i);

    // Process rest of the elements, i.e., from arr[k] to
    // arr[n-1]
    for (; i < n; i++) {
        // if q is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!q.empty())
            cout << arr[q.front()] << " ";

        // else the window does not have a
        // negative integer
        else
            cout << "0"
                 << " ";

        // Remove the elements which are out of this window
        while ((!q.empty()) && q.front() < (i - k + 1))
            q.pop();  // Remove from front of queue

        // Add current element at the rear of q
        // if it is a negative integer
        if (arr[i] < 0)
            q.push(i);
    }

    // Print the first negative
    // integer of last window
    if (!q.empty())
        cout << arr[q.front()] << " ";
    else
        cout << "0"
             << " ";
}

// Approach Optimized TC O(N) SC O(1)
void printFirstNegativeInteger(int arr[], int k, int n) {
    int firstNegativeIndex = 0;
    int firstNegativeElement;

    for (int i = k - 1; i < n; i++) {
        // skip out of window and positive elements
        while ((firstNegativeIndex < i) && (firstNegativeIndex <= i - k || arr[firstNegativeIndex] >= 0)) {
            firstNegativeIndex++;
        }

        // check if a negative element is found, otherwise
        // use 0
        if (arr[firstNegativeIndex] < 0) {
            firstNegativeElement = arr[firstNegativeIndex];
        } else {
            firstNegativeElement = 0;
        }
        cout << firstNegativeElement << " ";
    }
}


// Driver program to test above functions
int main() {
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    return 0;
}