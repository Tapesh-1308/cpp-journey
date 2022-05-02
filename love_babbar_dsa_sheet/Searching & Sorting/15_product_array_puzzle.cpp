#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Simple Approach(If we are allowed to use / operator) TC O(N) SC O(1)
vector<int> productArray(vector<int> &nums) {
    int n = nums.size();

    // allProduct stores product of element in nums
    int allProduct = 1, flag = 0; //Flag store number of 0 in nums
    for(int i=0; i<n; i++) {
        if(nums[i] == 0) // Increment flag to count 0's
            flag++;
        else allProduct *= nums[i]; // else calculate product
    }

    vector<int> ans (n, 1); // Store the answer
    // Traverse the array nums
    for(int i=0; i<n; i++) {
        // If more than 0 in nums then all element will be 0
        if(flag > 1) ans[i] = 0;
        // If no zero then ans[i] will allproduct / curr element nums[i] to remove self element in product
        else if (flag == 0)
            ans[i] = allProduct/nums[i]; // Instead of using / we can also use x/y -> x*y^-1 
            // ans [i] = allProduct*pow(nums[i], -1);
        // If nums contain 1 -> 0 then all element in ans will be 0 except where 0 lies 
        else if (flag == 1 && nums[i] != 0)
            ans[i] = 0; 
        // If flag is 1 and nums[i] == 0 -> then it will be equal to product
        else ans[i] = allProduct;
    }
    // return answer
    return ans;
} */

/* Method - 2 Left Right Array TC O(3N)  SC O(2N)
vector<int> productArray(vector<int> &nums) {
    int n = nums.size();

    // Left -> left[i] stores product nums[0...i-1]
    // Right -> right[i] -> product nums[i+1...n-1]
    // Product -> Answer -> left[i] * right[i]
    vector<int> left(n, 1), right(n, 1), product(n, 1);

    // Fill left array
    for(int i=1; i<n; i++)
        left[i] = left[i-1] * nums[i-1];

    // Fill right array
    for(int j=n-2; j>=0; j--)
        right[j] = right[j+1] * nums[j+1];

    // Calculate product array
    for(int i=0; i<n; i++)
        product[i] = left[i] * right[i];

    // Return answer -> product
    return product;
} */

// Method - 3 1 Array TC O(2N)  SC O(N)
vector<int> productArray(vector<int> &nums) {
    int n = nums.size();
    // Instead of using 2 arrays, we first use ans as left, then right, then ans
    vector<int> product(n, 1);

    int temp = 1;

    // Fill product with left property product[i] = nums[0]*...*nums[i-1]
    for(int i=0; i<n; i++) {
        product[i] = temp;
        temp *= nums[i];
    }

    temp = 1;

    // Fill right side and also multiply left and right in a single loop product[i] = product[i+1]*nums[i+1]*...*nums[n-1]
    for(int i=n-1; i>=0; i--) {
        product[i] *= temp;
        temp *= nums[i];
    }

    return product;
} 

int main(){
    vector<int> nums  = {10, 3, 5, 6, 2};
    
    vector<int> ans = productArray(nums);
    for( auto i:ans )
        cout << i << " ";
    return 0;
}