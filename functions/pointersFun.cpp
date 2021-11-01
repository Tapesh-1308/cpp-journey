#include<iostream>
using namespace std;

void swap (int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
void swapRef (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapRefVar (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // Swap Function 
    int a = 2, b = 4;
    // swap(a, b); // Not work
    // swapRef(&a, &b); // Work
    swapRefVar(a, b); //Work
    // swapRefVar(a, b) = 565; //return refrence
    cout<<a<<" "<<b;
    return 0;
}