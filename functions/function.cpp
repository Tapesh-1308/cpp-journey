#include <iostream>
#include <math.h>
using namespace std;

// Function prototype
// type function-name (arguments);
// int sum(int a, int b); //--> Acceptable
// int sum(int a, b); //--> Not Acceptable
// int sum(int, int); //--> Acceptable
// void g(void); //--> Acceptable
// void g(); //--> Acceptable

//Prime
// bool isPrime(int num){
//     for (int i = 2; i <= sqrt(num); i++)
//     {
//         if(num%i==0){
//             return false;
//         }
//     }
//     return true;
// }

//Fibonacci
/* void fib(int n){
    int t1= 0;
    int t2 = 1;
    int next;
    int i = 1;

    while(i <= n)
    {
        cout<<t1<<" ";
        next=t1+t2;
        t1 = t2;
        t2 = next;
        i++;

    }
    return;
} */

//Factorial
/* int fact(int num) {
    int factorial = 1;
    for (int i = num; i >= 1; i--)
    {
        factorial *= i;
    }
    return factorial;
} */

//nCr
 /* int fact(int num) {
    int factorial = 1;
    for (int i = num; i >= 1; i--)
    {
        factorial *= i;
    }
    return factorial; 
} */

//Pascle Triangle Pattern
/* int fact(int num) {
    int factorial = 1;
    for (int i = num; i >= 1; i--)
    {
        factorial *= i;
    }
    return factorial; 
}*/

int main()
{
    // int num1, num2;
    // cout << "Enter first number" << endl;
    // cin >> num1;
    // cout << "Enter second number" << endl;
    // cin >> num2;   
    // // num1 and num2 are actual parameters
    // cout << "The sum is " << sum(num1, num2);
    // g();

    //Prime
    /* int a, b;
    cin>>a>>b;
    for (int i = a; i < b; i++)
    {
        if(isPrime(i)){
            cout<<i<<endl;
        }
    } */

    //Fibonacci
    /* int n;
    cin>>n;

    fib(n); */
    
    //Factorial
    /* int n;
    cin>>n;

    cout<<fact(n);
    return 0; */

    //nCr
    /* int n, r;
    cin>>n>>r;
    int ans = fact(n)/(fact(r)*fact(n-r));
    cout<<ans; */

    //Pascle Triangle Pattern 
    //Output 
    // 1 
    // 1 1
    // 1 2 1
    // 1 3 3 1
    // 1 4 6 4 1
    // 1 5 10 10 5 1
    
    /* int n;
    cin>>n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
        }
        cout<<endl;
    } */
    

}

// int sum(int a, int b) {
//     // Formal Parameters a and b will be taking values from actual parameters num1 and num2.
//     int c = a + b;
//     return c;
// }

// void g() {
//     cout << "\nHello, Good Morning";
// }

