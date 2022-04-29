#include<bits/stdc++.h>
using namespace std;

// Method - 1 Brute Force - TC O(N^2) SC O(1)
int majorityElement(int arr[], int n) {
    // maxCount -> stores count of majority element
    // count -> store count of ith element
    // index -> store index of majority element
    int maxCount(INT_MIN), count(0), index;

    // Traverse on the array
    for(int i=0; i<n; i++) {
        count = 0;
        // Calculate count of arr[i]
        for(int j=0; j<n; j++) {
            if(arr[i]==arr[j])
                count++;
        }

        // calculate max of count and maxcount, and update index with i
        if(count > maxCount) {
            maxCount = count;
            index = i;
        }
    }

    // if maxCount is greater than n/2 return majority element else return -1
    return maxCount > n/2 ? arr[index] : -1;
}

// Method - 2 Bit Masking - TC O(NlogN) SC O(1)
int majorityElement(int arr[], int n) {
    // Number of bits in the integer
    int len = sizeof(int) * 8;
 
    // Variable to calculate majority element
    int number = 0;
 
    // Loop to iterate through all the bits of number
    for (int i = 0; i < len; i++) {
        int count = 0;
        // Loop to iterate through all elements in array
        // to count the total set bit at position i from right
        for (int j = 0; j < n; j++) 
            if (arr[j] & (1 << i)) // check set bit at ith position
                count++;
        
        // If the total set bits exceeds n/2, this bit should be 
        // present in majority Element.
        if (count > (n / 2))
            number += (1 << i);
    }
 
    int count = 0;
 
    // iterate through array get the count of candidate majority element
    for (int i = 0; i < n; i++)
        if (arr[i] == number)
            count++;
 
    // Verify if the count exceeds n/2
    if (count > (n / 2))
        return number;
    
    return -1;
}

// Method - 3 Hashmap - TC O(N) SC O(N)
int majorityElement(int arr[], int n) {
    // To store frequency of each element in array
    unordered_map<int, int> um;
        
    for(int i=0; i<n; i++) {
        // Increment frequency
        um[arr[i]]++;
        // In case frequency becomes greater than n/2, then return arr[i]
        if(um[arr[i]] > n/2) {
            return arr[i];
        }
    }
    return -1;
}

// Method - 4 Moore's Voting Algorithm - TC O(N) SC O(1)
int majorityElement(int arr[], int n) {
    int majority = arr[0]; // Stores majority element
    int count = 0; // Stores count
    
    for(int i=0; i<n; i++){
        // If getting same element increment its count
        if(arr[i] == majority)
            count++;
        else {
            // If it is not equal to prev element decrement count
            count--;

            // If count becomes 0 means its time to update majority            
            if(count == 0) {
                majority =  arr[i];
                // reinitialise count as 1
                count = 1;
            }
        }
    }

    // If majority is is actually majority element
    count=0;
    for(int i=0; i<n; i++)
        // to check calculate the count of majority 
        if(arr[i] == majority)
            count++;

    // if yes, return majority else return -1
    return count > n/2 ? majority : -1;
}

int main(){
    int arr[] = {5, 2, 3, 5, 5};
    int n = sizeof(arr)/sizeof(int);

    int ans = majorityElement(arr, n);

    if(ans != -1)
        cout << "Majority Element: " << ans << endl;
    else cout << "No Majority Element";

    return 0;
}