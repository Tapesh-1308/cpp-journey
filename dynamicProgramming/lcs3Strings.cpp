//Longest common subsequence
#include<bits/stdc++.h>
using namespace std;
const int N = 205;
int dp[N][N][N];

//Memoize
int lcs3(string &s1, string &s2, string &s3, int n, int m, int k){
    if(n==0 || m==0 || k==0) return 0;
    if(dp[n][m][k]!=-1) return dp[n][m][k];
    if(s1[n-1]==s2[m-1] && s2[m-1]==s3[k-1])
        return dp[n][m][k] = 1+lcs3(s1, s2, s3, n-1, m-1, k-1);
    else return dp[n][m][k] = max({lcs3(s1, s2, s3, n-1, m, k), lcs3(s1, s2, s3, n, m-1, k), lcs3(s1, s2, s3, n, m, k-1)});
}


int main(){
        
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    int n=s1.size(), m=s2.size(), l=s3.size();

    // memset(dp, -1, sizeof dp);
    // cout<<lcs3(s1, s2, s3, n, m, l)<<endl;

    //Tabulation
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(l+1, -1)));
    
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            for(int k=0; k<l+1; k++){
                if(i==0||j==0||k==0) {
                    dp[i][j][k]=0;
                    continue;
                }
                if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]) dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }
        }
    }
    cout<<dp[n][m][l]<<endl;
    
    return 0;
}