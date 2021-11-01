#include<iostream>
#include<list>
using namespace std;

void display(list<int> l){
    list<int> :: iterator iter;
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        cout<<*iter<<" ";
    } cout<<endl;
}

int main() {
    list<int> l;
    l.push_back(9);
    l.push_back(8);
    l.push_back(3);
    l.push_back(6);
    display(l);

    // l.pop_back();
    // display(l);
    // l.pop_front();
    // display(l);

    cout<<l.empty()<<endl;

    l.sort();
    display(l);

    list<int> l2;
    l2.push_back(9);
    l2.push_back(5);
    l2.push_back(3);
    l2.push_back(4);
    display(l2);
    
    l2.sort();
    display(l2);

    l.merge(l2);
    display(l);

    
    return 0;
}