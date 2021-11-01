#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
    stack<pair<int,int>> s; 
    int index;
public:
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index +=1;
        
        while(!s.empty() && s.top().second<=price)    
            s.pop();

        if(s.empty())
        {   s.push({index,price});      return index+1;   }
        
        int result = s.top().first;
        s.push({index,price});
        return index-result;        
    }
};


int main() {
    // Stock span problem leetcode-901 -> O(n^2) - Brute Force
    /* vector<int> stock = {100, 80, 60, 70, 60, 75, 85};
    int n = stock.size();
    vector<int> count(n);
    for (int i = 0; i < n; i++) {
        count[i] = 0;
        int j = i;
        while(stock[j]<=stock[i] and j>=0){
            count[i]++;
            j--;
        }
    }
    for (auto i : count) {
        cout<<i<<" ";
    } */

    /* vector<int> stock = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans;
    stack<pair<int, int>> s;

    for (auto i : stock){
        int day = 1;
        while(!s.empty() and s.top().first <= i){
            day += s.top().second;
            s.pop();
        }
        s.push({i, day});
        ans.push_back(day);
    }
    
    for (auto i : ans) {
        cout<<i<<" ";
    } */

    StockSpanner* obj = new StockSpanner;
    cout<<obj->next(100);
    cout<<obj->next(80);
    cout<<obj->next(60);
    cout<<obj->next(70);
    cout<<obj->next(60);
    cout<<obj->next(75);
    cout<<obj->next(85);
    
    return 0;
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */