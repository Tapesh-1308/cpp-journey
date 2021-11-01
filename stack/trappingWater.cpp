#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> vec){
    int n = vec.size();
    if(n<=2){
        return 0;
    }
    vector<int> left(n), right(n);
    left[0] = 0;
    int leftMax = vec[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = leftMax;
        leftMax = max(leftMax, vec[i]);
    }
    right[n-1] = 0;
    int rightMax = vec[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = rightMax;
        rightMax = max(rightMax, vec[i]);
    }

    int ans = 0;
    for (int i = 1; i < n-1; i++)
    {
        if(vec[i]<left[i] and vec[i]<right[i])
            ans += min(left[i], right[i]) - vec[i];
    }
    return ans;
}

int main() {
    vector<int> vec = {3,1,2,4,0,1,3,2};
    /* //Trapping Rainwater Problem - LeetCode - 42 - Brute Force O(n^2)
    int n = vec.size();
    int left[n];
    int right[n];
    int ans = 0;
     for (int i = 0; i < n; i++)
    {
        left[i] = vec[i];
        right[i] = vec[i];
        int j = i;
        while(j>=0){
            left[i] = max(left[i], vec[j]);
            j--;
        }
        j = i;
        while(j>=0){
            right[j] = max(right[j], vec[i]);
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans += (min(left[i],right[i])-vec[i]);
    }
    cout<<ans<<endl; */
    cout<<trap(vec);
    return 0;
}

// kytxa4dv6bljzwb01h1dq                         HACK2021-yzt3fz