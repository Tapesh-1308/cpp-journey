// SPOJ - DEFKIN - defence of kings
#include<bits/stdc++.h>
using namespace std;

// Image - https://www.spoj.com/content/fidels:DEFKIN.png


// Time Complexity - O(2*NlogN)
// Space Complexity - O(n)
int main(){
    // t- number of testcases
    int t; cin>>t;
    while(t--) {
        // w-width, h-height, n-number of kings
        int w, h, n;
        cin>>w>>h>>n;

        // store defended rows(y) and coloumn(x) position of tower
        vector<int> x;
        vector<int> y;

        // starting edge of board
        x.push_back(0);
        y.push_back(0);

        // taking king position input
        for(int i=0; i<n; i++) {
            int xi, yi;
            cin>>xi>>yi;
            x.push_back(xi);
            y.push_back(yi);
        }           

        // ending of board
        x.push_back(w+1);
        y.push_back(h+1);

        // sort both array
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        // xmax and ymax stores the maximum consecutive difference 
        int xmax = 0;
        int ymax = 0;

        // find the maximum consecutive differnce between elements of array x and y
        for(int i=0; i<x.size()-1; i++) {
            xmax = max(xmax, x[i+1]-x[i]-1);
            ymax = max(ymax, y[i+1]-y[i]-1);
        }

        // biggest undefended area will xmax*ymax
        cout << xmax*ymax<<endl;
    }

    return 0;
}