// C++ program to find the K-th largest sum
// of subarray
#include <bits/stdc++.h>
using namespace std;

// Function to calculate Kth largest element
// in contiguous subarray sum
int kthLargestSum(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int sum;
    
    for(int i=0; i<n; i++) {
        sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            
            pq.push(sum);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    return pq.top();
}

// Driver's code
int main()
{
	int a[] = { 10, -10, 20, -40 };
	int N = sizeof(a) / sizeof(a[0]);
	int K = 6;

	// Function call
	cout << kthLargestSum(a, N, K);
	return 0;
}
