#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;
int n, m;

vector<pair<int, int>> g[N];

void dijkstra(int source){
    vector<bool> vis(N, 0);
    vector<int> dist(N, INF);
    set<pair<int, int>> st; //we can use multiset also!

    st.insert({0, source});
    dist[source] = 0;

    while(!st.empty()){
        auto node = *st.begin();
        int v = node.second;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto child : g[v]){
            int childV = child.first;
            int wt = child.second;
            if(dist[v] + wt < dist[childV]){
                dist[childV] = dist[v] + wt;
                st.insert({dist[childV], childV}); 
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(dist[i]<INF) cout<<dist[i]<<" ";
        else cout<<"-1 ";
    }
}



int main(){
    for(int i=0; i<m; i++){
        int x, y, wt;
        cin>>x>>y>>wt;
        g[x].push_back({y, wt});
        g[y].push_back({x, wt});
    }
    int source; cin>>source;
    dijkstra(source);
   
}