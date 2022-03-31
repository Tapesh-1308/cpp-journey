//Dry Run
/* Consider k = 4, n = 9 
Given array: 3 1 2 2 2 1 4 3 3 

i = 0
         3 _ _
temp[] has one element, 3 with count 1

i = 1
         3 1 _
temp[] has two elements, 3 and 1 with 
counts 1 and 1 respectively

i = 2
         3 1 2
temp[] has three elements, 3, 1 and 2 with
counts as 1, 1 and 1 respectively.

i = 3
         - - 2 
         3 1 2
temp[] has three elements, 3, 1 and 2 with
counts as 1, 1 and 2 respectively.

i = 4
         - - 2 
         - - 2 
         3 1 2
temp[] has three elements, 3, 1 and 2 with
counts as 1, 1 and 3 respectively.

i = 5
         - - 2 
         - 1 2 
         3 1 2
temp[] has three elements, 3, 1 and 2 with
counts as 1, 2 and 3 respectively.

i = 6
         - - 2 
         - 1 2 
temp[] has two elements, 1 and 2 with
counts as 1 and 2 respectively.

i = 7
           - 2 
         3 1 2 
temp[] has three elements, 3, 1 and 2 with
counts as 1, 1 and 2 respectively.

i = 8          
         3 - 2
         3 1 2 
temp[] has three elements, 3, 1 and 2 with
counts as 2, 1 and 2 respectively. */

#include<bits/stdc++.h>
using namespace std;

// A structure to store an element and its current count
struct eleCount {
    int e; // Element
    int c; // Count
};

void morethanNbyK(int arr[], int n, int k) {
    //Method 1 Using Hashing TC O(N) SC O(N)
	/* int x = n / k;
	
	// unordered_map initialization
	unordered_map<int, int> freq;

	for(int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}

	// Traversing the map
	for(auto i : freq)
	{
		
		// Checking if value of a key-value pair is greater than x (where x=n/k)
		if (i.second > x) {
			// Print the key of whose value is greater than x
			cout << i.first << endl;
		}
	} */

    //Method 2 TC O(nk) SC O(k)
    // k must be greater than 1 to get some output
    if (k < 2)
        return;
 
    /*Step 1: Create a temporary array (contains element and
     count) of size k-1. Initialize count of all elements as 0*/
    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].c = 0;
 
    /* Step 2: Process all elements of input array */
    for (int i = 0; i < n; i++) {
        int j;
 
        /* If arr[i] is already present in the element count array, then increment its count */
        for (j = 0; j < k - 1; j++) {
            if (temp[j].e == arr[i]) {
                temp[j].c += 1;
                break;
            }
        }
 
        /* If arr[i] is not present in temp[] */
        if (j == k - 1) {
            int l;
 
            /* If there is position available in temp[], then place arr[i] in
              the first available position and set count as 1*/
            for (l = 0; l < k - 1; l++) {
                if (temp[l].c == 0) {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }
 
            /* If all the position in the temp[] are filled, 
               then decrease count of every element by 1 */
            if (l == k - 1)
                for (l = 0; l < k-1; l++)
                    temp[l].c -= 1;
        }
    }
 
    /*Step 3: Check actual counts of * potential candidates in temp[]*/
    for (int i = 0; i < k - 1; i++)
    {
        // Calculate actual count of elements
        int ac = 0; // actual count
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;
 
        // If actual count is more than n/k, then print it
        if (ac > n / k)
            cout << "Number:" << temp[i].e << " Count:" << ac << endl;
    }

}
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	
	morethanNbyK(arr, n, k);

	return 0;
}