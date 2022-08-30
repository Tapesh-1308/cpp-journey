// Find maximum trains for which stoppage can be provided
#include <bits/stdc++.h>
using namespace std;

// Approach - TC O(mlogm) SC O(m)

// function to calculate maximum trains stoppage
int maxStop(vector<vector<int>> &train, int m, int n)
{
    // Create a array of vector of pair ‘platform’ -> { [], [()()()], [()()], [()] }
    vector<pair<int, int>> plat[n+1];

    // pair stores (departure, arrival), store data in plat, index denotes platform
    for(int i=0; i<m; i++) {
        plat[train[i][2]].push_back({train[i][1], train[i][0]});
    }

    // apply sort for all trains for a platform i, sort according to departure time
    for(int i=1; i<=n; i++) {
        sort(plat[i].begin(), plat[i].end());
    }
    
    // store ans
    int ans = 0;

    // store trains currently standing on a platform
    int lastSelected = 0;
    
    // now maximize the ans
    for(int i=1; i<=n; i++) {
        // if no train schedule on ith platform
        if(plat[i].size() == 0) continue;

        // always take 1st train of every platform
        ans++;
        lastSelected = plat[i][0].first; // store departure time of selected train
        
        // now traverse for all trains of ith platform
        for(int j=1; j<plat[i].size(); j++) {
            // if train can stop of ith platform i.e. arrival time of current train is greate or equal then last selected train
            if(plat[i][j].second >= lastSelected) {
                // select curr train
                ans++;
                lastSelected = plat[i][j].first; // update last selected ->departure time of curr train
            }
        }
    }
    
    // return the ans
    return ans;
}

int main()
{
    // n -> number of platforms
    // m -> number of trains
    int n = 3, m = 6;

    // Trains 2d Array -> {arrival, departure, platform}
	vector<vector<int>> trains = {  {1000, 1030, 1},
                                    {1010, 1030, 1},
                                    {1000, 1020, 2},
                                    {1030, 1230, 2},
                                    {1200, 1230, 3},
                                    {900 , 1005, 1} };

	cout << "Maximum Stopped Trains = " << maxStop(trains, m, n);
	return 0;
}
