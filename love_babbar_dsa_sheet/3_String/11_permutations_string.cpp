#include<bits/stdc++.h>
using namespace std;

//Recursion TC O(N * N!) SC O(N)
void recursive(string a, int l, int r, vector<string> &ans) {
    if(l==r) 
        ans.push_back(a);
    
    
    else {
        for(int i=l; i<=r; i++) {
            swap(a[l], a[i]);
            recursive(a, l+1, r, ans);
            swap(a[l], a[i]);
        }
    }
}
vector<string>find_permutation(string S) {
    vector<string> ans;
    recursive(S, 0, S.length()-1, ans);
    sort(ans.begin(), ans.end());
    return ans;
}


int main(){
    int t;
    cin >> t;
    while(t--) {
	    string S;
	    cin >> S;
	    vector<string> ans = find_permutation(S);
	    for(auto i: ans) {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}