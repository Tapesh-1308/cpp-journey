//Cycle Detection in Undirected Graph
#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj_list, vector<bool> &visited, int parent){
    visited[src] = true;
    for(auto i:adj_list[src]){
        if(i!=parent){
            if(visited[i])
                return true;
            if(!visited[i] and isCycle(i, adj_list, visited, src)) 
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n);
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    bool cycle = false;
    vector<bool> visited (n, false);

    for(int i=0; i<n; i++){
        if(!visited[i] and isCycle(i, adj_list, visited, -1)) 
            cycle = true;
    }
    if(cycle) cout<<"Cycle is Present";
    else cout<<"Cycle is not Present";
        
    return 0;
}