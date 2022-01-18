//Leetcode - 518
#include<bits/stdc++.h>
using namespace std;

int dp[310][10010];

int func(int ind, int amount, vector<int>& coins){
    if(amount==0)  return 1;
    if(ind<0) return 0;
    if(dp[ind][amount] !=-1) return dp[ind][amount];
    int ways = 0;
    for(int coinAm=0; coinAm<=amount; coinAm += coins[ind])
        ways += func(ind-1,amount-coinAm, coins) + 1LL; 
    return dp[ind][amount] = ways;
}

int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    return func(coins.size()-1,amount, coins);
}

int main(){
    vector<int> coins = {1,2};
    cout<<coinChange(coins, 3);
    return 0;
}