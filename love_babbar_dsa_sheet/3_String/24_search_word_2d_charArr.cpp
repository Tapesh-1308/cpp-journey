/* * Find all occurrences of given word in grid. A word can be matched in all 8 directions. 
   * Word is said be found in a direction if all characters match in this direction (not in zig-zag form). 
*/ 
#include<bits/stdc++.h>
using namespace std;

//Approach - TC O(N*M*8*word.length()) SC O(1)

//Direction Array X to move Up-Down Y to move Left-Right
int x[] = {-1, -1, -1, 0,  0, 1, 1,  1};
int y[] = {-1,  0,  1, 1, -1, 1, 0, -1};

bool solve(int i, int j, vector<vector<char>> &grid, string word){
    if(grid[i][j] != word[0]) return false; //If first word doesn't match return false

    int n = word.length();
    for(int dir = 0; dir < 8; dir++) { // check for all direction

        /* rd -> row direction
           cd -> column direction */
        int k, rd = i+x[dir], cd = j+y[dir]; 

        for(k=1; k<n; k++) {  // Check for complete word from 1 as 0th index is already matched if we are here
            // if we cannot move in direction ( right or up or down or left )
            if(rd<0 || rd>=grid.size() || cd<0 || cd>=grid[0].size()) break;

            //if any element didn't match
            if(grid[rd][cd] != word[k]) break;

            //increment rd and cd to the same direction as zigzag is not allowed
            rd += x[dir];
            cd += y[dir];
        }
        //If above loop runs completely i.e. k = n, means we found the word then return true
        if(k==n) return true;
    }

    //If we do not found word in all 8 directions return false
    return false;
}

vector<vector<int>> search(vector<vector<char>> &grid, string word) {
    vector<vector<int>> ans; // To store ans

    //Traverse the grid
    for(int i=0; i<grid.size(); i++) 
        for(int j=0; j<grid[0].size(); j++) 
            if(solve(i, j, grid, word)) 
                ans.push_back({i, j}); // if we get true in above function means we found the word then push its row, col index

    //return the ans
    return ans;
}

int main(){
    vector<vector<char>> grid = {{ 'a', 'b', 'c'}, 
                                 { 'd', 'r', 'f'},
                                 { 'g', 'h', 'i'}};
    string word = "abc";

    vector<vector<int>> ans = search(grid, word);
    
    if(ans.size() == 0) cout<< -1; //If there is no word in grid

    for(auto i: ans) {
        cout<<"Pattern found at : ";
        for(auto j : i)
            cout<<j<<" ";
    }
        
    return 0;
}