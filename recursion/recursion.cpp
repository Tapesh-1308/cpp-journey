#include <iostream>
using namespace std;

/*************** Recursion ***************/
int Sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int prevSum = Sum(n - 1);
    return n + prevSum;
}

int fib(int n)
{
    if(n < 2){
        return 1;
    }
   return fib(n-2) + fib(n-1); 
}

int power(int n, int p){
    if(p==0){
        return 1;
    }
    int prevPower = power(n, p-1);
    return n*prevPower;
}

int fact(int n){
    if(n==0){
        return 1;
    }
    return  n * fact(n-1);
}

int main()
{
    //Sum of nth number
    // int n;
    // cin >> n;
    // cout << Sum(n);

    //Fibonacci Using recursion
    // cout<<fib(6);

    //n^p
    // int n, p;
    // cin>>n>>p;
    // cout<<power(n, p);
    // return 0;

    //Factorial
    int n;
    cin>>n;
    cout<<fact(n);

}