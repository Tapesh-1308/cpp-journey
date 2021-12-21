#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int arr[], int n, int m, int mid){
    int studentsReq = 1, sum = 0;

    for(int i=0; i<n; i++) {
        if(arr[i]>mid) return false;

        if(arr[i]+sum>mid) {
            studentsReq++;
            sum = arr[i];
            if(studentsReq>m) return false;
        } else{
            sum += arr[i];
        }
    }
    return true;
}

int allocateMin(int arr[], int n, int m){
    if(n<m) return -1;
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];

    int start = 0, end = sum, ans = INT_MAX;
    while(start<=end){
        int mid = (start+end)>>1; // |-->> (start+end)/2 <<--|
        if(isFeasible(arr, n, m, mid)){
            ans = min(ans, mid);
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    cout<<allocateMin(arr, 4, 2);
    return 0;
}