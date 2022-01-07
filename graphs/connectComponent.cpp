// Find the number of connected components in the graph and its size.
//Cycle Detection in Undirected Graph
#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
int n, m;
vector<vector<int>> adj;
vector<int> components;

int getComp(int idx){
    if(vis[idx]) return 0;
    vis[idx] = true;
    int ans=1;
    for(auto i:adj[idx]){
        if(!vis[i]){
            ans+=getComp(i);
            vis[i] = true;
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, 0);       
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0; i<n; i++)
        if(!vis[i]) components.push_back(getComp(i));

    // for(auto i:components)
    //     cout<<i<<" ";
    // cout<<endl;

    long long ans=0;
    for(auto i: components)
        ans += i*(n-i);

    cout<<(ans/2)<<endl;
    //components (0-1-4) (2-3)
    //0-2 | 0-3 | 1-2 | 1-3 | 4-2 | 4-3

    return 0;
}