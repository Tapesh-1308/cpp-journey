#include<bits/stdc++.h>
using namespace std;

/* Method - 1 Linear Traversal TC O(N) SC O(1)
vector<int> firstAndLast(vector<int> &arr, int n, int x) {

    // To store the ans ans[0] -> 1st occ ans[1] -> 2nd occu
    vector<int> ans(2, 0); 

    bool flag = 0; // To check if we find any elements equal to x or not

    // Traverse the array
    for(int i=0; i<n;) {
        // If we found 1st occurance store it in ans[0]
        if(arr[i] == x) {
            ans[0] = i;
            flag = 1; // Mark it as 1 to ensure element is present no need to return -1

            // While we don't et last occu run this loop
            while(arr[i] == x and i<n) {
                ans[1] = i; // Store ans[1] 
                i++;  
            }
        }
        i++; 
    }
    //If flag is still false means, we didn't get any element equal to x
    if(!flag) return {-1};

    //Else return ans
    return ans;
}
*/

// Method - 2 Binary Search - TC O(logN) SC O(1)
// Binary search to find first occurance
int firstOccu(vector<int> &arr, int n, int x) {
    int st = 0, end = n-1; // Start and end pointer
    int mid, ans = -1;

    while(st<=end) {
        // Calulate mid
        mid = (st+end) / 2;
        
        if(arr[mid] == x) {
            // In binary search we just return here but to find 1st occurance
            // we need to further more search in left side to do this we will move
            // end to mid - 1 , ans update the ans alse
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < x) // If smaller means we need big elements so move right
            st = mid + 1;

        // If smaller move left       
        else end = mid -1;
    }
    
    // Return ans
    return ans;
}

int lastOccu(vector<int> &arr, int n, int x) {
    int st = 0, end = n-1;
    int mid, ans = -1;
    while(st<=end) {
        mid = (st+end) / 2;
        
        // Same code as firstoccu chang is instead of end = mid - 1 we will do
        // start = mid + 1 beause to find last occurance we need to search in 
        // right direction. 
        if(arr[mid] == x) {
            ans = mid;
            st = mid + 1;
        }
        else if (arr[mid] < x)
            st = mid + 1;
            
        else end = mid -1;
    }
    
    return ans;
}
vector<int> firstAndLast(vector<int> &arr, int n, int x){
    vector<int> ans(2, 0);
        
    ans[0] = firstOccu(arr, n, x); // Store 1st occ
    ans[1] = lastOccu(arr, n, x); // Store last occ
    
    // If we x is not present in array return -1; 
    if(ans[0] == -1 || ans[1] == -1)
        return {-1};
    
    // else return ans
    return ans;
}

int main(){
    vector<int> arr = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    int n = sizeof(arr) / sizeof(int);
     
    vector<int> ans = firstAndLast(arr, n, 5);

    for(auto i: ans)
        cout<<i<<" ";    
    return 0;
}