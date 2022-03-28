#include <iostream>
using namespace std;

//Partition Approach
void shiftall(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

// Two Pointer Approach
void shiftall(int arr[], int left, int right) {
    while(left<=right){
        if(arr[left]<0 && arr[right]<0)
            left++;
        else if(arr[left]>0 && arr[right]<0)
            swap(arr[left++], arr[right--]);
        else if(arr[left]>0 && arr[right]>0)
            right--;
        else{
            left++; right--;
        }
    }
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, 11};
    int n=9;
    shiftall(arr, 0, n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}