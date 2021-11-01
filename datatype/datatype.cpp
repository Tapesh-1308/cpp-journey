#include <iostream>
using namespace std;

int main()
{
    int a;
    float b;
    char c = 'y';
    bool d;
    double e;
    short int f;
    long int g;
    string h = "Tapesh";

    cout << "Size int " << sizeof(a) << endl;
    cout << "Size float " << sizeof(b) << endl;
    cout << "Size char " << sizeof(c) << endl;
    cout << "Size bool " << sizeof(d) << endl;
    cout << "Size double " << sizeof(e) << endl;
    cout << "Size short " << sizeof(f) << endl;
    cout << "Size long " << sizeof(e) << endl;
    cout << "\n"
         << h;

    return 0;
}