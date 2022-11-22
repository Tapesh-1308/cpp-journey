#include <bits/stdc++.h>
using namespace std;
 
// TC -> O(2^M*N)
// SC -> O(M+N)

// Function to check if (i, j) is a valid matrix coordinate
bool isValid(int i, int j, int M, int N) {
    return (i >= 0 && i < M && j >= 0 && j < N);
}
 
// Function to print the route taken
void printPath(vector<int> const &path, int last)
{
    for (int i: path) {
        cout << i << ", ";
    }
    cout << last << endl;
}
 
void findPaths(vector<vector<int>> const &mat, vector<int> &path, int i, int j)
{
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // base case
    // if the last cell is reached, print the route
    if (i == M - 1 && j == N - 1) {
        printPath(path, mat[i][j]);
        return;
    }
 
    // include the current cell in the path
    path.push_back(mat[i][j]);
 
    // move right
    if (isValid(i, j + 1, M, N)) {
        findPaths(mat, path, i, j + 1);
    }
 
    // move down
    if (isValid(i + 1, j, M, N)) {
        findPaths(mat, path, i + 1, j);
    }
 
    // backtrack: remove the current cell from the path
    path.pop_back();
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
 
    vector<int> path;
 
    // start from '(0, 0)' cell
    int x = 0, y = 0;
 
    findPaths(mat, path, x, y);
 
    return 0;
}
