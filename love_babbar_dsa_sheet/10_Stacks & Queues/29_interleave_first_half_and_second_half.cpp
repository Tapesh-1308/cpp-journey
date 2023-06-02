// C++ program to interleave the first half of the queue
// with the second half using queue
#include <bits/stdc++.h>
using namespace std;

// Function to interleave the queue
void interLeaveQueue(queue<int>& q)
{
	// To check the even number of elements
	if (q.size() % 2 != 0)
		cout << "Input even number of integers." << endl;

	// Initialize an empty queue of int type
	queue<int> temp;
	int halfSize = q.size() / 2;

	// Push first half elements into the stack
	// queue:16 17 18 19 20, queue: 11 12 13 14 15
	for (int i = 0; i < halfSize; i++) {
		temp.push(q.front());
		q.pop();
	}

	// enqueue back the queue elements alternatively
	// queue: 11 16 12 17 13 18 14 19 15 20
	while (!temp.empty()) {
		q.push(temp.front());
		q.push(q.front());
		q.pop();
		temp.pop();
	}
}

// Driver program to test above function
int main()
{
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.push(16);
	q.push(17);
	q.push(18);
	q.push(19);
	q.push(20);
	interLeaveQueue(q);
	int length = q.size();
	for (int i = 0; i < length; i++) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
