#include<iostream>
// #include<queue> -> Use this for priority queue
#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int , vector<int>> pq1; // max heap
    priority_queue<int , vector<int>, greater<int>> pq2; //min heap
    pq1.push(2);
    pq1.push(3);
    pq1.push(1);
    // cout<<pq1.top()<<endl;//3
    // pq1.pop();
    // cout<<pq1.top()<<endl;//2

    pq2.push(8);
    pq2.push(7);
    pq2.push(6);
    // cout<<pq2.top()<<endl;//6

    cout<<pq1.size()<<endl;//3

    return 0;
}