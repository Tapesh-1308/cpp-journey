#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    vector<vector<int>> adj_list(n);
    vector<int> inDeg(n, 0);
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        //x-->y // Directed graph
        adj_list[x].push_back(y);
        inDeg[y]++;
    }
    queue<int> pq;
    for(int i=0; i<n; i++){
        if(inDeg[i]==0) pq.push(i);
    }
    while(!pq.empty()){
        cnt++;
        int tmp=pq.front();
        pq.pop();
        cout<<tmp<<" ";
        for(auto it:adj_list[tmp]){
            inDeg[it]--;
            if(inDeg[it]==0) pq.push(it);
        }

    }
    return 0;
}