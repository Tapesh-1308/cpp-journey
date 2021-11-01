#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    for(auto i : dq){
        cout<<i<<" ";
    } cout<<endl;

    dq.pop_front();
    dq.pop_back();

    for(auto i : dq){
        cout<<i<<" ";
    } cout<<endl; */

    /* // Question Sliding Window maximum
    // Using set Time Complexity )(nlog(n))
     int n, k;
     cin >> n >> k;
     vector<int> a(n);
     for (auto &i : a) {
         cin >> i;
     }
     set<int, greater<int>> s;
     vector<int> ans;
     for (int i = 0; i < k; i++) {
        s.insert(a[i]);
     }
     ans.push_back(*s.begin());
     for (int i = k; i < n; i++) {
        s.erase(a[i-k]);
        s.insert(a[i]);
        ans.push_back(*s.begin());
     }
     for (auto i: ans) {
         cout<<i<<" ";
     } */

    // Let's optimize this by using deque in Time Complexity o(n)
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back(); 
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    for(int i = k; i<n; i++){
        if(q.front() == i-k){
            q.pop_front();
        }
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    for (auto &i : ans)
    {
        cout<<i<<" ";
    }
    

    return 0;
}
