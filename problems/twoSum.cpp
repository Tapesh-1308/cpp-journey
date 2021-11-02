#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int sum = nums[i] + nums[j];
        if (sum < target)
            i++;
        else if (sum > target)
            j--;
        else
            break;
    }

    cout << i << " " << j << endl;
    return {i, j};
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    twoSum(vec, 8);
    return 0;
}