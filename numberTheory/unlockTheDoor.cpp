//Hackerearth Question - Unlock the door

#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
const int N = 1e5+10;
int fact[N];

int binExp(int a, int b, int m){
    int result = 1;
    while(b>0){
        if(b&1) result = (result*1ll*a)%m;
        a = (a*1ll*a) % m;
        b >>= 1;
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    fact[0] = 1;
    for(int i=1; i<N; i++)
        fact[i] =(fact[i-1] * 1ll * i) % M;
    while(t--){
        int n, k;
        cin>>n>>k;
        int ans = fact[k];
        int deno = fact[k-n];
        ans = (ans *1ll* binExp(deno, M-2, M))%M;
        cout<<ans<<endl;
    }
    return 0;
}