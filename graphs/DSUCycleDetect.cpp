#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);

void makeSet(int v){
    parent[v]=v;
    sz[v]=1;
}

int findSet(int v){
    if(v==parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

int main(){
    for(int i=0; i<N; i++)
        makeSet(i);

    int n, m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    bool cycle=false;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        int x=findSet(u);
        int y=findSet(v);
        if(x==y) cycle=true;
        else unionSets(u,v);
    }
    if(cycle) cout<<"Cycle is present";
    else cout<<"Cycle is not present";
    
    return 0;
}