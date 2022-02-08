// Hackerearth Ques - A XOR Challenge
#include<bits/stdc++.h>
using namespace std;

int main(){
    int c; cin>>c;
    int bitCount = (int)log2(c) + 1;
    int a=0, b=0;
    vector<int> setBits;
    for(int i=0; i<bitCount; i++){
        if(c&(1<<i))
            setBits.push_back(i);
        else {
            a|=(1<<i);
            b|=(1<<i);
        }
    }
    long long ans = -1;
    int size = 1<<setBits.size();
    for(int mask=0; mask<size; mask++){
        int tempa = a, tempb = b;
        for(int j=0; j<setBits.size(); j++){
            if(mask&(1<<j))
                tempa |= (1<<setBits[j]);
            else tempb |= (1<<setBits[j]);
        }
        ans = max(ans, tempa*1ll*tempb);
    }
    cout<<ans<<endl;
    return 0;
}