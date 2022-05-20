#include<bits/stdc++.h>
using namespace std;

// Method - Recursion - TC O(_____)? SC O(N+M)

void getSentence(vector<vector<string>> &words, int k, string ans) {
    // Check if we reach the last row
    if(k == words.size()) 
        cout << ans << endl;
    // If we are on kth row run recursive function for all column elements
    else 
        for(int i=0; i<words[k].size(); i++) 
            // in func update ans and increment k
            getSentence(words, k+1, ans + words[k][i] + ' ');
}

int main(){
    vector<vector<string>> words = {{"You", "We"},
                                    {"have", "are"},
                                    {"sleep", "eat", "drink"}};
    // Here words represent list, 0 -> means 1st row, "" -> blank ans
    getSentence(words, 0, "");
    return 0;
}