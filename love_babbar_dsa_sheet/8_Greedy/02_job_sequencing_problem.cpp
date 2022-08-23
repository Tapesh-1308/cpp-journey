// Find the maximum profit job sequence from a given array of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// Approach - Using Greedy Technique - TC O(NlogN + N*M), n is number of jobs, m is maximum deadline, SC O(M)

// A structure to represent a job
struct Job {
	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
};

// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns minimum number of platforms required
void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of profit
	sort(arr, arr + n, comparison);

    // maxi stores the maximum deadline
    int maxi = arr[0].dead;
    for(int i=1; i<n; i++) 
        maxi  = max(maxi, arr[i].dead);
    
    // create a slot array to know which slot is empty, -1 denotes empty slots
    vector<int> slot(maxi+1, -1); // using size maxi+1 instead of maxi for (1 index array)
    
    // initialize profit and job count -> number of jobs taken
    int jobCount = 0;
    int profit = 0;
    
    // traverse Job arr[]
    for(int i=0; i<n; i++) {
        // find empty slot suitable for curr job
        for(int j=arr[i].dead; j>0; j--) {
            // if any slot is empty
            if(slot[j] == -1){
                // fill that slot and include it into profit, increment job count
                slot[j] = arr[i].id;
                jobCount++;
                profit += arr[i].profit;
                break;
            }
        }
    }

	// Print the result
    cout << "Job Count: " << jobCount << " Total Profit: " << profit << endl;
	cout << "Following is maximum profit sequence of jobs \n";
	for (int i = 0; i < n; i++) {
        cout << slot[i] << " ";
    }
		
}

// Driver code
int main()
{
	Job arr[] = { { 1, 2, 100 },
				{ 2, 1, 19 },
				{ 3, 2, 27 },
				{ 4, 1, 25 },
				{ 5, 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printJobScheduling(arr, n);
	return 0;
}

