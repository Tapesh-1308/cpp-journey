#include <iostream>
using namespace std;

void permutations(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);

        permutations(ros, ans + ch);
    }
}

int countPath(int s, int e){
    if(s==e)
        return 1;
    if(s>e)
        return 0;

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(s+i, e);
    }
    return count;
    
}

int countPathMaze (int n, int i, int j){
    if(i == n-1 && j == n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPathMaze(n, i+1, j) + countPathMaze(n, i, j+1);
}

int tillingWays(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    return tillingWays(n-1) + tillingWays(n-2);
}

int freindsPair(int n){
    if(n==0 || n==1 || n==2)
        return n;

    return freindsPair(n-1) + freindsPair(n-2)*(n-1);
}

int knapsack(int value[], int wt[], int n, int W){
    if(n==0||W==0)
        return 0;
    if(wt[n-1] > W)
        return knapsack(value, wt, n-1, W);
    
    return max(knapsack(value, wt, n-1, W-wt[n-1]) + value[n-1], knapsack(value, wt, n-1, W));
}

int main()
{
    //Permtation using recursion
    // permutations("ABC", "");

    //path counter
    // cout<<countPath(0, 50);

    //Maze Game
    // cout<<countPathMaze(3, 0, 0);

    //Ways to fill tilling
    // cout<<tillingWays(4);

    //Friends Pair Problem
    // cout<<freindsPair(4)<<endl;

    //0-1 knapsack problem
    // int wt[] = {10, 20, 30};
    // int value[] = {100, 50, 150};
    // int W = 50;
    // cout<<knapsack(value, wt, 3, W);
    
    return 0;
}