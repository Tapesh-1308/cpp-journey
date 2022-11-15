#include <bits/stdc++.h>
using namespace std;

/* Time Complexity: O( (2^n) * k * (n/2) )

Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)

Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n). */

// function to check if a string is palindrome or not
bool isPalindrome(string s, int start, int end) {
    // traverse string from start to end
    while (start <= end) {
        // if found unequal return false
        if (s[start++] != s[end--])
            return false; 
    }
    // return true if string is palindrome
    return true;
}

// recursive function that creates partition 
// takes ->         starting index of string, string, curr ans, result 
void partitionHelper(int index, string s, vector<string> &path, vector<vector<string>> &res) {
    // base case
    if (index == s.size()) { // if string get exhausted completely
        res.push_back(path); // push path into result
        return;
    }

    // traverse on string from index to end
    for (int i = index; i < s.size(); ++i) {
        // if string [index...i] is palindrome 
        if (isPalindrome(s, index, i)) {
            // push substring [index...i] in path (size of string [index...i] is i-index+1)
            path.push_back(s.substr(index, i - index + 1));

            // call recursively for remaining part
            partitionHelper(i + 1, s, path, res);

            // backtrack for other solutions
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    // stores all answer
    vector<vector<string>> res;
    // store current ans
    vector<string> path;

    // recursive function
    partitionHelper(0, s, path, res);

    // return result
    return res;
}

int main() {
    string s = "aabb";
    vector<vector<string>> ans = partition(s);
    int n = ans.size();
    cout << "The Palindromic partitions are :-" << endl;
    cout << " [ ";
    for (auto i : ans) {
        cout << "[ ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}