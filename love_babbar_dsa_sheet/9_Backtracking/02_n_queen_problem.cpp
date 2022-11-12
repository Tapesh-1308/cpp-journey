#include <bits/stdc++.h>
using namespace std;

// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).
// Space Complexity: O(N)

// function to check if it is safe to place queen on board[row][col]
bool isSafe(int row, int col, vector<string> &board, int n) {
    // to regain row col values
    int duprow = row;
    int dupcol = col;

    // check upper left diagonal ↖ 
    while (row >= 0 && col >= 0) 
        if (board[row--][col--] == 'Q') // if any queen found 
            return false;

    // regain row col values
    col = dupcol;
    
    // check left on current row <-
    while (col >= 0) 
        if (board[row][col--] == 'Q') // if any queen found
            return false;
    
    // regain row col values
    row = duprow;
    col = dupcol;

    // check of lower left diagnoal ↙
    while (row < n && col >= 0) 
        if (board[row++][col--] == 'Q') // if any queen found
            return false;
    
    // return true if no queen found (safe position)
    return true;
}

// recursive function to find the all solutions
void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, 
           vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)  {
    // basecase if coloumn becomes n (means all queens placed)
    if (col == n) {
        ans.push_back(board); // put created board in ans
        return;
    }

    // run loop on current column for n rows
    for (int row = 0; row < n; row++) {
        // if isSafe for queen to place on board 
        /* no queen on left of current row 
           no queen on lower diagnol 
           no queen on upper diagnol
        */
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            // put queen on board
            board[row][col] = 'Q';

            // also mark queen on 3 directions
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            // recursive call for next call
            solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

            // backtracking
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

// function to find all possible solution
vector<vector<string>> solveNQueens(int n) {
    // stores all solution boards
    vector<vector<string>> ans;

    // stores single board at a time
    vector<string> board(n);
    string s(n, '.'); // empty string

    // fill empty string initially
    for (int i = 0; i < n; i++) {
        board[i] = s; 
    }

    /* we will use hashing to maintain a list to check whether that position can be the right one or not.
    
    * leftrow -> tells if there is queen in the left side of current row <-
    * upperdiagnoal -> tells if there is queen in the upper diagnal ↖
    * lowerdiagnoal -> tells if there is queen in the lower diagnal ↙
    
    */
    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

    // function call (column number, board, answer, 3 vector, input n)
    solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

    return ans;
}
       
int main() {
    int n = 4; // we are taking 4*4 grid and 4 queens
    
    vector<vector<string>> ans = solveNQueens(n);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}