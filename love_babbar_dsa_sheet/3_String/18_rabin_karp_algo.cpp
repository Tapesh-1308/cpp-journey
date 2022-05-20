#include<bits/stdc++.h>
using namespace std;

/* Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[])
that prints all occurrences of pat[] in txt[]. You may assume that n > m. */

/*Method 1 Brute Force TC O(S*T) SC O(1)
void search(string &s, string &t){
    int S = s.size(), T = t.size();
    for(int i=0; i<T-S+1; i++) {
        if(t.substr(i, S) == s) {
            cout<<i<<" ";
        }
    }
} */

//Method 2 Rabin Karp Algorithm TC O(T-S+1) SC O(1)
void search(string pat, string txt, int mod, int d) {
    int M = pat.size();
    int N = txt.size();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%mod"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % mod;
 
    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % mod;
        t = (d * t + txt[i]) % mod;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)  {
 
        // Check the hash values of current window of text and pattern. If the hash values match then only
        // check for characters one by one
        if ( p == t ) {  
            // Check for characters one by one 
            for (j = 0; j < M; j++) 
                if (txt[i+j] != pat[j])
                    break;
                    
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout<<"Pattern found at index "<< i<<endl;
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M ) {
            t = (d*(t - txt[i]*h) + txt[i+M])%mod;
 
            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + mod);
        }
    }
}

int main(){
    string t = "AABAACAADAABAABA";
    string s = "AABA";

    int d = 256; //Base Value for hash function
    int mod = 101; //Mod value

    search(s, t, mod, d);    
    return 0;
}