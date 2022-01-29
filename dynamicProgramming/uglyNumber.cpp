#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> dp(n+1);
    int i2(0), i3(0), i5(0);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = min({2*dp[i2], 3*dp[i3], 5*dp[i5]});
        if(2*dp[i2]==dp[i]) i2++;
        if(3*dp[i3]==dp[i]) i3++;
        if(5*dp[i5]==dp[i]) i5++;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}