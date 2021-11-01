#include<iostream>
using namespace std;

class A{
    int a;
    public: 

    // void setData(int a){
    //     this->a = a;
    // }
    
    A & setData(int a){
        this->a = a;
        return *this;
    }
    void getData(){
        cout<<a<<endl;
    }
};

// this is a keyword which is a pointer which points to the object which inkvokes the member function 

int main() {
    A a;
    a.setData(10).getData();
    a.getData();
    return 0;
}   