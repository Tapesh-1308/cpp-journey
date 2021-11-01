#include<iostream>
#include<fstream>
using namespace std;

int main() {
    string st = "Tapesh is a good boy";
    string st2;

    //Writing Operation
    // ofstream obj("sample.txt");
    // cin>>st2; 
    // obj<<st2 + " is a good boy";
    // obj.close();

    // Reading Operation
    ifstream obj2;
    obj2.open("sample.txt");
    // obj2>>st2;
    // getline(obj2, st2);

    while(!obj2.eof()){
        getline(obj2, st2);
        cout<<st2<<endl;
    }
    // cout<<st2;
    obj2.close();

    return 0;
}