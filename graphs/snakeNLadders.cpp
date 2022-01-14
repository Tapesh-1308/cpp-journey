#include<bits/stdc++.h>
using namespace std;

int main(){
    int ladders, snakes;
    cin>>ladders;
    map<int, int> ladd;
    map<int, int> snake;
    for(int i=0; i<ladders; i++){
        int u, v; cin>>u>>v;
        ladd[u] = v;
    }
    cin>>snakes;
    for(int i=0; i<snakes; i++){
        int u, v; cin>>u>>v;
        snake[u] = v;
    }
    int moves=0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<bool> vis(101, 0);
    vis[1] = true;
    while(!q.empty() and !found){
        int n=q.size();
        while(n--){
            int t = q.front();
            q.pop();
            for(int die=1; die<=6; die++){
                if(t+die==100)
                    found=true;
                if(t+die <= 100 && ladd[t+die] && !vis[ladd[t+die]]){
                    vis[ladd[t+die]] = 1;
                    if(ladd[t+die]==100)
                        found = true;
                    q.push(ladd[t+die]);
                }
                else if(t+die <= 100 && snake[t+die] && !vis[ladd[t+die]]){
                    vis[snake[t+die]] = 1;
                    if(snake[t+die]==100)
                        found = true;
                    q.push(snake[t+die]);
                }
                else if(t+die <= 100 && !vis[t+die] && !snake[t+die] && !ladd[t+die]){
                    vis[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }
    if(found) cout<<moves;
    else cout<<-1;
    return 0;
}