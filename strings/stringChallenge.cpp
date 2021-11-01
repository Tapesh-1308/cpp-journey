#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    // Convert String To Upper Case
    /* string str = "hfieeieeeyruytowrieieueitncd";

     for (int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'a' && str[i]<='z')
            str[i] -= 32;
    }
    cout<<str<<endl; 
    //Short Method
     transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str; */

     // Convert String To Lower Case
    /* string str2 = "HFIEEIEEEYRUYTOWRIEIEUEITNCD";

    for (int i = 0; i < str2.size(); i++)
    {
        if(str2[i] >= 'A' && str2[i] <='Z')
            str2[i] += 32;
    }
    cout<<str2<<endl; 
     //Short Method
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    cout<<str2; */

    // Maximum number finder
    /* string a = "57628568789180";
    sort(a.begin(), a.end(), greater<int>());
    cout<<a<<endl; */
    
    //Most repeatitive alphabet
    string str = "fhutitwuytuwhcirhruyt";

    int freq[26];

    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i] -'a']++;
    }

    char ans = 'a';
    int maxF = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i]>maxF)
        {
            maxF = freq[i];
            ans = i+'a';
        }
        
    }

    cout<<maxF<<" "<<ans<<endl;
    
    
    
    return 0;
}