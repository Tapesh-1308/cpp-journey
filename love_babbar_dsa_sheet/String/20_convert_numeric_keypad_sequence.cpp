#include<bits/stdc++.h>
using namespace std;

// Approach TC O(N) SC O(N)
//We can use map here too instead of vector of string
string printSequence(string &input, vector<string> &keypad) {
    string output = "";

    for(int i=0; i<input.length(); i++) {
        if(input[i] == ' ') output.push_back('0');
        else output += keypad[input[i] - 'A'];
    }

    return output;
}

int main(){
    vector<string> keypad = {"2", "22", "222", 
                             "3", "33", "333",
                             "4", "44", "444",
                             "5", "55", "555",
                             "6", "66", "666",
                             "7", "77", "777", "7777",
                             "8", "88", "888",
                             "9", "99", "999", "9999"};
    string input = "HELLO WORLD";

    cout<<printSequence(input, keypad);
    /* Output -> 4433555555666096667775553 */
    return 0;
}