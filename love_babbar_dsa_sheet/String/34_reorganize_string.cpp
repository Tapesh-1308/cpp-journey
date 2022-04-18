// Rearrange characters in a string such that no two adjacent are same
#include<bits/stdc++.h>
using namespace std;

// Comparator for Min Heap
struct comparator {
    bool operator()(pair<char, int> &p1, pair<char, int> &p2){
        return p1.second < p2.second;
    }
};

string reorganizeString(string s) {
    pair<char, int> myPair; // To store char with freq in minHeap
    unordered_map<char, int> um; // To calculate freq

    // Calculating freq
    for(int i=0; i<s.length(); i++)
        um[s[i]]++;
    
    //Creating minHeap
    priority_queue<pair<char, int>, vector<pair<char, int>>, comparator> pq;

    // Pushing a pair in min heap    
    for(auto &i : um)
        pq.push({i.first, i.second});

    // Pushing 1st element in ans
    string ans = "";
    auto block = pq.top();
    pq.pop();
    ans.push_back(block.first);
    block.second--;

    // For another element
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        ans.push_back(temp.first);
        temp.second--;

        if(block.second > 0)
            pq.push(block);
        
        block = temp;
    }
    if(block.second > 0) return "";
    return ans;
}

int main(){
    string ans = reorganizeString("aab");
    if(ans.empty())
        cout<<"Not Possible\n";
    else cout<<ans<<endl;

    return 0;
}