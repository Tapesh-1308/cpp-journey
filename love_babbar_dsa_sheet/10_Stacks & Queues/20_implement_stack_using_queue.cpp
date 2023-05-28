#include <bits/stdc++.h>
using namespace std;

/**
 * Stack Using 2 Queue
 * Push - O(N), Pop - O(1), Top - (1)
*/
class Stack {
	// Two inbuilt queues
	queue<int> q1, q2;

public:
	void push(int x) {
		// Push x first in empty q2
		q2.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{
		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size() { return q1.size(); }
};

/**
 * Stack Using Two Queue
 * Push - O(1), Pop - O(N), Top - O(N)
*/
class Stack {
    queue<int> q1, q2;
 
public:
    void pop()
    {
        if (q1.empty())
            return;
 
        // Leave one element in q1 and
        // push others in q2.
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
 
        // Pop the only left element
        // from q1
        q1.pop();
 
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
 
    void push(int x) { q1.push(x); }
 
    int top()
    {
        if (q1.empty())
            return -1;
 
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
 
        // last pushed element
        int temp = q1.front();
 
        // to empty the auxiliary queue after
        // last operation
        q1.pop();
 
        // push last element to q2
        q2.push(temp);
 
        // swap the two queues names
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }
 
    int size() { return q1.size(); }
};

/**
 * Stack using one queue
 * Push - O(N) Pop - (1) Top - O(1)
*/
class Stack {
    queue<int> q;
public:
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
};
 
// Push operation
void Stack::push(int data)
{
    //  Get previous size of queue
    int s = q.size();
 
    // Push the current element
    q.push(data);
 
    // Pop all the previous elements and put them after
    // current element
 
    for (int i = 0; i < s; i++) {
        // Add the front element again
        q.push(q.front());
 
        // Delete front element
        q.pop();
    }
}
 
// Removes the top element
void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}
 
// Returns top of stack
int Stack::top() { return (q.empty()) ? -1 : q.front(); }
 
// Returns true if Stack is empty else false
bool Stack::empty() { return (q.empty()); }
 
int Stack::size() { return q.size(); }

// Driver code   
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << "current size: " << s.size() << endl;
	return 0;
}
