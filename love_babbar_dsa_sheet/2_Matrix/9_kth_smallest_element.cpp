#include <bits/stdc++.h>
using namespace std;

/* Method 1 Brute Force TC O(N^2 + N^2logN^2) SC O(N^2)
int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();

    vector<int> temp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            temp.push_back(matrix[i][j]);
        }
    }
    sort(temp.begin(), temp.end());

    return temp[k-1];
} */

/* Method 2 Priority Queue TC (N^2logK) SC O(N)
int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix.size(); j++) 
            pq.push(matrix[i][j]);

    for(int i=1; i<k; i++) 
        pq.pop();
    
    return pq.top();
} */

//Method 3 Binary Search + Upper bound TC (N(NlogN)) SC O(1)
int kthSmallest(vector<vector<int>> &matrix, int k){
    int n = matrix.size();
    int low = matrix[0][0], hi = matrix[n-1][n-1];
    int mid;
    while(low<=hi) {
        mid = (low+hi) / 2;

        int count = 0;
        for(int i=0; i<n; i++) 
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        
        if(count < k) 
            low = mid+1;
        else hi = mid-1;
    }
    return low;
}
  
int main() {
	int n = 4;
	vector<vector<int>> matrix = { {10, 20, 30, 40},
                                   {15, 25, 35, 45},
                                   {25, 29, 37, 48},
                                   {32, 33, 39, 50} };  
	cout << "7th smallest element is " << kthSmallest(matrix, 7);
	return 0;
}
