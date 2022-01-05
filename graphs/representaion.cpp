#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rep(i, a, b) for(int i=a; i<b; i++)

const int N = 1e5+2;

vi adj[N];

int main(){
    //Adjacency Matrix
    /* int n, m;
    cin>>n>>m;

    //Taking Input
    vvi adjm(n+1, vi(n+1, 0));
    rep(i,0,m){
        int x, y;
        cin>>x>>y;

        adjm[x][y] =1;
        adjm[y][x] =1;
    }

    //Print
    rep(i,1,n+1){
        rep(j,1,n+1) cout<<adjm[i][j]<<" ";
        cout<<endl;
    }

    //Check if there is any edge present
    if(adjm[3][4]==1)
        cout<<"Yes Present"<<endl;
    else cout<<"No edge"; */

    //Adjacency List
    int n, m;
    cin>>n>>m;

    rep(i,0,m){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i,1,n+1){
        cout<<i<<"->";
        for(int x:adj[i]) //use auto x instead of int x if c++ 11 
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}