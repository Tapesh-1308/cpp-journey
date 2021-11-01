#include <iostream>
using namespace std;

int main()
{
    int n=5, m=5;
    int arr[n][m] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };

    //Spiral Order Matrix Traversal
    /* int rowStart = 0, rowEnd = 4, columnStart = 0, columnEnd = 4;

    while(rowStart <= rowEnd && columnStart <= columnEnd) {

        //row start
        for (int col = columnStart; col <= columnEnd; col++)
        {
            cout<<arr[rowStart][col]<<" ";
        }
        rowStart++;

        //column end
        for (int row = rowStart; row <= rowEnd; row++)
        {
            cout<<arr[row][columnEnd]<<" ";
        }
        columnEnd--;

        //row end
        for (int col = columnEnd; col >= columnStart; col--)
        {
            cout<<arr[rowEnd][col]<<" ";
        }
        rowEnd--;

        //column start
        for (int row = rowEnd; row >= rowStart; row--)
        {
            cout<<arr[row][columnStart]<<" ";
        }
        columnStart++;
    } */

    //Matrix Transpose
    /* for(int i = 0; i<5; i++){
        for (int j = i; j < 5; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } */

    //Matrix Multiplication
    /* int arr1[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int arr2[2][4] = {{7, 8, 9, 10}, {11, 12, 13, 14}};

    int ans[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ans[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ans[i][j] += arr1[i][k]*arr2[k][j];
            }
            
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    } */
    
    //Searching an element from 2d array
    /* int target;
    cin>>target;

    bool found = false;

    int r  = 0, c = m-1;
    while(r < n && c >= 0){
        if(arr[r][c] == target){
            found = true;
        }
        if(arr[r][c] > target){
            c--;
        }
        else{
            r++;
        }
    }

    if(found){
        cout<<"Element is Present\n";
    }
    else{
        cout<<"Element is Not present\n";
    } */

    return 0;
}