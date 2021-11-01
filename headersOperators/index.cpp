// There are two types of header files:
// 1. System header files: It comes with the compiler
#include <iostream>
// 2. User defined header files: It is written by the programmer
// #include "tapesh.h" //--> This will produce an error if this.h is no present in the current directory

using namespace std;

int sum = 45;
int main()
{
    // int a=4, b=5;
    // cout<<"Operators in C++:"<<endl;
    // cout<<"Following are the types of operators in C++"<<endl;

    /******************** Arithmetic operators **************/
    // cout<<"The value of a + b is "<<a+b<<endl;
    // cout<<"The value of a - b is "<<a-b<<endl;
    // cout<<"The value of a * b is "<<a*b<<endl;
    // cout<<"The value of a / b is "<<a/b<<endl;
    // cout<<"The value of a % b is "<<a%b<<endl;
    // cout<<"The value of a++ is "<<a++<<endl;
    // cout<<"The value of a-- is "<<a--<<endl;
    // cout<<"The value of ++a is "<<++a<<endl;
    // cout<<"The value of --a is "<<--a<<endl;
    // cout<<endl;

    // Assignment Operators --> used to assign values to variables
    // int a =3, b=9;
    // char d='d';

    /***************** Comparison operators ********************/
    // cout<<"Following are the comparison operators in C++"<<endl;
    // cout<<"The value of a == b is "<<(a==b)<<endl;
    // cout<<"The value of a != b is "<<(a!=b)<<endl;
    // cout<<"The value of a >= b is "<<(a>=b)<<endl;
    // cout<<"The value of a <= b is "<<(a<=b)<<endl;
    // cout<<"The value of a > b is "<<(a>b)<<endl;
    // cout<<"The value of a < b is "<<(a<b)<<endl;

    /****************Logical operators***********/
    // cout<<"Following are the logical operators in C++"<<endl;
    // cout<<"The value of this logical and operator ((a==b) && (a<b)) is:"<<((a==b) && (a<b))<<endl;
    // cout<<"The value of this logical or operator ((a==b) || (a<b)) is:"<<((a==b) || (a<b))<<endl;
    // cout<<"The value of this logical not operator (!(a==b)) is:"<<(!(a==b))<<endl;
    // cout<<"The value of this logical not operator (!(a==b)) is:"<<(!(a==b))<<endl;

    /********** scope resolution operator ************/
    // int a, b, sum;
    // cout << "Enter 1st value: " << endl;
    // cin >> a;
    // cout << "Enter 2nd value: " << endl;
    // cin >> b;
    // sum = a + b;
    // cout << "This sum is " << sum << endl;
    // cout << "This sum is " << ::sum << endl;  // :: <- this is a scope resolution operator used to get global value


    /*********** Operator Precedence*****************/
    int a = 3, b = 4;
    int c = ((((a * 5) + b) - 45) + 87);
    cout << c;

    return 0;
}
