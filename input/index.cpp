#include <iostream>
using namespace std;

int main() 
{
    // This is '<<' an insertion operator
    // This is '>>' an extraction operator

    cout << "Input Tut\n";

    int amount1, amount2;
    cout << "Enter the first amount ";
    cin >> amount1;

    cout << "Enter the second amount ";
    cin >> amount2;

    int sum = amount1 + amount2;

    cout << "The sum is " << sum;
    return 0;
}
