#include <bits/stdc++.h>
using namespace std; 

//Method 1 Clockwise Rotation TC(N^2) SC O(1)
void rotate90Clockwise(vector<vector<int>> matrix) {
 
    // Traverse each cycle
    for (int i = 0; i < matrix.size() / 2; i++) {
        for (int j = i; j < matrix.size() - i - 1; j++) {
 
            // Swap elements of each cycle in clockwise direction
            int N = matrix.size()-1;
            int temp = matrix[i][j];
            matrix[i][j] = matrix[N - j][i];
            matrix[N - j][i] = matrix[N - i][N - j];
            matrix[N - i][N - j] = matrix[j][N - i];
            matrix[j][N - i] = temp;
        }
    }
}

//Method 2 Transpose_Reverse O(N^2) SC O(1)
void rotate90clockwise(vector<vector<int>> matrix) {
	// Transpose of matrix
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < i; j++)
			swap(matrix[i][j], matrix[j][i]);
	// Reverse individual rows
	for (int i = 0; i < matrix.size(); i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}
}


int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3, 4 },
                                   { 5, 6, 7, 8 },
                                   { 9, 10, 11, 12 },
                                   { 13, 14, 15, 16 } };

	rotate90clockwise(matrix);

	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.size(); j++)
			cout << matrix[i][j] << " ";
	cout << endl;
}
