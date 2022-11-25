#include<bits/stdc++.h>
using namespace std;

// implementation using array (circular manner)
struct Queue{
    int capacity; // queue capacity
    int size; // number of elements in queue
    int front; // first element index
    int rear; // last element index
    int *arr; // array 

    // contructor
    Queue(int cap) {
        capacity = cap; 
        size = front = 0; // initialize size and front as 0
        rear = capacity - 1; // rear will be the last index
        arr = new int[capacity];
    }

    // function to insert element in the queue
    void enqueue(int x) {
        // if queue is full return 
        if(isFull()) {
            cout << "OverFlow" << endl;
            return;
        }

        // increment rear (for first element -> rear = capacity - 1, so ((capacity - 1) + 1) % capacity = 0)
        rear = (rear + 1) % capacity;
        arr[rear] = x; // add element in queue
        size++; // increment size
    }

    // function to remove element in the queue
    int dequeue() {
        // if queue is empty return -1 
        if(isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }

        int todel = arr[front]; // element to delete
        front = (front + 1) % capacity; // increment front
        size--; // decrement size
        return todel; // return the deleted item
    }

    // function to the first element in the queue
    int getFront(){
        // if queue is empty return -1
        if(isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }

        // else return front element
        return arr[front];
    }

    // function to get the last element in the queue
    int getRear(){
        // if queue is empty return -1
        if(isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }

        // return the rear element 
        return arr[rear];
    }

    // if size becomes equals to the capacity returns true
    bool isFull(){
        return capacity == size;
    }

    // if size is 0 queue is empty
    bool isEmpty(){
        return size == 0;
    }
};

// linked list node
struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

// implementation using linked list
struct QueueL { 
    // front node and rear node
	QNode *front, *rear; 
    int size; // size of queue

    // constructor 
	QueueL() { 
		front = rear = NULL; // initally both will be null
        size = 0; // with size 0
	} 

    // function to insert element into the queue
	void enqueue(int x) { 		 
		QNode* temp = new QNode(x); // create element node
		 
        // if rear is null -> first element
		if (!rear) { 
			front = rear = temp; // both front and rear will become temp
            size++; // increment size and return
			return; 
		} 

        // if not the first node
		rear->next = temp;  // add element node after rear
		rear = temp; // update rear
        size++; // increment size
	} 

	// function to remove element from the queue
	int dequeue() { 
        // if list is empty
		if (!front) 
			return -1; 

        // store front node in temp
		QNode* temp = front; 
		front = front->next; // move fornt forward
        size--; // decrement size

        // if front becomes nul (list becomes empty)
		if (!front) 
			rear = NULL; // make rear also null

        // store delete node data
        int del = temp->data;
		delete (temp); 

        // return delete data
        return del;
	} 

    // function to the front node 
    int getFront(){
        // if list is empty
        if(!front) 
            return -1;

        // else return front data
        return front->data;
    }

    // function to get the rear node
    int getRear(){
        //if list is empty
        if(!rear) 
            return -1;

        // else return the rear data
        return rear->data;
    }

    // function to get the size of queue
    int getSize(){
        return size; // return the size variable
    }

    // function to check if queue is empty or not
    int isEmpty(){
        return size == 0; // check if size is 0
    }
}; 


int main() {
    // Using Array
    Queue q(3); // [1,2,3]

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.isFull() << endl; // True

    cout << q.dequeue() << endl; // removed 1
    cout << q.getFront() << endl; // front = 2
    cout << q.getRear() << endl; // rear = 3

    cout << q.dequeue() << endl; // removed 2
    cout << q.getFront() << endl; // front = 3
    cout << q.getRear() << endl; // rear = 3

    cout << q.dequeue() << endl; // removed 3
    cout << q.isEmpty() << endl; // True

    // Using linked list
    QueueL ql; // [1,2,3]

    ql.enqueue(1);
    ql.enqueue(2);
    ql.enqueue(3);

    cout << ql.getSize() << endl; // size = 3
    cout << ql.dequeue() << endl; // removed 1
    cout << ql.getFront() << endl; // front = 2
    cout << ql.getRear() << endl; // rear = 3

    cout << ql.dequeue() << endl; // removed 2
    cout << ql.getFront() << endl; // front = 3
    cout << ql.getRear() << endl; // rear = 3

    cout << ql.dequeue() << endl; // removed 3
    cout << ql.isEmpty() << endl; // True

    return 0;
}