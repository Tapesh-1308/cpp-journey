// check whether an array can be partitioned into K subsets of equal sum
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^nk)
// Space Commplexity: O(nk)

// recursive function -> it will generate a subset with sum (array sum / k), ans recursively call
// itself for remaining k-1 subsets
bool solve(int idx, int sum, int reqSum, int k, int arr[], vector<bool> &visited, int n) {
    // if k becomes 0 (all partitions made), return true
    if (k == 0)
        return true;

    // if curr subset sum = required sum, then call for next subset
    if (sum == reqSum)
        // by decrementing k
        return solve(0, 0, reqSum, k - 1, arr, visited, n);

    // if sum becomes greater then required or index reached end 
    // but sum is still not equal to required return false
    if (sum > reqSum || idx >= n)
        return false;

    // if current index is already visited then continue fcall for next index
    if (visited[idx])
        return solve(idx + 1, sum, reqSum, k, arr, visited, n);

    // Case : 1 By including current element 

    // mark as visited
    visited[idx] = 1;

    // add current element with sum     
    bool incl = solve(idx + 1, sum + arr[idx], reqSum, k, arr, visited, n);

    // backtrack
    visited[idx] = 0;

    // Case : 2 By excluding current element

    // no addition
    bool excl = solve(idx + 1, sum, reqSum, k, arr, visited, n);

    // return false only when both incl and excl are false
    return incl || excl;
}

// wrapper function over solve()
bool isKPartitionPossible(int arr[], int n, int k) {
    // if k is 1 then no partition required return true
    if (k == 1)
        return true;

    // calculate array sum
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // if sum is not the multiple of k or k is greater then array size
    // then partition is not possible
    if (sum % k != 0 || k > n)
        return false;

    // create a visited boolean array of n size
    vector<bool> visited(n, 0);

    // try to make k partitions (if possible return true else false) 
    // solve(index, curr_sum, required_sum, array, visited array, size)
    return solve(0, 0, sum / k, k, arr, visited, n);
}

int main() {
    int arr[] = {2, 1, 4, 5, 3, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    if (isKPartitionPossible(arr, N, K))
        cout << "Partitions into equal sum is possible.\n";
    else
        cout << "Partitions into equal sum is not possible.\n";
}