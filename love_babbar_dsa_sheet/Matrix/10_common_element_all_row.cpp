#include<bits/stdc++.h>
using namespace std;

//Approach - HashMap TC O(N*M) SC O(M)
void printCommonElements(vector<vector<int>> &matrix) {
    unordered_map<int, int> um;
    for(int i=0; i<matrix[0].size(); i++) 
        um[matrix[0][i]] = 1;
    
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(um[matrix[i][j]] == i) {
                um[matrix[i][j]] = i+1;

                if(i==matrix.size()-1 && um[matrix[i][j]] == matrix.size())
                    cout<<matrix[i][j]<<" ";
            }
        }
    }
}

int main(){

    vector<vector<int>> matrix = { {1, 2, 1, 4, 8},
                                   {3, 7, 8, 5, 1},
                                   {8, 7, 7, 3, 1},
                                   {8, 1, 2, 7, 9} };
 
    printCommonElements(matrix);
 
    return 0;
}