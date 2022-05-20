#include <bits/stdc++.h>
using namespace std;

//Approach - TC O(N*M * 2^2*target.size()) SC O(1)
int solve(int i, int j, string &target, vector<vector<char>> &mat, int size, int idx) {
    int found = 0;
    if(i>=0 && j>=0 && i<mat.size() && j<mat[0].size() && target[idx] == mat[i][j]) {
        char temp = mat[i][j];
        mat[i][j] = '0';
        idx++;
        
        if(idx==size) found=1;
        else {
            found += solve(i+1, j, target, mat, size, idx);
            found += solve(i-1, j, target, mat, size, idx);
            found += solve(i, j+1, target, mat, size, idx);
            found += solve(i, j-1, target, mat, size, idx);
        }
        mat[i][j] = temp;
    }
    return found;
}
    
int findOccurrence(vector<vector<char> > &mat, string target){
    int n = mat.size();
    int m = mat[0].size();
    
    int ans = 0;
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            ans += solve(i, j, target, mat, target.length(), 0);
    return ans;
    
}


int main() {
    string target = "SNAKES";
    vector<vector<char>> mat = {{'S','N','B','S','N'},
                                  {'B','A','K','E','A'},
                                  {'B','K','B','B','K'},
                                  {'S','E','B','S','E'}};

    cout << findOccurrence(mat, target);
}
