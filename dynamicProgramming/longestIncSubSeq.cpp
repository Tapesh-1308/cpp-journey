//Longest Increasing Sub Sequence
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int dp[N];

int lis(vector<int> &a, int n){
    if(dp[n]!=-1) return dp[n];
    dp[n] = 1;
    for(int i=0; i<n; i++)
        if(a[n]>a[i]) dp[n] = max(dp[n],1+lis(a, i));
    return dp[n];
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int ans = 0;
    for(int i=0; i<a.size(); i++) 
        ans = max(ans, lis(a, i));
    cout<<ans<<endl;
    return 0;
    
}