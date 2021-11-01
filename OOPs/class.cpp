#include <iostream>
using namespace std;

// Creating a Constructor
    // Constructor is a special member function with the same name as of the class.
    //It is used to initialize the objects of its class
    //It is automatically invoked whenever an object is created

class students
{
    string name;

public:
    int age;
    bool gender;

    students()
    {
        cout << "Default constructor" << endl;
    } // Default constructor

    students(string s, int a, int g)
    {
        cout << "Parameterised constructor" << endl;
        name = s;
        age = a;
        gender = g;
    } // parameterised constructor

    students(students &a)
    {
        cout << "Copy constructor\a" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    } // Copy constructor
        
    ~students()
    {
        cout << "Destructor Called" << endl;
    }

    void setName(string s); // setter

    // void getName(){
    //     cout<<name<<endl;
    // } // getter

    // 2nd method of defining a function in class we can first declare and then define outside the class

    void getName(); // Declaration

    void printInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }

    bool operator==(students &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
            return true;
        return false;
    }
};

// Defining already declared function at line no. -> 43
// :: <-- This is scope resolution operator

void students ::setName(string s)
{
    name = s;
    getName(); // Nesting Function
}

void students ::getName()
{
    cout << name << endl;
}

int main()
{
    // students a;
    // a.name = "Tapesh";
    // a.age = 16;
    // a.gender = 1;

    students arr[1];
    for (int i = 0; i < 1; i++)
    {
        string s;
        cout << "Name = ";
        cin >> s;
        arr[i].setName(s);
        cout << "Age = ";
        cin >> arr[i].age;
        cout << "Gender = ";
        cin >> arr[i].gender;
    }

    // arr[1].getName();
    // for (int i = 0; i < 1; i++)
    // {
    //     arr[i].printInfo();
    // }

    // students a("Tapesh", 16, 1);
    // students b;
    // students c = b;

    // if(c==a){
    //     cout<<"Same"<<endl;
    // } else{
    //     cout<<"Not Same"<<endl;
    // }

    return 0;
}