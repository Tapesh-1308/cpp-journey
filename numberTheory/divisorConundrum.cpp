//Hackerearth Question - Monk and Divisor Conundrum
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int hashArr[N];
int countMultiple[N];

int main(){
    int n; cin>>n;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        hashArr[x]++;
    }

    for(int i=1; i<N; i++){
        for(int j=i; j<N; j += i){
            countMultiple[i] += hashArr[j];
        }
    }

    int q; cin>>q;
    while(q--){
        int p, q;
        cin>>p>>q;
        long long lcm = p*1ll*q/__gcd(p,q);
        long ans = countMultiple[p]+countMultiple[q];
        if(lcm<N) ans -= countMultiple[lcm];
        cout<<ans<<endl;
    }
    return 0;
}