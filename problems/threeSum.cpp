#include<bits/stdc++.h>
using namespace std;

int main() {
    // Three Sum Problem - O(n^3) - Brute Force
    /* 
    int arr[] = {4, 9, 6, 3, 0, 8};
    bool found = false;
    int target = 11;
    for (int i = 0; i < 6; i++) {
        for (int j = i+1; j < 6; j++) {
            for (int k = j+1; k < 6; k++) {
                if(arr[i]+arr[j]+arr[k] == target)
                    found = true;
            }  
        }  
    }
    cout<<found<<endl; */

    // Using two pointer algorithm
    int n; cin>>n;
    int target; cin>>target;

    vector<int> vec(n);
    for(auto &i : vec) 
        cin>>i;

    bool found = false;
    sort(vec.begin(), vec.end());

    for(int i = 0; i<n; i++){
        int l = i+1; int h = n-1;
        while(l<h){
            int curr = vec[i] + vec[l] + vec[h];
            if(curr==target)
                found = true;
            if(curr<target)
                l++;
            else h--;
        }
    }
    
    if(found)
        cout<<"True";
    else cout<<"False";

    return 0;
}