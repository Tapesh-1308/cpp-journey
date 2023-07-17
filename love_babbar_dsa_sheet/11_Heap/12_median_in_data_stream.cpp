#include <bits/stdc++.h>
using namespace std;

// max heap for left half (size can be 1 greater than min heap)
priority_queue<int> mx;

// min heap for right half
priority_queue<int, vector<int>, greater<int>> mn;

void insertHeap(int &x) {
    // 1st element or smaller than maximum of left half
    if (mx.empty() || x <= mx.top())
        mx.push(x); // go into left half
    else // otherwise go into right half
        mn.push(x);

    // Balance the heaps
    if (mx.size() > mn.size() + 1) {     // more elements in max heap?
        mn.push(mx.top());               // shift 1 element from max->min
        mx.pop();
    } else if (mn.size() > mx.size()) { // more elements in min heap?
        mx.push(mn.top());               // shift 1 element from min->mex
        mn.pop();
    }
}

// find median
double getMedian() {
    // for odd elements (median -> max.top)
    if(mx.size() > mn.size())
        return double(mx.top());
        
    // otherwise (max.top + min.top)/2
    else return (double(mx.top()) + double(mn.top()))/2;
}

int main() {
    int N = 4;
    int X[] = {5, 15, 1, 3};

    for (int i = 0; i < N; ++i) {
        insertHeap(X[i]);
        cout << getMedian() << endl;
    }

    return 0;
}
