// CHOCOlA - chocolate - SPOJ , same as minimum cost to cut board
#include <bits/stdc++.h>
using namespace std;

// TC - O(mlogm+nlogn)
// SC - O(1)

// method returns minimum cost to break board into m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
	int res = 0;

	// sort the horizontal cost in reverse order
	sort(X, X + m, greater<int>());

	// sort the vertical cost in reverse order
	sort(Y, Y + n, greater<int>());

    // hzntl -> stores number of horizontal peices 
    // vert -> stores number of vertical peices 

	// initialize as 1 -> while baord
	int hzntl = 1, vert = 1;

	// loop until one or both cost array are processed
	int i = 0, j = 0;
	while (i < m && j < n)
	{
        // process larger cost edge first
		if (X[i] > Y[j])
		{
            // total_cost = total_cost + edge_cost * peices (vert for horizontal cut)
			res += X[i] * vert;

			// increase current horizontal peices count by 1
			hzntl++;
			i++; // increment i
		}
		else
		{
            // total_cost = total_cost + edge_cost * peices (hzntl for vertical cut)
			res += Y[j] * hzntl;

			// increase current vertical peices count by 1
			vert++;
			j++; // increment j
		}
	}

	// loop for horizontal array, if remains
	while (i < m)
		res += X[i++]*vert;

	// loop for vertical array, if remains
	while (j < n)
		res += Y[j++]*hzntl;

	return res;
}

int main()
{
    int t; cin>>t;
    while(t--) {
	    int m, n;
	    cin>>m>>n;
    	int X[m-1];
    	int Y[n-1];
    	
    	for(int i=0; i<m-1; i++) cin>>X[i];
    	for(int i=0; i<n-1; i++) cin>>Y[i];
	    cout << minimumCostOfBreaking(X, Y, m-1, n-1)<<endl; 
    }
	
	
	return 0;
}
