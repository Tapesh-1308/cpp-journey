#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    const int N = 1e5+10;
    const int INF = 1e9+10;
    
    int dijkstra(int source, int n, vector<pair<int, int>> g[]){
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
                if(dist[v] + wt <    dist[childV]){
                    dist[childV] = dist[v] + wt;
                    st.insert({dist[childV], childV}); 
                }
            }
        }
        int ans =0;
        for(int i=1; i<=n; i++){
            if(dist[i]==INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> g[N];
        for(auto vec : times)
            g[vec[0]].push_back({vec[1], vec[2]});
        return dijkstra(k, n, g);
    }
};

int main(){
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    Solution obj;
    cout<<obj.networkDelayTime(times, 4, 2);
    return 0;
}