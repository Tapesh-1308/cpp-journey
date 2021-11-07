#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> temp = nums;
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

        for (int k = n-1; k != i; k--)
        {
            if (temp[k] == nums[j])
            {
                j = k;
                break;
            } 
        }
        for (int k = 0; k < n; k++)
        {
            if (temp[k] == nums[i])
            {
                i = k;
                break;
            } 
        }

    cout << i << " " << j << endl;
    return {i, j};
}

int main()
{
    vector<int> vec = {0,4,3,0};
    twoSum(vec, 0);
    return 0;
}