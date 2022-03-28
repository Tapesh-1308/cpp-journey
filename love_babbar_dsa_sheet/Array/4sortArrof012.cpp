#include<bits/stdc++.h>
using namespace std;

// TC = O(n) SC O(1)

class Solution {
    public:

    //Meth 1
    /* void sort012(int a[], int n) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        for(int i=0; i<n; i++){
            if(a[i]==0) zeroCount++;
            else if(a[i]==1) oneCount++;
            else twoCount++;
        }
        int i=0;
        while(i<zeroCount)
            a[i++] = 0;
        while(i<zeroCount+oneCount)
            a[i++] = 1;
        while(i<n) 
            a[i++] = 2;
    }
    */

    //Meth 2
    void sort012(int a[], int n)
    {
        int lo = 0, mid = 0, hi = n-1;
        while(mid!=hi){
            if(a[mid]==0){
                swap(a[lo], a[mid]);
                lo++; mid++;
            }
            else if(a[mid]==1){
                mid++;
            } else {
                swap(a[mid], a[hi]);
                mid++; hi--;
            }
        }
    }
    
};


int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
