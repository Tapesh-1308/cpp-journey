#include <bits/stdc++.h>
using namespace std;

// Approach - TC O(N) SC O(1)

// Function to return the lexicographically smallest string after swapping all the occurrences of any two characters
string smallestStr(string str, int n)
{
    // To store the first index of
    // every character of str in sorted order
    set<char> set;

    // Store the first occurring
    // index every character
    for(auto c:str)
        set.insert(c);
    
    // Starting from the leftmost character
    for(int i=0; i<str.length(); i++) {
        set.erase(str[i]); // remove curr char from set
        
        if(set.empty()) break; // if no char left in set
        
        
        // If there is a character in set which is
        // smaller than str[i] and appears after it
        char ch = *(set.begin()); // store that
        if(ch < str[i]) {
            // store the curr character
            int curr = str[i];

            // Replace every ch with curr
            // and every curr with ch            
            for(int j=0; j<str.length(); j++) {
                if(str[j] == curr) 
                    str[j] = ch;
                else if(str[j] == ch) 
                    str[j] = curr;
            }
            // break after replacing
            break;
        }
    }
    
    // return the update string
    return str;
}

int main()
{
	string str = "ccad";
	int n = str.length();

	cout << smallestStr(str, n);

	return 0;
}
