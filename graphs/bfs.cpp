//BFS - Breadth First Search
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rep(i, a, b) for(int i=a; i<b; i++)

const int N = 1e5+2;
bool vis[N];
vi adj[N];

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

    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int node = q.front();
        q.pop();    
        cout<<node<<endl;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    
    return 0;
}