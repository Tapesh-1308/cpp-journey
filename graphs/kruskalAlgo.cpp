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
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(), edges.end());
    int cost=0;
    for(auto i:edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = findSet(u);
        int y = findSet(v);
        if(x==y) continue;
        unionSets(u,v);
        cost += w;
    }
    cout<<cost<<endl;
    //Test Case
    // n m
    // 8 9
    // u v w
    // 1 2 5
    // 2 3 6
    // 4 3 2
    // 1 4 9
    // 3 5 5
    // 5 6 10
    // 6 7 7
    // 7 8 1
    // 8 5 1
    
    //Answer - Minimum cost!
    // 27
    return 0;
}