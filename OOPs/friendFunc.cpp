#include <iostream>
using namespace std;

/* Properties of friend functions
    1. Not in the scope of class
    2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
    3. Can be invoked without the help of any object
    4. Usually contans the objects as arguments
    5. Can be declared inside public or private section of the class
    6. It cannot access the members directly by their names and need object_name.member_name to access any member.
*/

class Complex;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int sumRealComplex(Complex, Complex);
    int comRealComplex(Complex, Complex);
};

class Complex {
    int a, b;
    //It will make freind of class' function
    // friend int Calculator ::sumRealComplex(Complex o1, Complex o2);
    // friend int Calculator ::comRealComplex(Complex o1, Complex o2);
    //It will make freind of whole class
    friend class Calculator;

public:
    void setData(int n1, int n2) {
        a = n1;
        b = n2;
    }

    // friend Complex sumComplex(Complex o1, Complex o2);
    void printNum() {
        cout << a << " + " << b << "i" << endl;
    }
};

int Calculator ::sumRealComplex(Complex o1, Complex o2) {
    return (o1.a + o2.a);
}
int Calculator ::comRealComplex(Complex o1, Complex o2) {
    return (o1.b + o2.b);
}

// Complex sumComplex(Complex o1, Complex o2) {
//     Complex o3;
//     o3.setData((o1.a + o2.a), (o1.b + o2.b));
//     return o3;
// }

int main() {
    // Complex c1, c2, sum;

    // c1.setData(1, 5);
    // c1.printNum();

    // c2.setData(5, 1);
    // c2.printNum();

    // sum = sumComplex(c1, c2);
    // sum.printNum();
    Complex o1, o2;
    o1.setData(1, 4);
    o1.printNum();
    o2.setData(5, 7);
    o2.printNum();

    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "Sum of real part is " << res << endl;
    int comRes = calc.comRealComplex(o1, o2);
    cout << "Sum of comlex part is " << comRes << endl;

    return 0;
}
