// CPP program to reverse a Queue
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the queue
void Print(queue<int>& Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

// Approach - Iterative - TC O(N) SC O(N)
void reverseQueue(queue<int>& Queue)
{
	stack<int> Stack;
	while (!Queue.empty()) {
		Stack.push(Queue.front());
		Queue.pop();
	}
	while (!Stack.empty()) {
		Queue.push(Stack.top());
		Stack.pop();
	}
}

// Approach - Recusrive - TC O(N) SC O(N)
void reverseQueue(queue<int>& q)
{
    // base case
    if (q.size() == 0)
        return;
    // storing front(first element) of queue
    int fr = q.front();
 
    // removing front
    q.pop();
 
    // asking recursion to reverse the
    // leftover queue
    reverseQueue(q);
 
    // placing first element
    // at its correct position
    q.push(fr);
}

// Driver code
int main()
{
	queue<int> Queue;
	Queue.push(10);
	Queue.push(20);
	Queue.push(30);
	Queue.push(40);
	Queue.push(50);
	Queue.push(60);
	Queue.push(70);
	Queue.push(80);
	Queue.push(90);
	Queue.push(100);

	reverseQueue(Queue);
	Print(Queue);
}
