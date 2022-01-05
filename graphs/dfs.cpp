//BFS - Breadth First Search
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rep(i, a, b) for(int i=a; i<b; i++)

const int N = 1e5+2;
bool vis[N];
vi adj[N];

void dfs(int node){
    //preorder
    vis[node] =1;
    // cout<<node<<" ";

    //inorder
    for(auto it: adj[node]){
        if(vis[it]);
        else dfs(it);        
    }

    //postorder
    cout<<node<<" ";

}

int main(){
    rep(i, 0, N)
        vis[i] =0;

    int n, m;
    cin>>n>>m;

    int x, y;
    rep(i,0,m){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    
    return 0;
}