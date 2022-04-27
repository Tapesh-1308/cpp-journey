#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Inbuilt Func - TC O(√n) SC O(1) 
int findSqrt(int x){
    return sqrt(x);
} */

/* Method - 2 Linear Traversal - TC O(√n) SC O(1)
int findSqrt(int x){
    if (x == 0 || x == 1)
        return x;
    
    int i(1), res(1);
    while(res <= x) {
        i++;
        res = i*i;
    }

    return i-1;
} */

// Method - 3 Binary Search - TC O(logn) SC O(1)
// Long long int everywhere for large numbers
int findSqrt(int x){
    if ( x==0 || x == 1)
        return x;
    
    int st(1), end(x/2), ans(1), mid;
    while(st <= end) {
        mid = (st+end) / 2;

        int sq = mid*mid;
        if(sq == x)
            return mid;
        else if (sq <= x) {
            st = mid + 1;
            ans = mid;
        }
        else end = mid - 1;
    }
    return ans;
}

int main(){
    cout << findSqrt(4) << endl;
    cout << findSqrt(11) << endl;
    cout << findSqrt(9) << endl;
    return 0;
}