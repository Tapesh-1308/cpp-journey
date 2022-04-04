#include<bits/stdc++.h>
using namespace std;

// Program to search an element in 2d Array

/* This matrix has the following properties:
    *Integers in each row are sorted from left to right.
    *The first integer of each row is greater than the last 
     integer of the previous row.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) //If Matrix length is 0 return false
            return 0;
        
        int n = matrix.size(); //Length of row
        int m = matrix[0].size(); //Length of Column
        
        //Binary Search Implementation
        int low = 0, high = (n * m) - 1;
        int mid;
        while(low<=high){
            mid = (low + high)/2;
            
            /* Original Location where mid lies in 2d matrix can be access by mid/m and mid%m */
            if(matrix[mid/m][mid%m] == target) //If target is found return true
                return 1;
            
            else if (matrix[mid/m][mid%m] < target) //If found element is smaller then we have to search in right
                low = mid+1;
            
            else  //If found element is larger than target then we have to search in left
                high = mid-1;
            
        }
        //If not found return 0
        return 0;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 8;

    Solution ob;
    if(ob.searchMatrix(matrix, target))
        cout<<"Present\n";
    else cout<<"Not Present\n";

    return 0;
}