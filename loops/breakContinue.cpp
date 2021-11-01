#include <iostream>
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
    // int i;
    // for (i = 2; i < n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         cout << "This number is not Prime" << endl;
    //         ;
    //         break;
    //     }
    // }
    // if (i == n)
    // {
    //     cout << "This number is Prime";
    // }

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

    return 0;
}