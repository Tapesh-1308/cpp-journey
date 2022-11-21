// divide the set in two subsets of n/2 sizes each such that the absolute difference of the sum of two subsets is as minimum as possible.
#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(2^n) , two choices at every step
// Space Complexity : O(n), Stack space required 

// recursive function which returns the minimum absolute diffrence between two subsets having n/2 size of array 

/* takes ->
  *  current sum -> which keeps track of sum of created sum
  *  current size -> keeps track of size of created subset
  *  n -> it is the size of input array, using here as index range (n to 0)
  *  total sum -> it is the totol sum of input array
  *  reach -> store the required size of subset, it can be (n/2) in case of even and (n+1)/2 or (n-1)/2 in case of odd
  *  arr -> input array
*/

int solve(int curr_sum, int curr_size, int n, int total_sum, int reach, vector<int> &arr) {
    // base case
    if (n == 0) // if no elements remaing in array return intmax
        return INT_MAX;

    // if subset size reached half size
    if (curr_size == reach) {
        //  absolute diff(remaining element sum - current sum)
        return abs((total_sum - curr_sum) - curr_sum);
    }

    // return the min of including of the current element in subset or excluding the current element in the subset
    return min (
            // add curr element value to sum , increment subset size, decrement index
        solve(curr_sum + arr[n - 1], curr_size + 1, n - 1, total_sum, reach, arr), // including
            // no addition, size remains same, dec index
        solve(curr_sum, curr_size, n - 1, total_sum, reach, arr) // excluding
    );
}


int tug_of_war(vector<int> &arr, int n) {
    /* calculate total sum */
    int total_sum = 0;
    for (auto i : arr)
        total_sum += i;

    /* if we have even size of arr*/
    if (n % 2 == 0)
        // call recursive function to make partition at n/2 subset size 
        return solve(0, 0, n, total_sum, n / 2, arr);
    
    /* in case of odd size */
    else
        // call recursive function to make partition at minimum sum of (n-1 / 2) subset size or (n+1 / 2) subset size
        return min (
            solve(0, 0, n, total_sum, (n + 1) / 2, arr), 
            solve(0, 0, n, total_sum, (n - 1) / 2, arr)
        );

}

int main() {
    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};

    cout << tug_of_war(arr, arr.size());
    return 0;
}