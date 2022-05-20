#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public: 

    //  * Time Complexity -> O(Row*Column)
    //  * Space Complexity -> O(1)
    

    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)  {
        int top = 0, down = r-1;
        int left = 0, right = c-1;

        /* 
        Top -> starting row index
        Down -> ending row index
        Left -> starting column index
        Right -> ending column index
        */

        int dir = 0;
        vector<int> ans;
        
        while(top<=down && left<=right) {
            if(dir==0) {
                //Print the first row
                for(int i=left; i<=right; i++) 
                    ans.push_back(matrix[top][i]);
                top+=1;
            }
            
            else if(dir==1) {
                //Print the last column
                for(int i=top; i<=down; i++)
                    ans.push_back(matrix[i][right]);
                right-=1;
            }
            
            else if(dir==2) {
                //Print the last row 
                for(int i=right; i>=left; i--)
                    ans.push_back(matrix[down][i]);
                down-=1;
            }
            
            else if(dir==3) {
                //Print the first column
                for(int i=down; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left+=1;
            }
            dir = (dir+1)%4;  // If dir become 4 then it will be = 0
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}