//Longest common subsequence
#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> a,b;
const int N = 2005;
int dp[N][N][7];

//Memoize
int klcs(int i, int j, int k){
    if(i==n || m==j) return 0;
    int c1(0), c2(0), c3(0);
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(a[i]==b[j])
        c1 = 1+klcs(i+1, j+1, k);
    if(k>0) c2 = 1+klcs(i+1, j+1, k-1);
    c3 = max(klcs(i+1, j, k), klcs(i, j+1, k));
    return dp[i][j][k] = max({c1,c2,c3});
}


int main(){
    memset(dp, -1, sizeof dp);
        
    cin>>n>>m>>k;
    a=vector<int>(n);
    b=vector<int>(m);

    for(auto &i: a) cin>>i;
    for(auto &i: b) cin>>i;

    cout<<klcs(0,0,k)<<endl;

    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<m+1; j++){
    //         if(i==0||j==0) {
    //             dp[i][j]=0;
    //             continue;
    //         }
    //         if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
    //         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //     }
    // }
    // cout<<dp[n][m]<<endl;
    
    return 0;
}