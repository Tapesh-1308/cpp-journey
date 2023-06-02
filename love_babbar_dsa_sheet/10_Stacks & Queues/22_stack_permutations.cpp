#include <bits/stdc++.h>
using namespace std;

// Approach Using Stack TC O(N) SC O(N)
// function to check if input array is
// permutable to output array
bool checkStackPermutation(int ip[], int op[], int n) {
    // we will be pushing elements from input array to stack uptill top of our stack
    // matches with first element of output array
    stack<int> s;

    // will maintain a variable j to iterate on output array
    int j = 0;

    // will iterate one by one in input array
    for (int i = 0; i < n; i++) {
        // pushed an element from input array to stack
        s.push(ip[i]);
        // if our stack isn't empty and top matches with output array
        // then we will keep popping out from stack uptill top matches with
        // output array
        while (!s.empty() and s.top() == op[j]) {
            s.pop();
            // increasing j so next time we can compare next element in output array
            j++;
        }
    }

    // if output array was a correct permutation of input array then
    // by now our stack should be empty
    if (s.empty()) {
        return true;
    }
    return false;
}

// Driver program to test above function
int main() {
    // Input Array
    int input[] = {4, 5, 6, 7, 8};

    // Output Array
    int output[] = {8, 7, 6, 5, 4};

    int n = 5;

    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}
