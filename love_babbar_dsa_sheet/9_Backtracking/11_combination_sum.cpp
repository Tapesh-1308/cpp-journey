// find all combinations that sum to a given value
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^t * k) where t is the target, k is the average length of every combination generated
// Space Complexity: O(k*x), k is the average length and x is the no. of combinations

// recursive function that finds all combination
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
    // base case
    // If index == size of array and  target == 0 include the combination in our answer
    if (ind == arr.size()) {
        if (target == 0)
            ans.push_back(ds);
        
        return;
    }

    // picking up the element
    if (arr[ind] <= target) { // only if target is >= curr element
        // add curr element to ans
        ds.push_back(arr[ind]);

        // call for same element by substracting target by curr element
        findCombination(ind, target - arr[ind], arr, ans, ds);

        // backtrack
        ds.pop_back();
    }

    // not picking the element, so increment index
    findCombination(ind + 1, target, arr, ans, ds);
}

// wrapper function over findCombination()
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    // ans -> store all combinations
    vector<vector<int>> ans;

    // ds -> data structure contains current combination
    vector<int> ds;
    
    // sort input array to get ans in sorted order
    sort(candidates.begin(), candidates.end());
 
    // remove duplicates if testcases contains duplicates
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    // call recursive function
                // index, target, ip arr, answer, ds->data structures that contains curr combination
    findCombination(0, target, candidates, ans, ds);

    // return answer
    return ans;
}
 
int main() {
    vector<int> v{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}