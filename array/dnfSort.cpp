#include<iostream>
using namespace std;

// DNF = dutch national flag
//Time complexity = O(n)

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void dnfSort(int arr[], int n){
    int l = 0, m = 0, h = n-1;

    while(m<=h){
        if(arr[m]==0){
            swap(arr, l , m);
            l++; m++;
        }
        else if(arr[m]==1){
            m++;
        }
        else{
            swap(arr, m,  h);
            h--; 
        }
    }
}

int main() {
    int arr[10] = {1, 0, 2, 1, 0, 2 , 0, 1, 1, 2};
    dnfSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
    
    
    return 0;
}