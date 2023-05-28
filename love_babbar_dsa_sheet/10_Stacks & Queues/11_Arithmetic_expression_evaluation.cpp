#include <bits/stdc++.h> 
using namespace std;

/**
 * Function of eval function TC O(1)
 * take two numbers from nums stack, say a and b, and remove them
 * take operator from ops stack, say op, and remove it
 * perform the operation and return the output (this output will get stored in nums.top)
*/
int eval(stack<int> &nums, stack<char> &ops) {
	int a = nums.top();
	nums.pop();

	int b = nums.top();
	nums.pop();

	char op = ops.top();
	ops.pop();

	switch (op) {
		case '+':
			return b+a;
			break;
		case '-':
			return b-a;
			break;
		case '*':
			return b*a;
			break;
		case '/':
			return b/a;
			break;
	}
	return -1;
}

/** 
 * we have / * + - operator, where / * precedence is highest(2) then + -(1), else lowest(-1)
 * TC O(1)
*/
int precedence(char c) {
	if(c == '/' || c == '*') return 2;
	else if(c=='+' || c=='-') return 1;
	return -1;
}

/** Approach 1, using two stacks, TC O(N), SC O(N)
 * Take two stacks nums (stores numbers) and ops (stores ( and operators)
 * Traverse the expression
 *      if s[i] is a number
 *          extract complete number, and push in nums stack
 *      if s[i] is an open parenthesis -> (
 *          push that into ops stack
 *      if s[i] is a close parenthesis -> )
 *          then evaluate expression using eval() function till we get open braces in ops stack
 *      if s[i] is an operator 
 *          if curr operator precedance in smaller than ops'top operator then
 *           evaluate till ops.top's precedence become smaller, after than push the operator
 * After traversing all expression there might be some operators left in ops, so evaluate that too.
 * return the nums.top, as we are maintaing our ans in nums
 * */

int evaluateArithmeticExpression(string &s) 
{
	stack<int> nums;
	stack<char> ops;

	for(int i=0; i<s.size(); i++) {
		char c = s[i];
		if(isdigit(c)) {
			string num = "";
			while(s[i] >= '0' && s[i] <= '9') {
				num += s[i++];
			}

			int int_num = stoi(num);
			nums.push(int_num);
			i--;
		}

		else if(c == '(')
			ops.push(c);
		
		else if(c == ')') {
			while (!ops.empty() && ops.top() != '(') 
				nums.push(eval(nums, ops));
                  
            ops.pop();
		}
		else {
			while(!ops.empty() && precedence(c) < precedence(ops.top())) 
				nums.push(eval(nums, ops));
			ops.push(c);
		}
	}
	while(!ops.empty())
		nums.push(eval(nums, ops));

	return nums.top();
}

/**
 * Another Approach using Infix to postfix or prefix, TC O(N) SC (N)
*/