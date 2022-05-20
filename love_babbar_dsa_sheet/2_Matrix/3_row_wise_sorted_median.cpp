#include <bits/stdc++.h>
using namespace std;

//Method 1 - Brute Force || TC O(n*m) SC O(N)
/* int median(vector<vector<int>> &matrix, int row, int col) {
    vector<int> median(row * col);
    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++) 
            median.push_back(matrix[i][j]);
        
    sort(median.begin(), median.end());

    return median[(row * col) / 2];
} */

// Method 2 - Using Binary Search || TC O(32*Nlogm) SC = O(1)
class Solution{   
    int counter(vector<int> &row, int mid) {
        int l = 0, h = row.size()-1;
        int md;
        while(l<=h) {
            md = (l + h) >> 1;
            if(row[md] <= mid)
                l = md + 1;
            else h = md - 1;
        }
        return l;
    }
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int low = 0, high = 1e9;   
        int mid;
        while(low<=high) {
            mid = (low + high) >> 1;

            // Find count of elements smaller than mid
            int count = 0;
            for(int i=0; i<r; i++)
                count += counter(matrix[i], mid);
                
            if(count <= (r*c) / 2)  
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return low;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  