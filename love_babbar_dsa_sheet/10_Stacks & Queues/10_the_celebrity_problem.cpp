#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), The total number of comparisons is 3(N-1).
// Auxiliary Space: O(N), n extra space is needed to store the stack.


// Returns -1 if celebrity is not present. If present, returns id (value from 0 to n-1).
int findCelebrity(int n, vector<vector<int>> &M) {
    
    // Store all persons in party in stack
    stack<int> st;
    for(int i=0; i<n; i++) 
        st.push(i);
        
    
    // run a while loop till stack size is atleast 2
    while(st.size() >= 2) {
        // get the top 2 elements from stack

        // first
        int i = st.top(); 
        st.pop();

        // second
        int j = st.top(); 
        st.pop();
        
        // check if first knows second
        if(M[i][j]) 
            st.push(j); // as 1st knows 2nd, 2nd can be celebrity so push it back
        else 
            st.push(i); // as 1st doesn't know 2nd, 1st can be celebrity so push it back this time
    }
    
    // after the loop, one element is remaining in the stack which can be celebrity
    int id = st.top();

    // check if id is celebrity or not
    for(int i=0; i<n; i++) 
        // if celebrity knows anyone or anyone doesn't know celebrity
        if(i!=id && (M[id][i] || !M[i][id] )) 
            return -1;
    
    // after checking return the celebrity 
    return id;
}

// Driver code
int main() {
    int n = 4;

    // Person with 2 is celebrity
    vector<vector<int>> M {{0, 0, 1, 0},
                         {0, 0, 1, 0},
                         {0, 0, 0, 0},
                         {0, 0, 1, 0}};

    int id = findCelebrity(n, M);

    id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}
