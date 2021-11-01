#include <iostream>
using namespace std;

// A --> B - Single Inheritance

// A --> B --> C - Multi-Level Inheritance

// A -->
//      -->C - Multiple Inheritance
// B -->

// A <--
//      <--C -  Hirerachial Inheritance
// B <--

//      A <--
//               <--D 
//       <-- C <--              - HybridInheritance
//               <--E 
//      B <--
 
// 9812012345

class Employee {
    int id;
    public:
    float salary;
    Employee(int inpid){
        id = inpid;
        salary = 34.0;
    }
    Employee(){}                                       
};

/*  Note:
1. Default visibility mode is private.
2. class Programmer : {{(public) <- This is visibility Mode}} Employee.
3. Public visibility mode: Public Member of base class becomes public in derived class.
4. Private visibility mode: Public Member of base class becomes private in derived class.
5. Private members never inherited. */

class Programmer : Employee {
    public:
    int id;
    Programmer(int inpId){
        id = inpId;
    }
    int languageCode = 9;
    void getData(){
        cout<<id<<endl;
    }
};

int main() {
    Employee harry(1), rohan(2);
    cout<<harry.salary<<endl;
    cout<<rohan.salary<<endl;
    Programmer tapesh(3);
    tapesh.getData();

    return 0;
}
// 9812012345