// Find minimum number of reversals required to balance an expression
#include <bits/stdc++.h>
using namespace std;

// Returns count of minimum reversals for making expr balanced. Returns -1 if expr cannot be balanced.

/* Method 1 Using Stack TC O(n) SC O(n)
int countMinReversals(string str) {
    // Step 1: Initialize a stack of char type and ans as 0.
    stack<char> st;
    int ans = 0;
 
    // Step 2: Run a loop for each character of the string
    for (int i = 0; i < str.size(); i++) {
        // Step 2.1: If ' { ' encountered push it to the stack
        if (str[i] == '{')
            st.push(str[i]);
        // Step 2.2: If ' } ' is encountered
        else {
            // Step 2.2.1: If stack has a '{' present for '}' encountered, pop from the stack.
            if (!st.empty())
                st.pop();
            // Step 2.2.2: If stack is empty, change '}' to '{' and push it to stack and increment ans by 1
            else {
                st.push('{');
                ans++;
            }
        }
    }
    // Step 3: if stack size is odd return -1.
    if (st.size() % 2 != 0)
        return -1;
    // Step 4: Increment ans by ( stackSize/2 ).
    ans += st.size() / 2;
    return ans;
} */


/* Method 2 2-Counter TC O(n) SC O(1)
int countMinReversals(string expr) {
    int len = expr.length();
 
    // Expressions of odd lengths cannot be balanced
    if (len % 2 != 0) {
        return -1;
    }
    int left_brace = 0, right_brace = 0;
    int ans;
    for (int i = 0; i < len; i++) {
 
        // If we find a left bracket then we simply increment the left bracket
        if (expr[i] == '{') {
            left_brace++;
        }
 
        // Else if left bracket is 0 then we find unbalanced right bracket and increment
        // right bracket or if the expression is balanced then we decrement left
        else {
            if (left_brace == 0) 
                right_brace++;
            
            else
                left_brace--;
        }
    }
    ans = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
    return ans;
} */


//Method 3 1-Counter TC O(n) SC O(1)
int countMinReversals(string s) {
	int temp = 0, res = 0, n = s.size();
	if (n % 2 != 0)
		return -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '{')
			temp++;
		else {
			if (temp == 0) {
				res++;
				temp++;
			}
			else
				temp--;
		}
	}
	if (temp > 0)
		res += temp / 2;
	return res;
}


int main() {
	string expr = "}}{{";
	cout << countMinReversals(expr);
	return 0;
}
