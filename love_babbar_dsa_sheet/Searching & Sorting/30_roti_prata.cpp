#include<bits/stdc++.h>
using namespace std;

// Method - Binary Search TC O(n^logn) SC O(1)

bool findPrata(int arr[], int n, int prata, int time){
    int p=0; // Store number of prata we can make in given time

    // Traversing for all ranked cook
    for(int i=0; i<n; i++) {
        // Sum store time taken while making pratas
        int sum=arr[i]; // j=1
        int j=2; // j -> 2 to while sum <= time
        while(sum <= time) {
            p++; // Created a prata
            sum += j*arr[i]; // Calulating time taken to create 
            j++; // It tell which prata we are making, 1st prata -> 1*arr[i], 2-> 2*arr[i]
        }   
        // If we created sufficient prata
        if(p >= prata)
            return true;
    }

    // If we can't created sufficient prata in given time
    return false;
}

int rotiPrata(int arr[], int n, int p) {
    // Search Space = 0...maxPossibleAnswer
    int st=0; 
    int end=0;

    // Calulating end
    int maxElement = INT_MIN;
    for(int i=0; i<n; i++) 
        maxElement = max(maxElement, arr[i]);
    
    for(int i=1; i<=p; i++) 
        end += i*maxElement;

    // Binary Search
    int mid, ans=0;
    while(st <= end) {
        mid = st + (end-st)/2;
        // FindPrata counts number of prata we can make using mid time
        // If we can make more than or equal to required then we can reduce time/mid
        // Hence end = mid-1, store ans as mid
        if(findPrata(arr, n, p, mid)){
            ans = mid;
            end = mid-1;
        }
        // When we can't make enough prata in mid time then we have increase time/mid
        // hence, st = mid+1
        else st = mid+1;
    }
    // return ans which store minimum mid value we get
    return ans;
}

int main(){
    int arr[] = {1,2,3,4};
    int l = sizeof(arr)/sizeof(int);
    int p = 10;
    cout << rotiPrata(arr, l, p);
    return 0;
}