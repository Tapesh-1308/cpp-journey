#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
//Recursive Method - Time Complexity - O(2^n)
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1) + fib(n-2);
}

//Dynamic Programming - Time Complexity - O(n) //Top-Down/Memorisation Approach
int fibo[N];
int fib2(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    memset(fibo, -1, sizeof(fibo));

    if(fibo[n] != -1) return fibo[n];

    return fibo[n] = fib(n-1) + fib(n-2);
}
//Bottom-Up/Tabulation Approach
int fib3(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
int main(){
    // cout<<fib(1000);//TLE
    // cout<<fib2(1000);//No TLE
    cout<<fib3(8);
    return 0;
}