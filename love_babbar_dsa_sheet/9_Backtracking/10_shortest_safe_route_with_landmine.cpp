// C++ program to find shortest safe Route in the matrix with landmines
#include <bits/stdc++.h>
using namespace std;

// Time Complexity -> M*4^N*M + N*M
// Space Complexity -> N*M

// Row and Column 
#define R 12
#define C 10

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

// A function to check if a given cell (x, y) can be visited or not
bool isSafe(int mat[R][C], int visited[R][C], int x, int y) {
	// if there is a landmine or the cell is already visited, we can't visited it
    if (mat[x][y] == 0 || visited[x][y])
		return false;

	return true;
}

// A function to check if a given cell (x, y) is a valid cell or not
bool isValid(int x, int y) {
    // check if x and y indexes are in bounds of given matrix
	if (x < R && y < C && x >= 0 && y >= 0)
		return true;

	return false;
}

// A function to mark all adjacent cells of landmines as unsafe. Landmines are shown with number 0
void markUnsafeCells(int mat[R][C]) {
    // traverse the matrix
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// if a landmines is found
			if (mat[i][j] == 0) {
			// mark all adjacent cells
			for (int k = 0; k < 4; k++)
                // if adjacent indexes are in bounds and not a landmine
				if (isValid(i + rowNum[k], j + colNum[k]) && mat[i + rowNum[k]][j + colNum[k]] != 0)
					mat[i + rowNum[k]][j + colNum[k]] = -1; //  marking 
			}
		}
	}

	// mark all found adjacent cells as unsafe
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mat[i][j] == -1)
				mat[i][j] = 0;
		}
	}
}

// Function to find shortest safe Route in the matrix with landmines
// mat[][] - binary input matrix with safe cells marked as 1
// visited[][] - store info about cells already visited in current route
// (i, j) are coordinates of the current cell
// min_dist --> stores minimum cost of shortest path so far
// dist --> stores current path cost
void findShortestPathUtil(int mat[R][C], int visited[R][C], int i, int j, int &min_dist, int dist) {
	// if destination is reached
	if (j == C-1) {
		// update shortest path found so far
		min_dist = min(dist, min_dist);
		return;
	}

	// if current path cost exceeds minimum so far
	if (dist > min_dist)
		return;

	// include (i, j) in current path
	visited[i][j] = 1;

	// Recurse for all safe adjacent neighbours
	for (int k = 0; k < 4; k++) {
        // if adjacent cell indexes are in bounds and it is safe to move(not a landming and not visited)
		if (isValid(i + rowNum[k], j + colNum[k]) && isSafe(mat, visited, i + rowNum[k], j + colNum[k])) {
            // call for neighbours incrementing distance 
			findShortestPathUtil(mat, visited, i + rowNum[k], j + colNum[k], min_dist, dist + 1);
		}
	}

	// Backtrack
	visited[i][j] = 0;
}

// A wrapper function over findshortestPathUtil()
void findShortestPath(int mat[R][C]) {
	// stores minimum cost of shortest path so far
	int min_dist = INT_MAX;

	// create a boolean matrix to store info about
	// cells already visited in current route
	int visited[R][C];

	// mark adjacent cells of landmines as unsafe
	markUnsafeCells(mat);

	// start from first column and take minimum
	for (int i = 0; i < R; i++) {
		// if path is safe from current cell
		if (mat[i][0] == 1) {
			// initialize visited to false
			memset(visited, 0, sizeof visited);

			// find shortest route from (i, 0) to any
			// cell of last column (x, C - 1) where
			// 0 <= x < R
			findShortestPathUtil(mat, visited, i, 0, min_dist, 0);

			// if min distance is already found
			if(min_dist == C - 1)
				break;
		}
	}

	// if destination can be reached
	if (min_dist != INT_MAX)
		cout << "Length of shortest safe route is " << min_dist;

	else // if the destination is not reachable
		cout << "Destination not reachable from " << "given source";
}

int main() {
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};

	// find shortest path
	findShortestPath(mat);

	return 0;
}
