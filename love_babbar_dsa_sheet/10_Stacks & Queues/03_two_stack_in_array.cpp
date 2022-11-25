// implement two stacks in one array
#include<bits/stdc++.h>
using namespace std;

// Approach - 1 (giving half array to both stacks)
struct twoStacks {
    int size;
    int top1, top2;
    int *arr;

    // [0...|...size-1]
    //  <-s1|s2->

    twoStacks(int x) {
        size = x;
        top1 = size/2 + 1; // [0...size/2] -> stack1 (top1 one index after)
        top2 = size/2; // [size/2 + 1 ... size-1] -> stack2 (top2 one index before)
    }

    // to push in stack1
    void pushStack1(int x) {
        // if stack1 is full
        if(top1 == 0) 
            return;
        
        // decrement top1 and add element in array
        arr[--top1] = x;
    }

    // to push in stack2
    void pushStack2(int x) {
        // if stack2 is full
        if(top2 == size-1)
            return;

        // increment top2 and add element in array
        arr[++top2] = x;
    }

    // to remove from stack1
    void popStack1() {
        // if top1 is as initialized, empty stack1
        if(top1 == size/2 + 1)
            return;

        // increment top1
        top1++;
    }

    // to remove from stack2
    void popStack2() {
        // if top2 is as initalized, empty stack2
        if(top2 == size/2)
            return;

        // decrement top2
        top2--;
    }

};

// Approach - 2 (no size initally given)
struct twoStacks2 {
    int size;
    int top1, top2;
    int *arr;


    // [0....size-1]
    // s1->   <-s2
    twoStacks2(int x) {
        size = x;
        top1 = -1; // starts from starting
        top2 = size; // starts from last
    }

    // to push in stack1
    void pushStack1(int x) {
        // if array is filled completely
        if(top1 == top2-1) 
            return;
        
        // increment top1 and add element to stack1
        arr[top1++] = x;
    }

    // to push in stack2
    void pushStack2(int x) {
        // if array is filled completely
        if(top1 == top2-1)
            return;

        // decrement top2 and add element to stack2
        arr[--top2] = x;
    }

    // to remove from stack1
    void popStack1() {
        // if stack1 is empty
        if(top1 == -1)
            return;

        // else decrement top1
        top1--;
    }

    // to remove from stack2
    void popStack2() {
        // if stack2 is empty
        if(top2 == size)
            return;

        // increment top2
        top2++;
    }

};

int main(){
    // approach 1
    twoStacks ts(5);
    ts.pushStack1(10);
    ts.popStack1();

    ts.pushStack2(22);
    ts.popStack2();

    // approach 2
    twoStacks2 ts2(5);
    ts2.pushStack1(10);
    ts2.popStack1();

    ts2.pushStack2(22);
    ts2.popStack2();
    return 0;
}