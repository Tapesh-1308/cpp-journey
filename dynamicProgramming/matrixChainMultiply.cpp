#include<bits/stdc++.h>
using namespace std;

const int N = 102, MOD = 1e9+7;
int a[N];
int dp[N][N];

//memoization
int mcm(int i, int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    dp[i][j] = MOD;
    for(int k=i; k<j; k++)
        dp[i][j] = min(dp[i][j], mcm(i, k)+mcm(k+1, j) + (a[i-1] * a[k] * a[j]));
    return dp[i][j];
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    // memset(dp, -1, sizeof(dp));
    // cout<<mcm(1, n-1)<<endl;

    //tabulation
    int j, min, q;
    for(int i=1; i<n; i++)
        dp[i][i] = 0;
    for(int d=1; d<n-1; d++){
        for(int i=1; i<n-d; i++){
            j=i+d;
            min = INT_MAX;
            for(int k=i; k<=j-1; k++){
                q = dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j];
                if(q<min)
                    min = q;
                dp[i][j] = min;
            }
        }
    }
    cout<<dp[1][n-1]<<endl;

    return 0;
}