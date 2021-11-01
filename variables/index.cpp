#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    /********** Float and Long Double Literals *********************/
    float d = 29.7F;
    long double e = 29.7L;
    cout << "The size of 34.4 is " << sizeof(34.4) << endl;
    cout << "The size of 34.4f is " << sizeof(34.4f) << endl;
    cout << "The size of 34.4F is " << sizeof(34.4F) << endl;
    cout << "The size of 34.4l is " << sizeof(34.4l) << endl;
    cout << "The size of 34.4L is " << sizeof(34.4L) << endl;
    cout << "d = " << d << endl
         << "e = " << e << endl;

    /************* Refrence Variables *********************/
    float x = 455;
    float &y = x;
    cout << x << endl;
    cout << y << endl;

    /*********** Typecasting Variables **********************/
    int a = 45;
    float b = 45.46;
    cout << int(b) << endl
         << endl;
    cout << a + b << endl;
    cout << a + int(b) << endl;
    cout << a + (int)b << endl;

    /*********** Manipulators in C++ **********************/
    int p = 3, q = 456, r = 43676;
    cout << "Value without setw: " << p << endl;
    cout << "Value without setw: " << q << endl;
    cout << "Value without setw: " << r << endl;
    cout << "Value: " << setw(10) << p << endl;
    cout << "Value: " << setw(10) << q << endl;
    cout << "Value: " << setw(10) << r << endl;

    /***************** Constants *******************/

    const int z = 5;
    // z = 6; // This will throw an error because we can't change constants

    cout << "Z = " << z << endl;
}