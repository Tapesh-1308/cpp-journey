#include<bits/stdc++.h>
using namespace std;

/* Time Complexity -> O( nlogn ) 
   Space Complexity ->  O( 1 ) */
 
// Custom comparator to sort in decrasing order on the basis of count of set bits
static bool comparator(int a, int b) {
    // __builtin_popcount -> return number of set bits in a integer 
    return __builtin_popcount(a) > __builtin_popcount(b); // > to sort in decreasing order 
}

void sortBySetBitCount(int arr[], int n) {
    // Use stable sort for integers having same number of set bits, sort according to their position in the original array i.e., a stable sort.
    stable_sort(arr, arr+n, comparator);
}

int main(){
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    sortBySetBitCount(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}