#include<bits/stdc++.h>
using namespace std;

// Method - TC O(N+N+256) ~ O(N) - SC O(256)
int transfigure(string A, string B) {
    // Length of A and B
    int n = A.length(), m = B.length();
    
    // If length is not equal it can't be convert
    if(n != m) return -1;
    
    // To check if we have all char in A also in B
    int count[256];
    memset(count, 0, sizeof(count));
    
    // To check that increment for A[i] and Decrement for B[i]
    // due to this all element becomes 0
    for(int i=0; i<n; i++) {
        // Making 0
        count[A[i]]++;
        count[B[i]]--;
    }
    for(int i=0; i<256; i++) 
        // checking if not zero return -1 
        if(count[i] != 0)
            return -1;
    
    int ans = 0;
    
    int i = n-1; // Pointer for A
    int j = m-1; // Pointer for B

    while(i>=0) {
        if(A[i] != B[j])  // If not match don't decrement j
            ans++; // Increment ans in this case

        else // Else decrement j 
            j--;
        // Decrement i in every case
        i--;
    }

    // Return ans
    return ans;
}

int main(){
    string A = "GEEKSFORGEEKS";
    string B = "FORGEEKSGEEKS";

    cout << transfigure(A, B);

    return 0;
}