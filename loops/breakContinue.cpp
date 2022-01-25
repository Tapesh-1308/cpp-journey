#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Break and Continue

int main()
{
    //Break
    // for (int i = 0; i < 100; i++)
    // {
    //     if(i==50){
    //         break;
    //     }
    //     cout<<i<<endl;
    // }

    //Continue
    // for (int i = 0; i < 10; i++)
    // {
    //     if(i==5){
    //         continue;
    //     }
    //     cout<<i<<endl;
    // }

    // Write a program to print all odd numbers till n.
    // int n;
    // cout<<"Enter a number: ";
    // cin>>n;
    // for (int i = 0; i <= n; i++)
    // {
    //     if(i%2==0){
    //         continue;
    //     }
    //     cout<<i<<endl;
    // }

    // Write a program to check if a given number is prime or not.
    // int n;
    // cout<<"Enter a number: ";
    // cin >> n;
    // bool flag = 1;
    // for (int i = 2; i <= sqrt(n); i++) {
    //     if (n % i == 0) {
    //         flag = 0;
    //         break;
    //     }
    // }
    // if(flag) cout<<"This number is prime";
    // else cout<<"This number is not prime";

    

    // Write a program to print all prime numbers in a given range

    int a, b;
    cin >> a >> b;
    int j;

    for (int i = a; i < b; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if(j==i){
            cout<<i<<endl;
        }
    }

}