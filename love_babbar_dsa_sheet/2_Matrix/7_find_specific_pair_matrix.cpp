#include<bits/stdc++.h>
using namespace std;


//Method 1 Brute Force TC O(N^4) SC O(1)
int findMaxValue(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int ans = INT_MIN;

    for(int a=0; a<n; a++) 
    for(int b=0; b<n; b++)
        for(int c=a+1; c<n; c++)
        for(int d=b+1; d<n; d++)
            ans = max(ans, matrix[c][d] - matrix[a][b]);

    return ans;
}

//Method 2  

int main(){
    vector<vector<int>> matrix = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout << "Maximum Value is " << findMaxValue(matrix);

    return 0;
}
