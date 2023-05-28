#include <bits/stdc++.h>
using namespace std;

bool is_op(char c) {
    return c == '+' || c=='-' || c=='*' || c=='/';
}

// Function to check redundant brackets in a balanced expression
bool checkRedundancy(string& str) {
	// create a stack of characters
	stack<char> st;

	// Iterate through the given expression
	for (auto& ch : str) {

		// if current character is close parenthesis ')'
		if (ch == ')') {
			// If immediate pop have open parenthesis '('
			// duplicate brackets found
			bool flag = true;

			while (!st.empty() and st.top() != '(') {
				// Check for operators in expression
				if (is_op(st.top())) flag = false;

				// remove top element of stack
				st.pop();
			}
            st.pop(); // remove open braces
			// If operators not found
			if (flag == true)
				return true;
		}

		else
			st.push(ch); // push open parenthesis '(', operators and operands to stack
	}
	return false;
}

int main() {
	string str = "((a+b))";
	checkRedundancy(str);
	return 0;
}
