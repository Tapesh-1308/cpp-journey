// Activity selection problem.
#include <bits/stdc++.h>
using namespace std;

// custom comparator, to sort pair on the basis of second value in increasing order
struct comp{
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
};

// Approach - Greedy - TC O(NlogN) SC O(N)

// n --> Total number of activities
// start[] --> An array that contains start time of all activities
// end[] --> An array that contains finish time of all activities
int activitySelection(int start[], int end[], int n)
{
    // store start and end in one vector
    vector<pair<int, int>> ans;
    for(int i=0; i<n; i++) {
        ans.push_back({start[i], end[i]});
    }
    
    // sort end time in increasing order 
    sort(ans.begin(), ans.end(), comp());
    
    // always pick first activity
    int prev = ans[0].second; // store first activity ]gg end time in prev
    int res = 1; // result initialied with 1 as one we take one activity 

    // traverse on remaining activities
    for(int i=1; i<n; i++) {
        // if we can take curr activity -> start time is greate than previously taken end time
        if(ans[i].first >  prev) {
            res++; // increment result 
            prev = ans[i].second; // and update prev with curr activity end time
        }
    }
    
    // return the maximum number of activity we selected
    return res;
}

int main()
{
	int start[] = {1, 3, 0, 5, 8, 5};
	int end[] = {2, 4, 6, 7, 9, 9};
	int n = sizeof(start)/sizeof(start[0]);
	cout << activitySelection(start, end, n) << endl;
	return 0;
}
