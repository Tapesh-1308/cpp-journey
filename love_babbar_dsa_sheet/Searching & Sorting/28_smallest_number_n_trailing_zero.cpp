#include <bits/stdc++.h>
using namespace std;

// Count Number of trailing zeroes in N!

/* Method - 1 TC O(N!*N) SC O(N) (Stack Space)

// Function to find factorial
int factorial(int n) {
    if( n==0 || n==1 ) return 1;
    return n*factorial(n-1);
}

int findCount(int n) {
    // fact store N!
    int fact = factorial(n);

    int count=0; // Stores number of trailing zeroes
    while(fact%10 == 0){ //If divisble by 10 means last number is 0 
        count++; // Increment count, we get a trailing zero
        fact/=10; // Remove last number
    }
    return count;
} */

// Method - 2 TC O(log₅N) SC O(1)
int findCount(int n) {
    int count = 0;
    // Dividing n by multilples 5 and add it to count will give answer
    int i = 5;
    while(n/i > 0) { // Checking if n/i is not less then 0, n/5, n/25, n/125, if n is 40 then dividing it by 125 will give smaller value than 1
        count += n/i;  // updating count
        i*=5; // i-> 5->25->125->625
    }
    return count;
}

// Function to find smallest number whose factorial contains at least n trailing zeroes.

// Method - 1 Binary Search TC O(log₂N * log₅N) SC O(1)
int findSmallestNumber(int n) {
    //  the minimum value containing at least N trailing zeros is always less than or equal to 5*N.
    // Search space 0...5*n
	int lo = 0, high = 5*n;
    int mid;
    while(lo <= high) {
        mid = lo + (high-lo)/2;
        
        // This means that mid can be our answer but we need to check if there is any other number smaller than mid and with count >= N.
        if(findCount(mid) >= n) {
            high = mid-1;
        }
        // As, count < N, hence, mid cannot be our answer. So, we check for numbers greater than mid in hope of finding a number with count >= N.
        else lo = mid+1;
    }
    // Low contains our ans
    return lo;
}

int main() {
	int n = 2;
	cout << findSmallestNumber(n) << endl;
	return 0;
}
