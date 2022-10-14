// CPP program to find minimum number of elements such that their sum is greater
// than sum of remaining elements of the array.
#include <bits/stdc++.h>
using namespace std;

// function to find minimum elements needed.
int minElements(vector<int> &arr, int n)
{
    // sort the input
    sort(arr.begin(), arr.end());

    // calculate the whole arrey sum
    long long int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];
    
    // if array contains one element, return 1
    if (n == 1)
        return 1;

    // rightsum calculate sum from last 
    long long int rightsum = 0;
    // stores minimum number of elements  
    int ans = 0;

    // start iterating from the last
    for(int i=n-1; i>=0; i--) {
        // decrease totalsum by arr[i] and increase rightsum by arr[i]
        rightsum += arr[i];
        totalSum -= arr[i];

        // increment ans, taking another element
        ans++;

        // where rightsum becomes greater than totalsum return ans
        if(rightsum>totalSum) return ans;
    }

    // return n as answer 
    return n;
}

// Driver function
int main()
{
    vector<int> arr = {3, 1, 7, 1};
    int n = arr.size();
    cout << minElements(arr, n) << endl;
    return 0;
}
