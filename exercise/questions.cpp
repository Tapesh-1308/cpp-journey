#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    //Checking if a numbers is prime or not
    /* int n;
    cin >> n;
    bool flag = 0;    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if ((n % i) == 0)
        {
            cout << "Non-Prime";
            flag = 1;
            break;
        }
    }
    if (flag==0)
    {
        cout << "Prime";
    } */

    //Reversing a Number
    /* int n;
    cin>>n;

    int reverse =0;

    while(n>0){
        int lastdigit = n%10;
        reverse = reverse*10 + lastdigit;
        n=n/10;
    }

    cout<<reverse<<endl; */

    //Checking if a number is armstrong or not
    /* int n;
    cin >> n;

    int sum = 0;
    int originaln = n;

    while (n > 0)
    {
        int lastdigit = n % 10;
        sum += lastdigit * lastdigit * lastdigit;
        n = n / 10;
    }

    if (sum == originaln)
    {
        cout << "Yes it is an Armstrong Number\n";
    }
    else
    {
        cout << "No it is not an Armstrong Number\n";
    } */

    //Factorial of a Number n
    /* int n;
    cin>>n;

    int fact = 1;

    for (int i = n; i >= 1; i--)
    {
        fact *= i;
    }
    cout<<fact<<endl; */

    //Fibonacci Series
    /* int n;
    cin >> n;

    if (n == 0 || n == 1)
    {
        cout << "0";
    }
    else if (n == 2)
    {
        cout << "0 1";
    }
    else
    {
        int curr, a = 0, b = 1, i = 3;
        cout << a << " " << b << " ";
        while (i <= n)
        {
            curr = a + b;
            cout << curr << " ";
            a = b;
            b = curr;
            i++;
        }
        cout << endl;
    } */

    
    return 0;
}