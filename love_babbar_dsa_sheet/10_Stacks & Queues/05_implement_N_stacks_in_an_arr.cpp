#include<bits/stdc++.h>
using namespace std;

// Implementation of K stacks in one array
struct Stack{
    int *arr; // array that store element
    int *top; // stores top element index of all stacks

    // helps to reach next empty space while pushing and helps to reach previous element index while popping
    int *next; // stores  -> if arr[index] empty - tells next empty space else tells previous top index

    int N; // size of stack
    int K; // number of stacks
    int freespot; // stores just next free spot

    Stack(int size, int stacks){
        N = size;
        K = stacks;
        freespot = 0; // initally 1st freespot is (0 index)

        arr = new int[N];
        top = new int[K];
        next = new int[N];

        memset(top, -1, K); // [-1,-1,-1,...]

        // next store next empty space index
        for(int i=0; i<N; i++) // [1,2,3,4,5,...,-1]
            next[i] = i+1;

        next[N-1] = -1; // last's next is not empty so -1
    }

    // function to push x in mth stack
    void push(int x, int m) {
        // if no freespot available, means stack is full
        if(freespot == -1){
            cout << "Stack is Full " << endl;
            return;
        }

        // find index where space is available to push 
        int index = freespot;

        // update freespot to neext empty area(denoted by next array)
        freespot = next[index];

        // add element to array
        arr[index] = x;

        // now element is pushed so next index store top
        next[index] = top[m-1];

        // then update top as index
        top[m-1] = index;

        cout << "Added: " << x << " in " << m << endl;
    }

    // function to pop element from the mth stack
    int pop(int m) {
        // if top is deonting to -1, means stack is empty
        if(top[m-1] == -1) {
            cout << "Stack is empty " << endl;
            return -1;
        }

        // find index on which mth stack top lies
        int index = top[m-1];

        // update that top to previous element pushed into the mth stack(denoted by next array)
        top[m-1] = next[index];

        // now element to removed so next array will denotes next free space
        next[index] = freespot;

        // after deleting element index becomes empty so update freespot 
        freespot = index;

        // return the deleted elment
        return arr[index];
    }
};

int main(){
    Stack s(10,5);

    cout << "Adding elements: " << endl;
    int j = 5;

    for(int i=1; i<=5; i++) {
        s.push(i,j);
        j--;
    }

    cout << "Removing elements" << endl;

    j = 1;
    for(int i=1; i<=5; i++) {
        cout << "Element removed: " << s.pop(j)  << " in " << j<< endl;
        j++;
    }
    return 0;
}
