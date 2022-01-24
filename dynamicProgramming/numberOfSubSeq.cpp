#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned n; cin>>n;  
    string s; cin>>s;
    
    unsigned MOD = 1e9+7;
    unsigned e=1, a=0, ab=0, abc=0;
    for(unsigned i=0; i<n; i++){
        if(s[i] == 'a') a=(a+e)%MOD;
        else if(s[i]=='b') ab=(ab+a)%MOD;
        else if(s[i]=='c') abc=(abc+ab)%MOD;
        else if(s[i]=='?') {
            abc = (3*abc+ab)%MOD;
            ab = (3*ab+a)%MOD;
            a = (3*a+e)%MOD;
            e = (3*e)%MOD;
        }
    }  
    cout<<abc<<endl;
    return 0;
}