#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    // vector<int> vec;
    unordered_map<int, int> um;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        um[k]++;
    }
    
    
    for(auto it:um){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}