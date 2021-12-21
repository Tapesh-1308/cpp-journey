#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int arr[], int n, int m, int mid){
    int painters = 1, sum = 0;

    for(int i=0; i<n; i++) {
        if(arr[i]>mid) return false;

        if(arr[i]+sum>mid) {
            painters++;
            sum = arr[i];
            if(painters>m) return false;
        } else{
            sum += arr[i];
        }
    }
    return true;
}

int paintersPartition(int boards[], int n, int m){
    if(n<m) return -1;
    int sum = 0;
    for(int i=0; i<n; i++) sum += boards[i];

    int start = 0, end = sum, ans = INT_MAX;
    while(start<=end){
        int mid = (start+end)>>1;
        if(isFeasible(boards, n, m, mid)){
            ans = min(ans, mid);
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    cout<<paintersPartition(arr, 4, 2);
    return 0;
}