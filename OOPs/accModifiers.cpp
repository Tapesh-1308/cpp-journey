#include<iostream>
using namespace std;

// Public -> Access through Own class, Derived class, Outside the class.
// Private -> Access through only from Own class.
// Protected -> Access through only Own class, Derived class.

class A{
    public:
    int a;
    void funcA(){
        cout<<"FuncA\n";
    }
    private:
    int b;
    void funcB(){
        cout<<"FuncB\n";
    }
    protected:
    int c;
    void funcC(){
        cout<<"FuncC\n";
    }

};

int main() {
    A obj;
    obj.funcA();
    // obj.funcB(); // Throws Error - Private
    // obj.funcC(); // Throws Error - Protected

    return 0;
}   