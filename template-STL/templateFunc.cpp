#include<iostream>
using namespace std;

template<class T1, class T2>

float avg(T1 a, T2 b){
    float avgAns = (a+b)/2.0;
    return avgAns;
}

template<class T>
class myClass{
    public:
    T data;
    myClass(T a){
        data = a;
    }
    void display();
};

template<class T>
void myClass<T> :: display(){
    cout<<data<<endl;
}

void func(int a){
    cout<<"func "<<a<<endl;
}

template<class A>
void func(A a){
    cout<<"Template "<<a<<endl;
}

int main() {
    // cout<<avg(5, 2);

    // myClass<int> obj(5);
    // cout<<obj.data<<endl;
    // obj.display();

    // func(2);
    // func<int>(2); 
    return 0;
}
