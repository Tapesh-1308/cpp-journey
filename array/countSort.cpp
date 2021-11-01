#include<iostream>
using namespace std;

void countSort(int arr[], int n){
    int k = arr[0];
    for (int i = 0; i < n; i++) { k = max(k, arr[i]); }

    int countArr[10] = {0};
    for (int i = 0; i < n; i++) { countArr[arr[i]]++; }

    for(int i = 1; i<=k; i++){ countArr[i] += countArr[i-1]; }

    int output[n];
    for (int i = n-1; i >= 0; i--) { output[--countArr[arr[i]]] = arr[i]; }

    for(int i = 0; i < n; i++){ arr[i] = output[i]; }
    
}

int main() {
    int arr[9] = {1, 2, 3, 4, 5, 4, 3, 2, 1};

    countSort(arr, 9);
    for (int i = 0; i < 9; i++) { cout<<arr[i]<<" "; }
    
    return 0;
}