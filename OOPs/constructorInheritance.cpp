#include<iostream>
using namespace std;

class Base1{
    int data1;
    public:
    Base1(int b){
        cout<<"Base1 Constructor"<<endl;
        data1 = b;
    }
    void printB1(){
        cout<<data1<<endl;
    }
};

class Base2{
    int data2;
    public:
    Base2(int b){
        cout<<"Base2 Constructor"<<endl;
        data2 = b;
    }
    void printB2(){
        cout<<data2<<endl;
    }
};
class Derived: public Base2, public Base1{
    int derived1;
    int derived2;
    public:
    Derived(int a, int b, int c, int d):Base1(a), Base2(b){
        derived1 = c;
        derived2 = d;
        cout<<"Derived Constructor"<<endl;
    }

    void printDerived(){
        cout<<derived1<<endl;
        cout<<derived2<<endl;
    }
};


int main() {
    Derived tapesh(1, 2, 3, 4);
    tapesh.printB1();
    tapesh.printB2();
    tapesh.printDerived();
    return 0;
}