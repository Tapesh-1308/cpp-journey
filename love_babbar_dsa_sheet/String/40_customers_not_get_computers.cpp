#include<bits/stdc++.h>
using namespace std;

// Method - TC - O(N) SC O(26)
int runCustomerSimulation(int n, string s) {
    int occupied = 0; // Number of computer occupied
    int visited[26] = {0}; //If anyone visits
    
    int count = 0; // Count for whom who did not get computer

    // Traverse on string
    for(char c:s) {
        // If we get a new element
        if(visited[c-'A'] == 0) {
            // Mark it as visited
            visited[c-'A']=1;

            // Check if we have computers left
            if(occupied < n){
                occupied++; // Mark it occupied
                visited[c-'A']=2; // It tell after departure we have decrement occupied
            }

            // If all are occupied
            else count++; // Incerement answer
        }
        // If we get this element before
        else {
            if(visited[c-'A'] == 2) // If person is leaving
                occupied--; // De-occupied

            visited[c-'A']=0; // This element is now free 
        }
    }
    
    // Return ans
    return count;
}

int main()
{
	cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABAB") << endl;

	return 0;
	
}