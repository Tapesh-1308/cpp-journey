#include<iostream>
using namespace std;

int divisible(int n, int a, int b){
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);

    return c1+c2-c3;
}

// GCD = HCF (Highest Common Factor)
int gcd(int a, int b){
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main() {
    //Program To Find Number divisible by both a and b 
    /* int n, a, b;
    cin>>n>>a>>b;
    cout<<divisible(n, a, b); */

    //Program to Find GCD - Highest Common Factor
    /* int a, b;
    cin>>a>>b;
    cout<<gcd(a, b); */
    
    return 0;
}