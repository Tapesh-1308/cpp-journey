// Leetcode problem - 485
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec= {1,0,1,1,0,1};
    int ans = 0;
    int count = 0;
    for(int i = 0; i<vec.size(); i++){
        if(vec[i] == 1) count++;
        else count = 0;
        ans = max(ans, count);
    }
    cout<<ans;
    return 0;
}