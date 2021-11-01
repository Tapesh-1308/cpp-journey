#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    int ans = 0;
    for (auto &i : vec)
    {
        cin >> i;
    }
    cout<<endl;

    // Brute force approach O(n^2)
    /* for (int i = 0; i < n; i++) {
        int left = i;
        int right = i;
        while(vec[left] >= vec[i] and left >= 0 ){
            left--;
        }
        while(vec[right] >= vec[i]){
            right++;
        }
        left+=1;
        right-=1;
        int len = right-left+1;
        int area = len * vec[i];
        ans = max(ans, area);
    }
    cout<<ans; */

    // Let's optimize it with O(n)
    vector<int> left(n), right(n);

    stack<int> myStack;
    for (int i = 0; i < n; i++)
    {
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
    while(!myStack.empty())
        myStack.pop();
    
    for (int i = n-1; i >= 0; i--)
    {
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
    for(int i = 0; i<n; i++){
        area = max(area, vec[i]*(right[i]-left[i]+1));
    }
    cout << area;
    

    return 0;
}
