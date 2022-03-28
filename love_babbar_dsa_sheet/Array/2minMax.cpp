//Approach 1 2*(n-2) + 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> myPair;
    if(n==0) {
        myPair.first = a[0];
        myPair.second = a[0];
        return myPair;
    }
    if(a[1]>a[0]){
        myPair.first = a[0];
        myPair.second = a[1];
    }
    else {
        myPair.first = a[1];
        myPair.second = a[0];
    }
    for(long long i=2; i<n; i++){
        if(a[i]>myPair.second) myPair.second = a[i];
        else if(a[i]<myPair.first) myPair.first = a[i];
    }
    return myPair;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}

//Approach 2 Odd size-> 3*(n-1)/2          Even size->1+3*(n-2)/2

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> myPair;
    int i=0;
    if(n%2==0) {
        if(a[0]>a[1]){
            myPair.second = a[0];
            myPair.first = a[1];
        }
        else {
            myPair.second = a[1];
            myPair.first = a[0];
        }
        i=2;
    }
    else{
        myPair.second = a[0];
        myPair.first = a[0];
        i=1;
    }
    while(i<n-1){
        if(a[i]>a[i+1]){
            if(a[i]>myPair.second){
                myPair.second = a[i];
            }
            if(a[i+1]<myPair.first){
                myPair.first = a[i+1];
            }
        } else{
            if(a[i+1]>myPair.second){
                myPair.second = a[i+1];
            }
            if(a[i]<myPair.first){
                myPair.first = a[i];
            }
        }
        i=i+2;
    }
    return myPair;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}

