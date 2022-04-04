// Find the row with maximum number of 1s. Each row is sorted
#include <bits/stdc++.h>
using namespace std;

/* Method 1 Brute Force TC - O(n*m) SC - O(1)
int rowWithMax1s(vector<vector<bool>> matrix, int n, int m) {
	int rowIndex = -1 ; // Index of Maximum Row
	int maxCount = 0 ; // Maximum number of 1s in a row
	
	for(int i = 0; i < n; i++){
		int count = 0;
		for(int j = 0; j < m; j++ ){
			if(matrix[i][j] == 1){
				count++;
			}
		}
		if(count > maxCount){
			maxCount = count;
			rowIndex = i;
		}
	}
	
	return rowIndex;
}
*/

/* Method 2 Binary Search TC (NlogM) SC O(1)
int first(vector<bool> arr, int low, int high) {
    if(high >= low) {
        // Get the middle index
        int mid = low + (high - low)/2;
     
        // Check if the element at middle index is first 1
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
     
        // If the element is 0, recur for right side
        else if (arr[mid] == 0)
            return first(arr, (mid + 1), high);
         
        // If element is not first 1, recur for left side
        else
            return first(arr, low, (mid -1));
    }
    return -1;
}

int rowWithMax1s(vector<vector<bool>> matrix, int n, int m) {
    int i, index;
 
    // Initialize max using values from first row.
    int max_row_index = 0;
    int max = first(matrix[0], 0, m - 1);
 
    // Traverse for each row and count number of 1s by finding the index of first 1
    for (i = 1; i < n; i++) {
        // Count 1s in this row only if this row has more 1s than max so far
        if (max != -1 && matrix[i][m - max - 1] == 1) {
            // Note the optimization here also
            index = first (matrix[i], 0, m - max);
 
            if (index != -1 && m - index > max) {
                max = m - index;
                max_row_index = i;
            }
        }
        else {
            max = first(matrix[i], 0, m - 1);
        }
    }
    return max_row_index;
} */

// Method 3 TC O(n+m) SC O(1)
int rowWithMax1s(vector<vector<bool>> matrix, int n, int m) {
    // Initialize first row as row with max 1s
    int j,max_row_index = 0;
    j = m - 1;
 
    for (int i = 0; i < n; i++) {

        // Move left until a 0 is found
        bool flag=false; //to check whether a row has more 1's than previous

        while (j >= 0 && matrix[i][j] == 1) {
            j = j - 1; // Update the index of leftmost 1 seen so far
            flag=true; //present row has more 1's than previous
        }

        // if the present row has more 1's than previous
        if(flag){
            max_row_index = i; // Update max_row_index
        }
    }
    if(max_row_index==0&&matrix[0][m-1]==0)
        return -1;
    return max_row_index;
}


int main() {
	vector<vector<bool>> matrix = { {0, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    int n = matrix.size();
    int m = matrix[0].size();
	cout << "Index of row with maximum 1s is " << rowWithMax1s(matrix, n, m);

	return 0;
}
