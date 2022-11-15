#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n^2 board, we have 9 possible numbers.

Space Complexity: O(n^2), stack space
*/


// function to check if we can place a number in the empty block or not

/*
 * Condition to put any number :
 *  1) All the rows should be filled with numbers(1 – 9) exactly once.
 *  2) All the columns should be filled with numbers(1 – 9) exactly once.
 *  3) Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.
*/
bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    // traverse 
    for (int i = 0; i < 9; i++) {
        // condition 1 
        if (board[i][col] == c) // return false if same number found in any row
            return false;

        // condition 2
        if (board[row][i] == c) // return false if same number found in any column
            return false;

        // condition 3
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) // return false if same number found in 3*3 matrix
            return false;
    }

    // return true if all condition satisfy
    return true;
}

// recursive function to solve sudoku, returns true if any solution found
bool solveSudoku(vector<vector<char>> &board) {

    // Traverse on matrix
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {

            // if any empty block found -> Character ‘.’ indicates empty cell.
            if (board[i][j] == '.') {

                // try to place every all possible numbers i.e 1 to 9
                for (char c = '1'; c <= '9'; c++) {
                    // if it is valid to plac current number on this empty block
                    if (isValid(board, i, j, c)) {
                        // put current number
                        board[i][j] = c;

                        // call to solve remaining sudoku, if successfully solve then return true
                        if (solveSudoku(board))
                            return true;
                        // if by placing current number into this empty block does not gives us any solution backtrack
                        else
                            board[i][j] = '.';
                    }
                }

                // return false if we can't place any number b/w 1 to 9
                return false;
            }
        }
    }
    // return true when whole matrix traversed and no more empty block present
    return true;
}

int main()
{
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}