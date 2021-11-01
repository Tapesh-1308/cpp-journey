#include<iostream>
using namespace std;

#define n 20

class queue{
    int *arr;
    int front;
    int back;

public: 
    queue(){
        arr = new int[n];
        front=-1;
        back=-1;
    }

    void push(int x){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back] = x;

        if(front==-1)
            front++;
    }

    void pop(){
        if(front==-1 or front>back){
            cout<<"Empty Queue"<<endl;
            return;
        }
        front++;   
    }

    int peek(){
        if(front==-1 or front>back){
            cout<<"Empty Queue"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front==-1 or front>back){
            return true;
        }
        return false;
    }
};

int main() {
    queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    cout<<qu.peek()<<endl;
    qu.pop();
    cout<<qu.peek()<<endl;
    cout<<qu.empty()<<endl;
    return 0;
}