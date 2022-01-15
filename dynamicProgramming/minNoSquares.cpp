#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2, MOD=1e9+7;
int dp[N];

int minSq(int n){
    if(n==0||n==1||n==2||n==3) return n;
    if(dp[n]!=MOD) return dp[n];

    for(int i=1; i*i<=n; i++)
        dp[n]=min(dp[n], 1+minSq(n-i*i));
    return dp[n];    
}
int main(){
    for(int i=0; i<N; i++)
        dp[i] = MOD;
    cout<<minSq(1000);
    return 0;
}