#include<bits/stdc++.h>
using namespace std;

vector<int> minimumCoin(int v){
    vector<int> ans;
    if(v==0) return {};
    vector<int> deno={1,2,5,10,20,50,100,200,500,2000};
    for(int i=deno.size()-1; i>=0; i--){
        while(v>=deno[i]){
            v-=deno[i];
            ans.push_back(deno[i]);
        }
        if(v==0) break;
    }
    return ans;
}

int main() {
    int v; cin>>v;
    vector<int> ans = minimumCoin(v);
    for(auto it : ans) cout<<it<<" ";

    return 0; 
}