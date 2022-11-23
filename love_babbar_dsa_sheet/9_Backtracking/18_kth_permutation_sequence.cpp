// find the kth permutation sequence
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) * O(N) = O(N^2)
// Reason: We are placing N numbers in N positions. This will take O(N) time. For every number, we are reducing the search space by removing the element already placed in the previous step. This takes another O(N) time.

// Space Complexity: O(N) 
// Reason: We are storing  the numbers in a data structure(here vector)

// function to get the kth permutation sequence
string getPermutation(int n, int k) {

    // calculate the (n-1) factorial and gentrate [1...n] array
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    // we will store ans in a string
    string ans = "";

    // dec k by 1 as (0th based index)
    k = k - 1;

    // run a while loop till array size becomes 0 
    while (true) {
        // add k/fact th index  number in ans
        ans = ans + to_string(numbers[k / fact]);

        // remove this from array
        numbers.erase(numbers.begin() + k / fact);

        // if array becomes empty break out
        if (numbers.size() == 0)
            break;
        
        // update k for remaining elements
        k = k % fact;

        // update factorial as array size
        fact = fact / numbers.size();
    }

    // return generated permutation
    return ans;
}

int main() {
    int n = 3, k = 3;
    string ans = getPermutation(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;

    return 0;
}