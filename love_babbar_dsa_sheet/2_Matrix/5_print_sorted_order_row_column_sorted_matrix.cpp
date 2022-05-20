#include <bits/stdc++.h>
using namespace std;


/* Method 1 Brute Force TC O(N^2 + N^2logN^2) SC O(N^2)
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> &Mat) {
    vector<int> nums;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            nums.push_back(Mat[i][j]);
        }
    }
    sort(nums.begin(), nums.end());
    int k=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            Mat[i][j] = nums[k++];
        }
    }
    return Mat;
} */

// Method 2 MinHeap TC O(N^2logN^2) SC O(N^2) 
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> &Mat) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            pq.push(Mat[i][j]);
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            Mat[i][j] = pq.top();
            pq.pop();
        }
    }
    return Mat;
} 


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        
        v = sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}