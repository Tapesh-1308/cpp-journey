#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Solution{
    private:
    int largestRectangleArea(int* vec, int n) { //This is the code for Largest Rectangle in Histogram Problem
       
        vector<int> left(n), right(n); //Left/Right stores left/right limit for every index
        stack<int> myStack;
        for (int i = 0; i < n; i++) { // Filling left vector
            if(myStack.empty()){    
                left[i] = 0;
                myStack.push(i);
            } else {
                while(!myStack.empty() and vec[myStack.top()]>=vec[i])
                    myStack.pop();
                left[i] = myStack.empty()?0:myStack.top()+1;
                myStack.push(i);
            }
        }
        while(!myStack.empty()) //Clearing Stack
            myStack.pop();

        for (int i = n-1; i >= 0; i--) { //Filling right array
            if(myStack.empty()){
                right[i] = n-1;
                myStack.push(i);
            } else {
                while(!myStack.empty() and vec[myStack.top()]>=vec[i])
                    myStack.pop();
                right[i] = myStack.empty()?n-1:myStack.top()-1;
                myStack.push(i);
            }
        }

        int area = 0;
        for(int i = 0; i<n; i++){ //Calulating area
            area = max(area, vec[i]*(right[i]-left[i]+1));
        }
        return area;
    }
    public:

    //Time Complexity O(n*m) SC O(m)
    int maxArea(int M[MAX][MAX], int n, int m) {
        //Area of 1st Row
        int area = largestRectangleArea(M[0], m);
        
        //Calculating Area for complete matrix
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j]!=0)
                    M[i][j] += M[i-1][j];
            }
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};


int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}