#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> us;
        for(int i=0; i<n; i++) us.insert(a[i]);
        for(int i=0; i<m; i++) us.insert(b[i]);
        
        for(auto &i : us)
            cout<<i<<" ";
        cout<<endl;
        
    }

    void doIntersection(int a[], int n, int b[], int m){
        unordered_set<int> us;
        int i=0, j=0;
        while(i!=n && j!=m){
            if(a[i]<b[j]) i++;
            else if (a[i]>b[j]) j++;
            else {
                us.insert(a[i]);
                i++; j++;
            }
        }
        for(auto &i : us)
            cout<<i<<" ";
        cout<<endl;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    ob.doUnion(a, n, b, m);
        ob.doIntersection(a, n, b, m);
	    
	}
	
	return 0;
}  