#include <iostream>
using namespace std;

int main()
{
                                // Pointers \\

    // What is a Pointer? ----> Data types which holds the address of other data types

    int a = 3;
    int *b;
    b = &a;

    // & ---> (Address  of) operator
    cout << "The Address of a is " << &a << endl;
    cout << "The Address of a is " << b << endl;

    // * ---> (value at) Derefrence operator
    cout << "The value at address b is " << *b << endl;

    //Pointer to Pointer
    int** c = &b;
     cout << "The Address of b is " << &b << endl;
    cout << "The Address of b is " << c << endl;
    cout << "The value at address c is " << *c << endl;
    cout << "The value at address ValueAt(valueAT(c)) is " << **c << endl;

    return 0;
}