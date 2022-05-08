#include<bits/stdc++.h>
using namespace std;

// Method 
    // Time Complexity -> O(nLogn)
    // Space Complexity -> O(1)

// Function to check if scheme can be allocated 
bool isValid(int a[], int n, int mx, int m) {
    int cntst = 1;  // Count number of students
    int sum = 0; // store sum, tells when we reach to mx 
    
    // Traversing for every books
    for(int i=0; i<n; i++) {
        sum += a[i]; // Add curr pages to sum

        // If sum become greater than mx means, we can give more pages to this st
        // so we have increase count of students
        if(sum > mx) { 
            cntst++; 
            sum = a[i]; // Sum for another student will be curr book
        }
        
        // If we can't allocate to m students then its count will be greater than m
        // so return false
        if(cntst > m)
            return false;
    }
    
    return true;
}

int findPages(int a[], int n, int m)  {
    // If number of students of more than the number of books
    if(m > n) return -1;

    // sort array to apply binary search
    sort(a, a+n);
    
    // Search space b/w maximum element in array - sum of all array
    // we can maximum gives all book one person i.e. sum of all array->end
    int st = a[n-1];
    int end = 0;
    
    // Calulating sum
    for(int i=0; i<n; i++)
        end += a[i];
        
    int mid, res=-1;
    while(st <= end) {
        mid = st + (end-st)/2;
        
        // If we can allocate books with given mid (number of pages) to m students 
        // then we store it in res and we search for smaller number as we need minimum ans
        if(isValid(a, n, mid, m)) {
            res = mid;
            end = mid - 1;
        }
        // If we can not allocate minimum (mid number of pages) to m students and we need more students to allocate means mid is too small to increase it we search in left side
        else {
            st = mid+1;
        }
    }
        
    return res;
}

int main() {
    //Number of pages in books
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; //No. of students
 
    cout << "Minimum number of pages = "
         << findPages(arr, n, m) << endl;
    return 0;
}