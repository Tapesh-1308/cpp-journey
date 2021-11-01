#include<iostream>
using namespace std;

class A{
    int a;
    int b;
    public:
    A(int x, int y): b(x), a(y){
        cout<<"a = "<<a<<endl; 
        cout<<"b = "<<b<<endl; 
    }
};

int main() {
    A obj(1, 2);
    
    return 0;
}