#include <bits/stdc++.h>
using namespace std;

// Time Complexity -> O(4^N*M)
// Space Complexity -> O(N*M)

// adjacent direction array for x and y coordinates
int xMove[4] = {-1,0,1,0};
int yMove[4] = {0,1,0,-1};

// function check if it is valid to move on (x,y) cell
bool isValid(vector<vector<int>> &matrix, int x, int y) {
    // return true if x and y are in bounds of matrix and cell is not visited or not safe
    return (x>=0 && y>=0 && x<matrix.size() && y<matrix[0].size()  && matrix[x][y] !=0);
}

// recursive function (curr coordination, matrix, destination, curr path length, max length so far)
void solve(int x, int y, vector<vector<int>> &matrix, int xd, int yd, int length, int &maxLength) {
    // base case (if destination found)
    if(x == xd && y == yd) {
        // update maxLength
        maxLength = max(length, maxLength);
        return;
    }    
    // Here I am using input matrix as visited array (0 -> represents unsafe + visited)
    // mark as visited
    matrix[x][y] = 0;
    
    // traverse in all adjacent direction
    for(int i=0; i<4; i++) {
        // find the adjacent coordinates
        int nextx = x+xMove[i];
        int nexty = y+yMove[i];
        
        // if it is valid to move on (nextx, nexty) cell
        if(isValid(matrix, nextx, nexty)) {
            // call for rest path with length + 1
            solve(nextx, nexty, matrix, xd, yd, length+1, maxLength);
        }
    }
    // backtrack (mark as unvisited)
    matrix[x][y] = 1;
    
}

// wrapper function over recursive function (solve)
int findLongestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
    // if source and destination cell is unsafe return -1
    if(matrix[xs][ys] == 0 || matrix[xd][yd] == 0) return -1;
    
    // maxLength stores maximum length
    int maxLength = INT_MIN;
    


    // helper func call with curr path length 0  
    solve(xs,ys, matrix, xd, yd, 0, maxLength);
    
    // return maxLength 
    return maxLength == INT_MIN  ? -1  : maxLength;
}


int main()
{
    // input matrix with hurdles shown with number 0
    vector<vector<int>> matrix { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                 { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                                 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
 
    // find longest path with source (0, 0) and
    // destination (1, 7)
    cout << findLongestPath(matrix, 0, 0, 1, 7) << endl;
 
    return 0;
}