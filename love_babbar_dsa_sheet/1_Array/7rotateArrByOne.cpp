#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[] = {1,2,3,4,5};

    //Method #1 TC O(N) SC O(1)
    int temp = arr[n-1];
    for(int i=n-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    /**************************/


    //Method #2 TC O(N) SC O(1)
    int i=0, j=n-1;
    while(i!=j) {
        swap(arr[i], arr[j]);
        i++;
    }
    /**************************/

    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}