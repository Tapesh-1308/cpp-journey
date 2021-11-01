#include <iostream>
using namespace std;

//Function Over Loading
class Tapesh
{
public:
    void func()
    {
        cout << "Function with no arguements\n";
    }
    void func(int x)
    {
        cout << "Function with int arguements\n";
    }
    void func(double x)
    {
        cout << "Function with double arguements\n";
    }
};

//Operator Overloading
class Complex
{
private:
    int a, b;

public:
    Complex(int r = 0, int i = 0)
    {
        a = r;
        b = i;
    }

    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.b = b + obj.b;
        res.a = a + obj.a;
        return res;
    }

    void display()
    {
        cout << a << " + i" << b << endl;
    }
};

int main()
{
    // Tapesh obj;
    // obj.func();
    // obj.func(3);
    // obj.func(4.5);

    Complex c1(12, 7);
    Complex c2(6, 7);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}

