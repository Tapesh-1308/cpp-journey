#include<bits/stdc++.h>
using namespace std;

//Global Variables
vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;

void color(int u, int curr){
    if(col[u]!=-1 && col[u] != curr){
        bipart = false;
        return;
    }
    col[u]=curr;
    if(vis[u]) return;
    vis[u] = true;

    for(auto i:adj[u])
        color(i, curr xor 1);
}

int main(){
    int n, m; cin>>n>>m;
    adj  = vector<vector<int>>(n);
    vis  = vector<bool>(n, 0);
    col  = vector<int>(n, -1);
    bipart=true;
    for(int i=0; i<m; i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0; i<n; i++)
        if(!vis[i]) color(i, 0);

    if(bipart) cout<<"Graph is Bipart"<<endl;
    else cout<<"Graph is not Bipart"<<endl;

    return 0;
}