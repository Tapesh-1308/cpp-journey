#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i, j;
    for (auto k : nums)
    {
        if (k < 0)
        {
            i = n - 1;
            j = 0;
            break;
        }
        else
        {
            i = 0;
            j = n - 1;
            break;
        }
    }

    if (i < j)
    {

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
    }

    if (i > j)
    {

        while (i > j)
        {
            int sum = nums[i] + nums[j];
            if (sum < target){
                j++;
            }
            else if (sum > target){
                i--;
            }
            else
                break;
        }
    }
    // int temp = nums[j];
    // nums[j] = nums[n-1];
    // nums[n-1] = temp;

    cout << i << " " << j << endl;
    return {i, j};
}

int main()
{
    vector<int> vec = {-1, -2, -3, -4, -5, -1};
    twoSum(vec, -8);
    return 0;
}