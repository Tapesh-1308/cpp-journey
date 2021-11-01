#include <iostream>
using namespace std;

int main()
{

    /********** Maximum Number **********/
    // int a, b, c;
    // cin>>a>>b>>c;
    // if(a>b){
    //     if(a>c){
    //         cout<<a<<endl;
    //     } else{
    //         cout<<c<<endl;
    //     }
    // } else{
    //     if(b>c){
    //         cout<<b<<endl;
    //     } else{
    //         cout<<c<<endl;
    //     }
    // }

    /**********Even Number***************/
    // int x;
    // cin >> x;
    // if (x%2==0) {
    //     cout<<"Even";
    // }
    // else {
    //     cout<<"Odd";
    // }

    /************Triangle is scalene, isosceles or equilateral.**********/
    // int a, b, c;
    // cout << "Input Side of a triangle\n";
    // cin >> a >> b >> c;
    // if (a == b && b == c && c == a)
    // {
    //     cout << "This is a equilateral Triangle";
    // }
    // else if (a == b || b == c || c == a)
    // {
    //     cout << "This is a isosceles Triangle";
    // }
    // else{
    //     cout << "This is a scalene Triangle";
    // }

    /*****************an alphabet is a vowel or a consonant****************/
    // char c;
    // cout << "Enter an alphabet: ";
    // cin >> c;
    // if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
    //     c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
    //     cout<<c<<" is a vowel\n";
    // }  else{
    //     cout<<c<<" is a constant\n";
    // }

    /************** Switch ***************/
    // char button;
    // cin >> button;
    // switch (button)
    // {
    // case 'a':
    //     cout << "Hello";
    //     break;
    // case 'b':
    //     cout << "Namaste";
    //     break;
    // case 'c':
    //     cout << "Salut";
    //     break;
    // case 'd':
    //     cout << "Hola";
    //     break;
    // case 'e':
    //     cout << "Ciao";
    //     break;
    // default:
    //     cout << "no cases left";
    //     break;
    // }

    /************ Simple Calculator **************/
    int a,b;
    char c;

    cout<<"1st Number : ";
    cin>>a;

    cout<<"Choose Operator (= - x /): ";
    cin>>c;

    cout<<"2nd Number : ";
    cin>>b;


    switch (c)
    {
    case '+':
        cout<<"Sum is : "<<(a+b);
        break;
    case '-':
        cout<<"Subtraction is : "<<(a-b);
        break;
    case 'x':
        cout<<"Multiplication is : "<<(a*b);
        break;
    case '/':
        cout<<"Division is : "<<(a/b);
        break;
    
    default:
    cout<<"You can only use '+ - x /'";
        break;
    } 
    return 0;
}