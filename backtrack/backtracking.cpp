#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
        return true;
    return false;
}

bool ratMaze(int **arr, int x, int y, int n, int **solArray)
{
    if (x == n - 1 && y == n - 1)
    {
        solArray[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solArray[x][y] = 1;
        if (ratMaze(arr, x + 1, y, n, solArray))
            return true;
        if (ratMaze(arr, x, y + 1, n, solArray))
            return true;
        solArray[x][y] = 0; //Backtracking
        return false;
    }
    return false;
}

bool isSafeQueen(int **arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
            return false;
    }

    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;

    while (row >= 0 && col < 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(int **arr, int x, int n)
{
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafeQueen(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }

            arr[x][col] = 0; // BackTraking
        }
    }
    return false;
}

int main()
{
    // Rat In Maze Problem
    /* int n;
    cin >> n;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<endl;

    int **solArr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }


    if (ratMaze(arr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j]<<" ";
            }cout<<endl;
        }
    } */

    // N - Queen Problem
    int n;
    cin >> n;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<arr[i][j]<<" ";
            }cout<<endl;
        }
    }
    return 0;
}