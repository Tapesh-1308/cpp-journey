#include<bits/stdc++.h>
using namespace std;

/* Approach - TC O(N) SC O(1) */

//Function returns value of roman symbol
int value(char ch){
    if(ch == 'I') return 1;
    if(ch == 'V') return 5;
    if(ch == 'X') return 10;
    if(ch == 'L') return 50;
    if(ch == 'C') return 100;
    if(ch == 'D') return 500;
    if(ch == 'M') return 1000;
    return -1;
}

//Return decimal value of roman numerals
int romanToDecimal(string &roman) {
    int n = roman.length();
    int ans = value(roman[n-1]);  //store last element value in ans
    
    //Traverse from second last value to 0th index 
    for(int i=roman.length() - 2; i>=0; i--){

        // if value is greater or equal to previous value while traversing from last
        // then add it with ans - VI  -> I = 6 , V = 5 -> 1+5 = 6 will be stored
        if(value(roman[i]) >= value(roman[i+1]))
            ans += value(roman[i]);
        
        else 
            //If we get smaller value then previous
            // IV -> V = 5 in ans, we get I now, so minus it with V=5 to get 4
            ans = ans - value(roman[i]);
        
    }
    
    // return the decimal value
    return ans;
}

int main(){
    string str = "MCMIV";
    cout << "Integer form of Roman Numeral is " << romanToDecimal(str) << endl;
    return 0;
}