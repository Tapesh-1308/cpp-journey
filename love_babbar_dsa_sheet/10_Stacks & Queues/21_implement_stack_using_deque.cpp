#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
	// Create an empty deque
	deque<int> my_deque;

public:
	void push(int item)
	{
		// Append the item to the end of the deque
		my_deque.push_back(item);
	}

	int pop()
	{
		// Remove and return the item from the end of the
		// deque
		int item = my_deque.back();
		my_deque.pop_back();
		return item;
	}

	int size()
	{
		// Return size of deque
		return my_deque.size();
	}

	bool is_empty()
	{
		// Return True if the deque is empty, and False
		// otherwise
		return my_deque.empty();
	}

	int top()
	{
		if (is_empty()) {
			// If the stack is empty, return -1
			return -1;
		}
		else {
			// Return the last item in the deque
			return my_deque.back();
		}
	}
};

int main()
{
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << "current size: " << st.size() << endl;
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	cout << "current size: " << st.size() << endl;
	return 0;
}
