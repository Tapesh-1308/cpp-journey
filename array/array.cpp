#include<iostream>
using namespace std;

int main() {
    // Array
    //We can make an array like this 
    int mathMarks[4];
    mathMarks[0] = 10;
    mathMarks[1] = 20;
    mathMarks[2] = 30;
    mathMarks[3] = 40;

    //This is 2nd methods to make an array
    int marks[] = {11, 21, 31, 41}; 

    cout<<"This is math marks"<<endl; 
    cout<<mathMarks[0]<<endl; 
    cout<<mathMarks[1]<<endl; 
    cout<<mathMarks[2]<<endl; // Output --> 30

    // We can change anrray value like this
    mathMarks[2] = 255; 
    cout<<mathMarks[2]<<endl; // Output --> 255
    
    cout<<mathMarks[3]<<endl; 

    cout<<"This is  marks"<<endl; 

    // cout<<marks[0]<<endl; 
    // cout<<marks[1]<<endl; 
    // cout<<marks[2]<<endl; 
    // cout<<marks[3]<<endl; 

    // Now we will see how can we print elements of an array using loop

    //For loop
    cout<<"Using for loop"<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<"Marks is "<<marks[i]<<endl;
    }
    //While Loop
    cout<<"Using while loop"<<endl;
    int i = 0;
    while(i<4){
        cout<<"Marks is "<<marks[i]<<endl;
        i++;
    }
    //Do while Loop
    cout<<"Using do-while loop"<<endl;
    int j = 0;
    do{
        cout<<"Marks is "<<marks[j]<<endl;
        j++;
    } while(j<4);
    
    return 0;
}