#include<bits/stdc++.h>
using namespace std;

/* Problem :
* Dexter was good in finding the K th smallest number from a set of numbers. He thought he could solve any problem related to K th smallest number. His friend Pipi challenged him with a problem.
* He gave him various ranges of number, These numbers were arranged in increasing order(only distinct numbers to be taken into account). Now he asked him to find the K th smallest number in the sequence, again and again.
* 
* Input Format
* The first line contains T, the number of test cases.
* For each test case, there will be two integers N and Q.
* Then N lines follow each line containing two integers A and B (denoting the range A-B)
* Then Q lines follow each line containing a non-negative integer K .

* Output Format
* For each query output the K th smallest number.

* Constraints
* 1 <= T <= 100
* 1 <= N <= 100
* 1 <= Q <= 1000
* -10^18 <= A <= B <= 10^18
* K >= 1
* 
* Note: If Kth smallest number is not present in the series, print -1
* 
* Sample Input
* 1
* 1 3
* 1 5
* 1
* 3
* 6
* Sample Output
* 1
* 3
* -1
* Explanation
* The numbers are "1 2 3 4 5". The 1st smallest number is 1
* The 3rd smallest number is 3 The 6th smallest number is not present. Hence answer is -1

* Time Limit: 5
* Memory Limit: 256 */

#define ll long long int

// Time Complexity O(t * (nlogn + 2n + q*n) )
// Space Complexity O(n)

int main() {
    // t -> Number of testcases
	ll t; cin>>t;
	while(t--) {
        // N -> Number of ranges
        // Q -> Number of K
		ll n, q;
		cin>>n>>q;
        // Stores all ranges
		vector<pair<ll, ll>> intervals;
	    for(ll i=0; i<n; i++) {
            // St -> Range Starting
            // End -> Range Ending
			ll st, end; // (st - end)
			cin>>st>>end;
			intervals.push_back({st, end});
	    }
        // Sort the ranges 
	    sort(intervals.begin(), intervals.end());
	    
        // Merging ranges that can be merges as we knly need distinct elements
	    ll idx = 0;
	    for(ll i=1; i<n; i++) {
            // If we can merge (1, 5) (3, 7) 5>=3 
	        if(intervals[idx].second >= intervals[i].first) {
                // (1, 5) (3, 7) ->  max (5, 7) = (1, 7)
	            intervals[idx].second = max(intervals[idx].second, intervals[i].second);
	        }
            // If we can't merge
	        else {
	            idx++;
                // (1, 7) (3, 7) (10, 15) -> (1, 7) (10, 15) (10, 15) we will search till idx means we don't take 10, 15 two times
	            intervals[idx] = intervals[i];
	        }
	    }
			
		while(q--) {
            // K -> kth smallest number to find
			ll k;
			cin>>k;
			
			ll ans=-1;
            // Traversing from 0 to idx to avoid last duplicates
			for(ll i=0; i<=idx; i++) {
                // If k can lie in range k = 9, (1, 5) 5-1+1 = 5 >= 9 No so kth smallest can't lie in this range.
                // If lies (1, 5) k = 4 5-1+1 = 5 >= 4 True!
    			if(intervals[i].second-intervals[i].first + 1 >= k) {
                    // ans will be (1, 5) = {1,2,3,4,5} k = 4 
                    // ans should be = ar[k-1->3] = 4
                    // 1 + 4 - 1 = 4
    			    ans = intervals[i].first + k - 1;
    			    break;
    			}
                // We reach here when we k can't lie in range then we have to check for another, so before checking we decrement k 
                // (1, 5) (10, 15) k = 9 k can't lie in 1st range then we have to traverse for 2nd  range (10, 15) k will be = 9 - (5-1+1) = 4 
                // 1 2 3 4 5 10 11 12 13 14 15 after 10 arr[k-1] arr[3] = 13
    			else k -= (intervals[i].second-intervals[i].first+1);
			}
			cout << ans << endl;
		}
	}
	return 0;
}