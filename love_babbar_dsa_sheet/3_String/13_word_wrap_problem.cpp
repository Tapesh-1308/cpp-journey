#include <bits/stdc++.h>
using namespace std;

int* solveWordWrap(vector<int>nums, int k) { 
    int n = nums.size();
    int costArr[n][n];
    
    for(int i=0; i<n; i++) {
        costArr[i][i] = k-nums[i];
        for(int j=i+1; j<n; j++) {
            costArr[i][j] = costArr[i][j-1] - nums[j] - 1;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(costArr[i][j] < 0) costArr[i][j] = INT_MAX;
            else costArr[i][j] *= costArr[i][j];
        }
    }
    
    int minCost[n];
    int result[n];
    
    
    for(int i = n-1; i >= 0 ; i--){
        minCost[i] = costArr[i][n-1];
        result[i] = n;
        for(int j=n-1; j > i; j--){
            if(costArr[i][j-1] == INT_MAX){
                continue;
            }
            if(minCost[i] > minCost[j] + costArr[i][j-1]){
                minCost[i] = minCost[j] + costArr[i][j-1];
                result[i] = j;
            }
        }
    }
    return result;

}
int main() {
    vector<int> words = {3,2,2,5};
	int k = 6;
  
	int *result = solveWordWrap(words, k);
    for(int i=0; i<words.size(); i++) {
        cout<<*(result+i)<<" ";
    }
    return 0;
}
