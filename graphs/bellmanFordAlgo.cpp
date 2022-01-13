#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edg;
    for(int i=0; i<m; i++){
        int x, y, w;
        cin>>x>>y>>w;
        edg.push_back({x, y, w});
    }
    int src; cin>>src;
    vector<int> dist(n, INF);
    dist[src]=0;
    bool change=false;
    for(int i=0; i<n-1; i++){
        for(auto e:edg){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(dist[u]+w<dist[v]) 
                change = true;
            dist[v] = min(dist[v], dist[u]+w);
        }
    }
    for(auto i: dist) cout<<i<<" ";
    cout<<endl;
    return 0;
}