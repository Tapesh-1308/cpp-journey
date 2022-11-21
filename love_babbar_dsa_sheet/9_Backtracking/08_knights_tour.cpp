// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

/* A utility function to check if i,j are valid indexes for N*N chessboard */
int isSafe(int x, int y, vector<vector<int>>& board, int n)
{
    // row and col index should be in board and board[x][y] should also empty
	return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

/* A recursive utility function to solve Knight Tour problem */
bool solveKTUtil(int x, int y, int movei, vector<vector<int>>& board, int xMove[8], int yMove[8], int n)
{
    // base case if moves reached end of board
	if (movei == n * n)
		return true;

	int next_x, next_y;

	/* Try all next moves from the current coordinate x, y */
	for (int k = 0; k < 8; k++) {
        // find next position to place a knight
		next_x = x + xMove[k]; // next row 
		next_y = y + yMove[k]; // next col

        // if it is safe to place on [nextx][nexty] (means place is empty and nextx nexty values are in range (0...n-1))
		if (isSafe(next_x, next_y, board, n)) {
			board[next_x][next_y] = movei; // placing knight 

            // after placing knight call for remaing tour by incremmenting move
			if (solveKTUtil(next_x, next_y, movei + 1, board, xMove, yMove, n))
				return true;
			else
                // backtracking
				board[next_x][next_y] = -1;
		}
	}

    // if is not possible to place knight in all 8 direction return false
	return false;
}



/* A utility function to print solution matrix board */
void printSolution(vector<vector<int>> &board)
{
	for (int x = 0; x < board.size(); x++) {
		for (int y = 0; y < board.size(); y++)
			cout << " " << setw(2) << board[x][y] << " ";
		cout << endl;
	}
}

/* This function solves the Knight Tour problem using Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete tour is possible, otherwise return true and prints the
tour. Please note that there may be more than one solutions,this function prints one of the feasible solutions. */
void solveKT(int n)
{
	/* Initialization of solution matrix */
	vector<vector<int>> board(n, vector<int>(n, -1));

	/* xMove[] and yMove[] define next move of Knight.
	xMove[] is for next value of x coordinate
	yMove[] is for next value of y coordinate */
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	board[0][0] = 0;

	/* Start from 0,0 and explore all tours using solveKTUtil() */
        // if  it returns false means no solution exists
	if (!solveKTUtil(0, 0, 1, board, xMove, yMove, n)) {
		cout << "Solution does not exist";
	}

    // else print the board
	else printSolution(board);
}



int main()
{
    int N = 8;

	solveKT(N);
	return 0;
}
