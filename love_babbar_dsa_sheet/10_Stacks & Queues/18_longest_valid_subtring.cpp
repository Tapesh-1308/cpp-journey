#include <bits/stdc++.h>
using namespace std;

// Approach using stacks TC O(N) SC O(N)
int solve(string str)
{
    int n = str.length();
 
    // Create a stack and push -1 as
    // initial index to it.
    stack<int> stk;
    stk.push(-1);
 
    // Initialize result
    int result = 0;
 
    // Traverse all characters of given string
    for (int i = 0; i < n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
         
        // If closing bracket, i.e.,str[i] = ')'
        else
        {
            // Pop the previous opening
            // bracket's index
            if (!stk.empty())
            {
                stk.pop();
            }
             
            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stk.empty())
                result = max(result, i - stk.top());
 
            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else
                stk.push(i);
        }
    }
 
    return result;
}

// Approach - 1 Optimized TC O(N) SC O(1)
// Function to return the length of
// the longest valid substring
int solve(string s, int n)
{

	// Variables for left and right counter.
	// maxlength to store the maximum length found so far
	int left = 0, right = 0, maxlength = 0;

	// Iterating the string from left to right
	for (int i = 0; i < n; i++)
	{
		// If "(" is encountered,
		// then left counter is incremented
		// else right counter is incremented
		if (s[i] == '(')
			left++;
		else
			right++;

		// Whenever left is equal to right, it signifies
		// that the subsequence is valid and
		if (left == right)
			maxlength = max(maxlength, 2 * right);

		// Resetting the counters when the subsequence
		// becomes invalid
		else if (right > left)
			left = right = 0;
	}

	left = right = 0;

	// Iterating the string from right to left
	for (int i = n - 1; i >= 0; i--) {

		// If "(" is encountered,
		// then left counter is incremented
		// else right counter is incremented
		if (s[i] == '(')
			left++;
		else
			right++;

		// Whenever left is equal to right, it signifies
		// that the subsequence is valid and
		if (left == right)
			maxlength = max(maxlength, 2 * left);

		// Resetting the counters when the subsequence
		// becomes invalid
		else if (left > right)
			left = right = 0;
	}
	return maxlength;
}


//A much shorter and concise version of the above code
int solve2(string s, int n){
	int left=0,right=0,maxlength=0,t=2;
	while(t--){
		left=0;
		right=0;
		for(int i=0;i<n;i++){
			if(s[i]=='(')left++;
			else right++;
				
			if(left==right){
				maxlength=max(maxlength,2*left);
			}
			//when travelling from 0 to n-1
			if(t%2==1 && right>left){
				left=0;
				right=0;
			}
			//when travelling from n-1 to 0
			if(t%2==0 && left>right){
				left=0;
				right=0;
			}
			}
			//now we need to do the same thing from the other side;
			reverse(s.begin(),s.end());
		}
		return maxlength;
}

// Driver code
int main()
{

	// Function call
	cout << solve("((()()()()(((())", 16);
	return 0;
}
