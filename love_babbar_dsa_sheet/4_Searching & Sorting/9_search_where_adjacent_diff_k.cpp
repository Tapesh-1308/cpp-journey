#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k) {
    int steps; // Stores number of skips we need to make 

    // To Traverse on the array
    for(int i=0; i<n;) {
        // If we found the element return its position
        if(arr[i] == x)
            return i;
        //update steps = x-arr[i] / k -> to check if next or more element can be x or not  
        steps = max(1, (x-arr[i])/k);
        i += steps; // making jump
    }
    // Element not present in array
    return -1;  
}

int main(){
    int arr[] = {20, 40, 50, 70, 70, 60};
    int n = sizeof(arr)/sizeof(int);

    cout << search(arr, n, 60, 20) << endl;

    return 0;
}