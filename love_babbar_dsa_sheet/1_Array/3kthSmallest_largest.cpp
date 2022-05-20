#include<bits/stdc++.h>
using namespace std;

//Approach #1 Using sorting TC NlogN
/* 
int kthSmallest(int arr[], int n, int k) {
    sort(arr, arr + n);
    return arr[k - 1];
}
*/

// Approach #2 Using Priority_queue TC N+KlogN
/*
int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<=r; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
*/

//Approach #3  Quick Select Algo Best Case TC O(n) Worst Case TC O(n^2)
int partition(int arr[], int pivot, int l, int r){
    int i=l, j=l;
    while(i<=r){
        if(arr[i]<=pivot){
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
    return j-1;
}

int kthSmallest(int arr[], int l, int r, int k) {
    int pivot = arr[r];
    int pi = partition(arr, pivot, l, r);
    
    if(k-1 > pi) 
        return kthSmallest(arr, pi+1, r, k);
    else if (k-1 < pi)
        return kthSmallest(arr, l, pi-1, k);
    else return arr[pi];
}

int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
} 

    


