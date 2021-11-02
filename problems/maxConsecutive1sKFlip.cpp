// Leetcode problem - 1004
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& vec, int k) {
        int n = vec.size(); 

        int zerocnt=0, i=0;
        int ans=0;
        for (int j = 0; j < n; j++) {
            if(vec[j]==0) zerocnt++;
            while(zerocnt>k){
                if(vec[i]==0) zerocnt--;
                i++;
            }
            ans = max(ans, j-i+1);
        } 
        return ans;
    }
};

int main() {
    vector<int> vec = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    Solution obj;
    cout<<obj.longestOnes(vec, 3);
    

    return 0;
}