#include <bits/stdc++.h>
using namespace std;

// Method - 1 Hash Function - TC O(N^2) SC O(1)

//Calulate Hash
string hashing(string str){
    vector<int>hash(27,0);
    
    int i=0;
    while(str[i]!='\0') {
        hash[str[i]-96]++;
        i++;
    }
    
    string ans="";
    for(int i=0; i<hash.size(); i++) {
        if(hash[i]>0) {
            ans+= char(i+96);
            ans+= to_string(hash[i]);
        }
    }
    
    return ans;
}

vector<vector<string>> getAnagramsTogether(vector<string>& strs) {
    
    int n= strs.size();
    unordered_map<string, vector<string>>grouping_bucket;
    vector<vector<string>> ans;
    
    // Iterate over the string, and push value in map with same hash keys
    for(int i=0; i<n; i++) {
        string temp= hashing(strs[i]);
        grouping_bucket[temp].push_back(strs[i]);
    }
    
    //Fill ans from map
    for(auto itr: grouping_bucket)
        ans.push_back(itr.second);
    
    return ans;
}

// Method - Sorting - TC O(N*mlogm) SC O(N)
vector<vector<string>> getAnagramsTogether(vector<string> &strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> M;

    for(int  i = 0; i < strs.size(); i++) {
        string temp = strs[i];
        sort(strs[i].begin(), strs[i].end()); // Sorting the string
        M[strs[i]].push_back(temp);  // Sorted string is the key and the value is the initial string
    }
    for(auto i : M)
        ans.push_back(i.second);  // Traversing the map and adding the vectors of string to ans
    return ans;
}

// Method - HashMap - TC O(N * (M*log(N) + logN)) SC O(N*M)
vector<vector<string>> getAnagramsTogether(vector<string> &strs) {
    // To store all strings with there freq
    map<map<char, int>, vector<string>> um;

    // Traverse for every string
    for(auto s : strs) {
        map<char, int> temp;
        // Traverse in string
        for(int i=0; i<s.length(); i++) {
            // Store strings in map
            if(temp.find(s[i]) != temp.end()) {
                temp[s[i]]++;
            }
            else temp[s[i]] = 1;
        }

        // Store map in map of map 
        um[temp].push_back(s);
        
    }

    // Fill ans from map of map
    vector<vector<string>> ans;
    for(auto it: um) {
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
	vector<string> strs = { "cat", "dog", "tac", "god", "act" };
	vector<vector<string>> ans = getAnagramsTogether(strs);

    for(int i=0; i<ans.size(); i++)
        for(int j=0; j<ans[i].size(); j++)
            cout << ans[i][j] << " ";
    
	return 0;
}