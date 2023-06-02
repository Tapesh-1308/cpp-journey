// C++ program to find circular tour for a truck
#include <bits/stdc++.h>
using namespace std;

// Approach - TC O(N) SC O(1)

// A petrol pump has petrol and distance to next petrol pump
class petrolPump {
public:
	int petrol;
	int distance;
};

// The function returns starting point if there is a
// possible solution, otherwise returns -1
int printTour(petrolPump p[], int n)
{
	// deficit is used to store the value of the capacity as
	// soon as the value of capacity becomes negative so as
	// not to traverse the array twice in order to get the
	// solution
	int start = 0, deficit = 0;
	int capacity = 0;
	for (int i = 0; i < n; i++) {
		capacity += p[i].petrol - p[i].distance;
		if (capacity < 0) {
			// If this particular step is not done then the
			// between steps would be redundant
			start = i + 1;
			deficit += capacity;
			capacity = 0;
		}
	}
	return (capacity + deficit >= 0) ? start : -1;
}
// Driver code
int main()
{
	petrolPump arr[] = { { 6, 4 }, { 3, 6 }, { 7, 3 } };

	int n = sizeof(arr) / sizeof(arr[0]);
	int start = printTour(arr, n);

	(start == -1) ? cout << "No solution"
				: cout << "Start = " << start;

	return 0;
}