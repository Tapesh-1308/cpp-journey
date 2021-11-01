#include <iostream>
#include <cmath>
using namespace std;

class SimpleCalc {
    float a, b;

public:
    void getDataSimple() {
        cout << "\nEnter the value of a: ";
        cin >> a;
        cout << "Enter the value of b: ";
        cin >> b;
    }
    void calcSim() {
        cout << "\nThe value of a + b is " << a + b << endl;
        cout << "The value of a - b is " << a - b << endl;
        cout << "The value of a * b is " << a * b << endl;
        cout << "The value of a / b is " << a / b << endl;
    }
};

class SciCalc {
    float a;

public:
    void getDataSci() {
        cout << "\nEnter the value of a: ";
        cin >> a;
    }
    void calcSci() {
        cout << "\nThe value of sin(a) is " << sin(a) << endl;
        cout << "The value of cos(a) is " << cos(a) << endl;
        cout << "The value of tan(a) is " << tan(a) << endl;
        cout << "The value of sqrt(a) is " << sqrt(a) << endl;
    }
};
class HybricCalc : public SimpleCalc, public SciCalc {
    
};

int main()
{
    HybricCalc obj;
    obj.getDataSimple();
    obj.calcSim();
    obj.getDataSci();
    obj.calcSci();
    return 0;
}