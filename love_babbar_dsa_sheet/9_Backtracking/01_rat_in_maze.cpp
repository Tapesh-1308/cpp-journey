#include <bits/stdc++.h>
using namespace std;

// Approach - Backtracking 
// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
// Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).

/*-------------------------------------------------------Type - 1---------------------------------------------------------*/

// helper function takes(index i & j, maze, maze size, ans vector, path string, visited 2d array)
void findPathHelper(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move, vector<vector<int>> &vis) {
    // base case - reached destination 
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move); // add generated path to answer 
        return;
    }

    /*  Possibility conditions:
            1) Boundary check 
            2) visited or not
            3) Path blocked or not
    */

    // downward direction
    if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1) { // posibilty conditions
        vis[i][j] = 1; // mark as visited
        findPathHelper(i + 1, j, m, n, ans, move + 'D', vis);  // call for downward 
        vis[i][j] = 0; // backtrack
    }

    // left direction
    if (j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1] == 1) { // posibilty conditions
        vis[i][j] = 1; // mark as visited
        findPathHelper(i, j - 1, m, n, ans, move + 'L', vis);  // call for left 
        vis[i][j] = 0; // backtrack
    }

    // right direction
    if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1) { // posibilty conditions
        vis[i][j] = 1; // mark as visited
        findPathHelper(i, j + 1, m, n, ans, move + 'R', vis);  // call for right 
        vis[i][j] = 0; // backtrack
    }

    // upward direction
    if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j] == 1) { // posibilty conditions
        vis[i][j] = 1; // mark as visited
        findPathHelper(i - 1, j, m, n, ans, move + 'U', vis);  // call for upward 
        vis[i][j] = 0; // backtrack
    }
}

// main function takes (maze and size)
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans; // store all paths in string
    vector<vector<int>> vis(n, vector<int>(n, 0)); // tell which block is visited

    // only call function, if we have a starting point
    if (m[0][0] == 1)
        findPathHelper(0, 0, m, n, ans, "", vis);

    // return the answer
    return ans;
}

/*-------------------------------------------------------Type - 2---------------------------------------------------------*/
// also takes di and dj array 
void findPathHelper(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move,
           vector<vector<int>> &vis, int di[], int dj[]) {
    // base case - reached destination
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move); // add path to answer
        return;
    }

    // create directions string
    string dir = "DLRU";

    // iterate for all directions, instead of checking if condition for all
    for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind]; // nexti -> i after making (ind)movement
        int nextj = j + dj[ind]; // nextj -> j after making (ind)movement

        // all condition in on if{}, 
        //                    Boundary check                       visited or not       blocked or not
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1) {
            vis[i][j] = 1;
            findPathHelper(nexti, nextj, m, n, ans, move + dir[ind], vis, di, dj); // dir[ind] -> on which dir we have
            vis[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    // create two vector which represents movement int four direction
    int di[] = { 1, 0, 0, -1 }; // down, left, right, up
    int dj[] = { 0, -1, 1, 0 }; // down, left, right, up

    if (m[0][0] == 1)
        findPathHelper(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
}

int main() {
    // maze size
    int n = 4;

    // maze - 0,1 representation
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    // store all paths
    vector<string> result = findPath(m, n);

    // if no path found
    if (result.size() == 0)
        cout << "No Path found";
    
    // else print all paths
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;

    return 0;
}