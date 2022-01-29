#include<bits/stdc++.h>
using namespace std;

int dp[1000009];
int main(){
    int n; cin>>n;
    dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int mod = 1000000007;
    for(long long int i=3; i<=n; i++)
        dp[i] = (dp[i-1]%mod + (((i-1)%mod)*dp[i-2])%mod)%mod;
    cout<<dp[n];
    return 0;
}