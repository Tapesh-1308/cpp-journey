#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// Method - 1 Visted Array - TC O(N) SC o(N)
void findMissingAndRepeating(int arr[], int n) {
    // To store output
    int repeating(0), missing(0);

    bool visited[n+1] = {false}; // Checks if arr[i] is visited or not

    // Traverse on array and mark element as visited
    for(int i=0; i<n; i++) {
        // If already visited and come again then it must be repeated
        if(visited[arr[i]])
            repeating = arr[i]; // Update repeating
        // Marke arr[i] visited
        visited[arr[i]] = true;
    }

    // If any number is missing the visited array of missing element index is false 
    for(int i=1; i<=n; i++) {
        // If visited[i] is false, means we didn't visited this
        if(!visited[i]){
            missing = i;
            break;
        }
    }
    // Print ans
    cout <<"Repeating: " << repeating << endl
         <<"Missing: "<< missing << endl;
}

// Method - 2 Maths - TC O(N) SC O(1)
void findMissingAndRepeating(int arr[], int n) {
    // sumArr - Stores sum of input array element
    // sumNum - Store sum of 1 to N numbers
    ll sumArr=0, sumNum=0;

    // sumArrSq - Stores sum of squares input array element
    // sumNumSq - Store sum of square from 1 to N numbers
    ll sumArrSq=0, sumNumSq=0;
    
    // Calculating sumArr and sumArrSq
    for(int i=0; i<n; i++) {
        sumArr+=arr[i];
        sumArrSq+=arr[i]*arr[i];
    }
    
    // Calculating sumNum and sumNumSq
    // -> n(n+1)/2 - formula used for sumNum
    // -> n(n+1)(2n+1) / 6 - formula used for sumNumSq
    sumNum = (n*(n+1))/2;
    sumNumSq = (n*(n+1)*((2*n) + 1)) / 6;
    
    // xmy -> x - y (x minus y)
    ll xmy = sumArr - sumNum;

    // xSmyS -> (x^2 - y^2)
    ll xSmyS = sumArrSq - sumNumSq;
    
    // find x + y = by dividing x-y with x^2 - y^2
        // i.e x^2 - y^2 = (x+y)(x-y)
        // xpy = (x+y)(x-y) / (x-y)
    ll xpy = xSmyS / xmy;
    
    // By adding x+y + x-y , we get 2x value divide by 2 we get x -> repeating
    ll repeating = (xpy + xmy) / 2;

    // put x value in x+y -> we get y -> missing
    ll missing = xpy - repeating;

    //Print ans
    cout <<"Repeating: " << repeating << endl
         <<"Missing: "<< missing << endl;
}


// Method - 3 Bit Manipulation - TC O(N) SC O(1)
void findMissingAndRepeating(int arr[], int n) {
    int repeating(0), missing(0);

    // To xor of complete array, x -> set bits bucket, y -> unset bit bucket 
    int xor1 = arr[0],x = 0, y = 0;
    
    //  Calulate xor of complete array
    for(int i=1; i<n; i++)
        xor1 ^= arr[i];
    
    // calulate xor of 1 to N and xor with xor1
    for(int i=1; i<=n; i++)
        xor1 ^= i; // Easy method
        
    // Find the right most set bit using this formula
    int rightMostSetBit = xor1 & ~(xor1 - 1);

    // Putting all element in x if its bit is set else put in y
    for(int i=0; i<n; i++){
        // If set
        if(arr[i] & rightMostSetBit)
            x^=arr[i]; // Bucket is keep doing xor of values
        else
            y^=arr[i];
    }
    
    // Putting all 1 to N in x and y bucket
    for(int i=1; i<=n; i++){
        // if set
        if(i & rightMostSetBit)
            x^=i; // keep doing xor 
        else y^=i;
    }

    // After this loop x and y contain repeating and missing element, but not sure which one is missng and which one is repeating

    // Let's find 
    bool flag=0;
    for(int i=0; i<n; i++){
        if(y == arr[i]){ // if Y present in arr[i] means it is repeating
            repeating = y;
            missing = x; // if is repeating then x definately be missing
            flag = 1;
            break;
        }
    }
    // if y is not present in arr[], means y is missing, then x will be repeating
    if(!flag) { 
        repeating = x;
        missing = y;
        
    }

    cout <<"Repeating: " << repeating << endl
         <<"Missing: "<< missing << endl;
}

// Method - 4 Swap Sort - TC O(N) SC O(1)
void findMissingAndRepeating(int arr[], int n) {
    int repeating(0), missing(0);

    // Traver the arr
    int i=0; 
    while(i < n) {
        // If the element is on its correct place
        if(arr[i] == arr[arr[i]-1])
            i++; // increment
        else
            // if it is not in the correct place swap with its correct position
            swap(arr[i], arr[arr[i]-1]);
    }
    
    // Find repeating and missing
    for(int i=0; i<n; i++){
        // if any element is not in its correct position
        if(arr[i] != i+1){
            repeating = arr[i]; // Then it will be repeating
            missing = i+1; // And, that place actual element is missing
            break;
        }
        
    }
    // Print answer
    cout <<"Repeating: " << repeating << endl
         <<"Missing: "<< missing << endl;
}

int main(){

    int arr[] = {1, 2, 1, 3};
    int n = sizeof(arr)/sizeof(int);

    findMissingAndRepeating(arr, n);

    return 0;
}