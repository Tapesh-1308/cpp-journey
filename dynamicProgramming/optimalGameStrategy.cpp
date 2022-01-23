#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(int i, int j, vector<int>& a){
    if(i==j) return a[i];
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int x = a[i] + min(solve(i+2, j, a), solve(i+1, j-1, a));
    int y = a[j] + min(solve(i, j-2, a), solve(i+1,  j-1, a));

    return dp[i][j] = max(x, y);
}

int main(){ 
    memset(dp, -1, sizeof dp);
    int n; cin>>n;
    vector<int> a(n);
    for(auto &it:a) cin>>it;   

    cout<<solve(0, n-1, a);
    return 0;
}