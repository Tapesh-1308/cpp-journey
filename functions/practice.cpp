#include <iostream>
using namespace std;

int naturalNum(int n)
{
    int ans = (n * (n + 1)) / 2;
    return ans;
}

void pyth(int p, int b, int h)
{
    if ((p * p) + (b * b) == (h * h))
    {
        cout << "Pythagoras Triplet";
    }
    else
    {
        cout << "Not a Pythagoras Triplet";
    }
    return;
}

int bTod(int n)
{
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 2;
        n /= 10;
    }
    return ans;
}

int oTod(int n)
{
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 8;
        n /= 10;
    }
    return ans;
}

int hxTod(string n)
{
    int ans = 0;
    int x = 1;
    int s = n.size();

    for (int i = s - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += x * (n[i] - '0');
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            ans += x * (n[i] - 'A' + 10);
        }
        x *= 16;
    }
    return ans;
}

int dTob(int n)
{
    int x = 1;
    int ans = 0;
    while (x <= n)
        x *= 2;
    x /= 2;
    while (x > 0)
    {
        int lastdig = n / x;
        n -= lastdig * x;
        x /= 2;
        ans = ans * 10 + lastdig;
    }
    return ans;
}

int dToO(int n)
{
    int x = 1;
    int ans = 0;
    while (x <= n)
        x *= 8;
    x /= 8;
    while (x > 0)
    {
        int lastdig = n / x;
        n -= lastdig * x;
        x /= 8;
        ans = ans * 10 + lastdig;
    }
    return ans;
}

string dToHx(int n)
{
    int x = 1;
    string ans = "";
    while (x <= n)
        x *= 16;
    x /= 16;
    while (x > 0)
    {
        int lastDig = n / x;
        n -= lastDig * x;
        x /= 16;

        if (lastDig <= 9)
        {
            ans = ans + to_string(lastDig);
        }
        else
        {
            char c = 'A' + lastDig - 10;
            ans.push_back(c);
        }
    }
    return ans;
}

int reverse(int n){
    int ans = 0;
    while(n>0)
    {
        int lastDig = n%10; 
        ans = ans*10 + lastDig;
        n /= 10;
    }
    return ans;
}
int binaryAddition(int a, int b)
{
    int ans = 0;
    int prevCarry = 0;
    while (a > 0 && b > 0)
    {
        if (a % 2 == 0 && b % 2 == 0){
            ans = ans*10 + prevCarry;
            prevCarry = 0;
        }
        else if((a%2 == 1 && b%2 == 0) || (a%2 == 0 && b%2 == 1)){
            if(prevCarry == 1){
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            else{
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        else{
            ans = ans*10 + prevCarry;
            prevCarry = 1;
        }
        a /= 10; b /= 10;
    }
    while(a>0){
        if (prevCarry == 1)
        {
           if(a%2 == 1){
               ans = ans*10 + 0;
               prevCarry = 1;
           }
           else{
               ans = ans*10 + 1;
               prevCarry = 0;
           }
        }

        else{
            ans = ans*10  - (a%2);
        }
        a /=10;
    }
    while(b>0){
        if (prevCarry == 1)
        {
           if(b%2 == 1){
               ans = ans*10 + 0;
               prevCarry = 1;
           }
           else{
               ans = ans*10 + 1;
               prevCarry = 0;
           }
        }

        else{
            ans = ans*10  - (b%2);
        }
        b /=10;
    }
    if(prevCarry == 1){
        ans = ans*10 + 1;
    }

    ans = reverse(ans);
    return ans;
}

int main()
{
    // 1) Question Sum of first n natural numbers
    // int n;
    // cin>>n;
    // cout<<naturalNum(n);

    // 2) Question Check Pythagoras Triplet
    // int p,b,h;
    // cin>>p>>b>>h;
    // pyth(p, b, h);

    // 3) Question Binary to Decimal Conversion
    // int n;
    // cin>>n;
    // cout<<bTod(n);
    // return 0;

    // 4) Question Octal to Decimal Conversion
    // int n;
    // cin>>n;
    // cout<<oTod(n);
    // return 0;

    // 5) Question Hexadecimal to Decimal Conversion
    // string n;
    // cin >> n;
    // cout << hxTod(n);

    // 6) Question Decimal to Binary Conversion
    // int n;
    // cin >> n;
    // cout<<dTob(n);

    // 7) Question Decimal to Octal Conversion
    // int n;
    // cin >> n;
    // cout<<dToO(n);

    // 8) Question Decimal to Hexadecimal Conversion
    // int n;
    // cin>>n;
    // cout<<dToHx(n);

    // 9) Question Adding to Binary Numbers
    // int a, b;
    // cin >> a >> b;
    // cout<<binaryAddition(a, b);

}
