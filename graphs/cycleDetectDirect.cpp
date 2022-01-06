//Cycle Detection in Directed Graph
#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &stack){
    stack[src] = true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i:adj_list[src]){
            if(!visited[i] and isCycle(i, adj_list, visited, stack)) return true;
            if(stack[i]) return true;        
        }
    }
    stack[src] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n);
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        adj_list[x].push_back(y);
    }
    bool cycle = false;
    vector<int> stack(n, 0);
    vector<bool> visited (n, false);

    for(int i=0; i<n; i++){
        if(!visited[i] and isCycle(i, adj_list, visited, stack)) 
            cycle = true;
    }
    if(cycle) cout<<"Cycle is Present";
    else cout<<"Cycle is not Present";
        
    return 0;
}