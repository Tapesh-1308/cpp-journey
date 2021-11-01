#include<iostream>
using namespace std;

bool isPowerOf2(int n){
    return (n && !(n & (n-1)));
}

int noOfOne(int n){
    int count = 0;
    while (n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

void subsets (int arr[], int n) {
    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i & (1<<j))
                cout<<arr[j]<<" ";
        } cout<<endl;
    } 
}

int uniqueNo(int arr[], int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
    
}

int getBit(int n, int pos) {
    return ((n & (1<<pos))!=0);
}

int setBit(int n, int pos) {
    return (n | (1<<pos));
}

void twoUniqueNo(int arr[], int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    while(setbit != 1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if(getBit(arr[i], pos-1)){
            newxor = newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(newxor^tempxor)<<endl;
    
}

int uniqueThree(int arr[], int n){
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }
        if(sum%3 != 0){
            result = setBit(result, i);
        }        
    }
    return result;
}

void countBits (int n) {
    int ans[n+1];     
    ans[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i/2] + i%2;
    }
    for (int i = 0; i <= n; i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main() {
    // 1st Challenge: Check if a number is power of 2 or not
    // cout<<isPowerOf2(3)<<endl;

    // 2nd Challenge: Program to count ones in a Binary
    // cout<<noOfOne(16)<<endl;

    //3rd Challenge: Program to Print all subarrays 
    // int arr[4] = {1, 2, 3, 4};
    // subsets(arr, 4);

    //4th Challenge: Program to Find Unique Number
    // int arr[7] = {1, 2, 3, 4, 1, 2, 3};
    // cout<<uniqueNo(arr, 7);

    // 5th Challenge: Program to Find 2 Unique Number
    // int arr[8] = {1, 2, 3, 1, 2, 3, 7, 5};
    // twoUniqueNo(arr, 8);

    // 6th Challenge: Program to Find Unique Number from triplets
    // int arr[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};
    // cout<<uniqueThree(arr, 10);

    // Leet Code Challenge: Counting Bits
    // int n;
    // cin>>n;
    // countBits(n);


    return 0;
}