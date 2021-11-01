#include <iostream>
using namespace std;

class Base
{
public:
    int base;
    virtual void display()
    {
        cout << "Base " << base << endl;
    }
};

class Derived : public Base
{
public:
    int derived;
    void display()
    {
        cout << "Base " << base << endl;
        cout << "Derived  " << derived << endl;
    }
};

int main()
{
    Derived dObj;
    Base *bPoint = &dObj;
    bPoint->base = 5;
    
    bPoint->display();
    return 0;
}