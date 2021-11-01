#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
    int arr[6] = {1, 9, 2, 8, 3, 7};
    sort(arr, arr+5);
    sort(arr, arr+6, greater<int>());
    
    for (int i = 0; i < 6; i++) { cout<<arr[i]<<endl; }
    
    return 0;
}