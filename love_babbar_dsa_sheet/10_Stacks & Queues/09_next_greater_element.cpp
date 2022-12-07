#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(n)
// Space complexity : O(n)

//Function to find the next greater element for each element of the array.
vector<int> nextLargerElement(vector<int> arr, int n) {
    // stores next greater of each element of arr
    vector<int> ans(n, -1); // ans[i] = next greater of arr[i]

    stack<int> s; // we will use stack to do it in O(n) time
    
    // traverse array from last
    for(int i=n-1; i>=0; i--) {
        // if stack is empty and top is also lesser than curr element, pop that element
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }
        
        // if stack does not becomes empty, means top is > than arr[i], which is next greater
        if(!s.empty())
            ans[i] = s.top(); 
            
        // if push curr element into the stack
        s.push(arr[i]);
    }
    
    // return the ans vector
    return ans;
}

int main(){
    vector<int> arr {1,3,2,4};
    int n = arr.size();

    // function call
    vector<int> ans = nextLargerElement(arr, n);

    // print the output
    for(auto i:ans){
        cout << i << " ";
    }

    return 0;
}