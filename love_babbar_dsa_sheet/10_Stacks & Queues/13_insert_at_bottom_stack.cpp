// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), where N is the total number of elements in the stack.
// Auxiliary Space: O(N)

// Recursive function to use implicit stack
// to insert an element at the bottom of stack
stack<int> recur(stack<int> S, int N) {
    // If stack is empty
    if (S.empty())
        S.push(N);

    else {
        // Stores the top element
        int X = S.top();

        // Pop the top element
        S.pop();

        // Recurse with remaining elements
        S = recur(S, N);

        // Push the previous
        // top element again
        S.push(X);
    }
    return S;
}

// Function to insert an element
// at the bottom of stack
void insertToBottom(stack<int> S, int N) {
    // Recursively insert
    // N at the bottom of S
    S = recur(S, N);

    // Print the stack S
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}

// Driver Code
int main() {
    // Input
    stack<int> S;
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);

    int N = 7;

    insertToBottom(S, N);

    return 0;
}
