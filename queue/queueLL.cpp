#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class queue{
    node* front;
    node* back;

    public: 
    queue(){
        front=NULL;
        back=NULL;
    }

    void push(int val){
        node* n=new node(val);
        if(front==NULL){
            back=n;
            front = n;
            return;
        }

        back->next = n;
        back=n;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return;
        }   
        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return -1;
        } 
        return front->data;
    }

    bool empty(){
        if(front==NULL)
            return true;
         
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
    qu.pop();

    cout<<qu.peek()<<endl;
    qu.pop();

    cout<<qu.peek()<<endl;
    qu.pop();
    
    cout<<qu.empty()<<endl;
    return 0;
}