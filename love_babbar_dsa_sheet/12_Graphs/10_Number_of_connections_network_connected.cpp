#include <bits/stdc++.h>
using namespace std;

// Approach using Disjoint Set Union

// Time Complexity: O(E*4α)+O(N*4α) where E = no. of edges and N = no. of nodes. The first term is to calculate the number of extra edges and the second term is to count the number of components. 4α is for the disjoint set operation we have used and this term is so small that it can be considered constant.

// Space Complexity: O(2N) where N = no. of nodes. 2N for the two arrays(parent and size) of size N we have used inside the disjoint set.
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};

int main() {

    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    Solution obj;
    int ans = obj.Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}
