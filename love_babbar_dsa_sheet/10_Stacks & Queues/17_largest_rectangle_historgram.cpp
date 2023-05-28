#include <bits/stdc++.h>
using namespace std;

/**
 * Approach - Optimized TC O(N) SC O(N)
*/

int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    int max_area = 0;

    // same code snippet as next smaller index problem
    for (int i = 0; i < heights.size(); i++) {
        while (!stk.empty() and heights[stk.top()] >= heights[i]) {
            int current_height = heights[stk.top()];
            stk.pop();
                            // i is nsi and stk.top() is psi and nsi-psi-1 is width
            int current_width = i - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        stk.push(i);
    }

    // some remaining elements in stack
    while (stk.empty()) {
        int current_height = heights[stk.top()];
        stk.pop();

        // nsi will be n
        int current_width = heights.size() - stk.top() - 1;
        max_area = max(max_area, current_height * current_width);
    }
    return max_area;
}

int main()
{
    vector<int> hist{5, 6, 4, 3, 7, 5};
    cout << "Maximum area is " << largestRectangleArea(hist);
    return 0;
}