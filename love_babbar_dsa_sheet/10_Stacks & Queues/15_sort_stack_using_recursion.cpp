#include <bits/stdc++.h>
using namespace std;

// The time complexity of the above solution is O(n2) and requires O(n) implicit space for the call stack, where n is the total number of elements in the stack.

// Insert the given key into the sorted stack while maintaining its sorted order.
// This is similar to the recursive insertion sort routine
void sortedInsert(stack<int> &stack, int key) {
    // base case: if the stack is empty or
    // the key is greater than all elements in the stack
    if (stack.empty() || key > stack.top()) {
        stack.push(key);
        return;
    }

    /* We reach here when the key is smaller than the top element */

    // remove the top element
    int top = stack.top();
    stack.pop();

    // recur for the remaining elements in the stack
    sortedInsert(stack, key);

    // insert the popped element back into the stack
    stack.push(top);
}

// Recursive method to sort a stack
void sortstack(stack<int> &stack) {
    // base case: stack is empty
    if (stack.empty()) {
        return;
    }

    // remove the top element
    int top = stack.top();
    stack.pop();

    // recur for the remaining elements in the stack
    sortstack(stack);

    // insert the popped element back into the sorted stack
    sortedInsert(stack, top);
}

void printStack(stack<int> stack) {
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main() {
    vector<int> list = {5, -2, 9, -7, 3};

    stack<int> stack;
    for (int i : list) {
        stack.push(i);
    }

    cout << "Stack before sorting: ";
    printStack(stack);

    sortstack(stack);

    cout << "Stack after sorting: ";
    printStack(stack);

    return 0;
}
