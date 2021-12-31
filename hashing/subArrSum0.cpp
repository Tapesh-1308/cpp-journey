#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];

    map<int, int> count;
    int sum=0;

    for(int i=0; i<n; i++){
        sum+=nums[i];
        count[sum]++;
    }
    int ans=0;  
    for(auto it:count){
        int c = it.second;
        ans += (c*(c-1))/2;
        if(it.first==0)
            ans+=it.second;
    }
    cout<<ans<<endl;
    for(auto it:count) 
        cout<<it.first<<" "<<it.second<<endl;
    return 0;
}