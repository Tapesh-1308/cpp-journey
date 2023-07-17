// c++ program to finds out smallest range that includes
// elements from each of the given sorted lists.
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    int row;
    int nextCol;
    Node(int data, int row, int nextCol) {
        this->data = data;
        this->row = row;
        this->nextCol = nextCol;
    }
};

struct compare {
    bool operator()(Node a, Node b) {
        return a.data > b.data;
    }
};

void findSmallestRange(vector<vector<int> >& arr, int n, int k) {
    priority_queue<Node, vector<Node>, compare> pq;

    int maxi = 0;
    int range = INT_MAX;
    for (int i = 0; i < k; i++) {
        pq.push(Node(arr[i][0], i, 0));
        maxi = max(maxi, arr[i][0]);
    }

    int start = -1;
    int end = -1;
    while (!pq.empty()) {
        Node n1 = pq.top();
        pq.pop();
        int min = n1.data;
        if (range > maxi - min) {
            range = maxi - min;
            start = min;
            end = maxi;
        }
        int nextRow = n1.row;
        int nextColumn = n1.nextCol;
        if (n1.nextCol + 1 < n) {
            pq.push(Node(arr[nextRow][nextColumn + 1], nextRow, nextColumn + 1));
            maxi = max(maxi, arr[nextRow][nextColumn + 1]);
        } else
            break;
    }
    cout << start << " " << end << endl;
}
int main() {
    vector<vector<int> > arr = {{1, 3, 5, 7, 9},
                                {0, 2, 4, 6, 8},
                                {2, 3, 5, 7, 11}};

    int k = 3;

    findSmallestRange(arr, k, 3);
    return 0;
}