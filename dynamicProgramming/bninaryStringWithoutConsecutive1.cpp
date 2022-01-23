//count number of binary string without consecutive 1's
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> nums(n+2, 0);

    nums[0]=1;
    nums[1]=1;
    for(int i=2; i<=n+1; i++)
        nums[i] = nums[i-1] + nums[i-2];

    cout<<nums[n+1];
    return 0;
}