#include <bits/stdc++.h>
using namespace std;

// Approach - TC O(N^3) SC O(1)

bool isValid(string s){
    // If length is greater than 3 ex 2551
    if(s.length() > 3) 
        return false;

    //If prefix is 0
    if(s[0] == '0' && s.length() > 1)
        return false;

    //Convert string to int
    int value = stoi(s);

    // Check if it is in range [0-255]
    return value >= 0 && value <= 255;
}

vector<string> genIp(string &s) {
    vector<string> ans; //Create vector of string to store ans
    
    //Make 1st part
    for(int i=1; i<=3 && i<s.length(); i++) {
        string first = s.substr(0, i);
        if(isValid(first)) {
            //If valid - make second part
            for(int j=1; j<=3 && i+j<s.length(); j++) {
                string second = s.substr(i, j);
                if(isValid(second)) {
                    //If it is also valid - make last two parts
                    for(int k=1; k<=3 && i+j+k<s.length(); k++) {
                        string third = s.substr(i+j, k); 
                        string fourth = s.substr(i+j+k);
                        
                        if(isValid(third) && isValid(fourth))
                            //if 3rd and 4th are valid then push it into ans
                            ans.push_back(first+'.'+second+'.'+third+'.'+fourth);
                    }
                }
            }
        }
    }
    // Return the ans
    return ans;
}


int main() {
    string s = "1111";
    vector<string> str = genIp(s);
    if(str.size()==0)
        cout << -1 << "\n";
    else
        for (auto &i : str)
            cout << i << "\n";

    return 0;
}  