#include<bits/stdc++.h>
using namespace std;

//Rotating array by one
void rightRotate(int arr[], int from, int to){
    int temp = arr[to];
    for(int i=to; i>=from; i--)
        arr[i] = arr[i-1];
    arr[from] = temp;
}

void rearrange(int arr[], int n){
    int wrongPos = -1; 

    for(int i=0; i<n; i++){
        if(wrongPos != -1){
            if((arr[wrongPos]<0 && arr[i]>=0) || (arr[wrongPos]>=0 && arr[i]<0)){
                // if a[wrong pos] is negative and a[i] is positive or a[wrong pos] is pos or a[i] is negative
                // then we need to rotate it by right 
                rightRotate(arr, wrongPos, i);

                if(i-wrongPos >= 2) wrongPos += 2; // Diff between ith and wrong pos is >= 2 then next wrong pos will surely be on += 2
                if(i-wrongPos >= 2) wrongPos += 2; // Diff between ith and wrong pos is >= 2 then next wrong pos will surely be on += 2
                else wrongPos = -1;
            }
        }
        else {
            if((arr[i] < 0 && i%2 == 1) || (arr[i] >= 0 && i%2 == 0))
                wrongPos = i; 
            // If ith pos is odd and arr[i] is negative or ith pos is even the arr[i] is positive
        }
    }

}

int main(){
    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    rearrange(arr, n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}