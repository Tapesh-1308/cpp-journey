#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Method 1 Brute Force TC O(n^3) SC O(1)
        /* for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(A[i] + A[j] + A[k] == X)
                        return 1;
        return 0; */

        //Method 2 Sorting + Three Pointer O(nlogn + n^2) Sc O(1)
        /* sort(A, A+n);
        for(int i=0; i<n; i++){
            int l=i+1;
            int r = n-1;
            while(l<r){
                if(A[i] + A[l] + A[r] == X)
                    return 1;
                else if (A[i] + A[l] + A[r] < X)
                    l++;
                else r--;
            }
        }
        return 0; */
        
        //Method 3 Hashset TC O(n^2) SC (n)
        unordered_set<int> us;

        for(int i=0; i<n; i++){
            int curr = X - A[i];
            for(int j=i+1; j<n; j++){
                if(us.find(curr-A[j]) != us.end())
                    return 1;
            }
            us.insert(A[i]);
        }
        return 0;
    }

};


int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}