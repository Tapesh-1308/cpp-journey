//Pointers with class
/* #include <iostream>
using namespace std;

class Complex {
    int real, imaginary;

public:
    void setData(int a, int b) {
        real = a;
        imaginary = b;
    }

    void getData() {
        cout << "Real: " << real << endl;
        cout << "Imaginary: " << imaginary << endl;
    }
};

int main()
{
    // Complex obj;
    // Complex * (ptr) = &obj;
    // (*ptr).setData(1, 5);
    
    Complex * (ptr) = new Complex;

    //Array of pointers 
    Complex * (ptr) = new Complex[4];

    ptr->setData(1, 5);
    ptr->getData();
    (ptr+1)->setData(6, 10);
    (ptr+1)->getData();

    return 0;
} */





//Pointers with derived class
/* #include <iostream>
using namespace std;

class Base
{
public:
    int base;
    void display()
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

    Derived *dPoint = &dObj;
    dPoint->base = 6;
    dPoint->derived = 7;
    dPoint->display();

    return 0;
} */