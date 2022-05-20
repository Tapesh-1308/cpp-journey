#include<bits/stdc++.h>
using namespace std;

// Time Complexity - O(nlogn) SC O(1)

// Stores two paritioning points
struct Partition {
    int left, right;
    Partition(int a, int b){
        left = a;
        right = b;
    }
};

int compare(int num1, int num2){
    if(num1 > num2) // if curr is greater than value
        return 1;
    if(num1 == num2) // if equal
        return 0;
    else return -1; // if value is smaller than value
}

// make partition using the idea of DNF Algo
Partition makePartition(int arr[], int st, int end) {
    // >>>> ==== <<<<, smaller element on left side equal in middle and greater in right

    // lessthan points to a element such that all elements befor it will be smaller than curr, started with st
    // greatThan point to a element such that all elements after it will be greater than curr, initiall points to end
    int lessThan = st, curr = st, greatThan = end; // curr end of equals, start with st
    int value = arr[st]; // Value which goes to its correct position

    // While we didn't traverse element, curr reach greaterThan
    while(curr <= greatThan) {
        // It checks whether curr element is smaller equal or greater than value
        int compareCurr = compare(arr[curr], value);
        switch (compareCurr) {
            case -1: // if curr is smaller than value
                swap(arr[curr++],arr[lessThan++]); // Swap curr with lessThan and increment both 
                break;
            case 0: // value is equal to curr 
                curr++; // increment curr only
                break;
            case 1: // curr is greater than value
                swap(arr[curr], arr[greatThan--]); // swap curr with greatThan and decrement greatThan only
                break;
        }
    }

    // LessThan and greatThan will be our partition points 
    Partition ans(lessThan, greatThan);
    return ans;
}

// Recusive function of 3 way Partitioning
void threeWayQuickSort(int arr[], int st, int end){
    if(end <= st) return; // Base case

    // Making partition such that all element less than curr value is on left side and greater is on right side and equals are in middle
    Partition midPart = makePartition(arr, st, end); 

    threeWayQuickSort(arr, st, midPart.left - 1); // left part
    threeWayQuickSort(arr, midPart.right + 1, end); // right part
}


int main() {
    int arr[] = {9, 8, 5, 32, 54, 9, 5, 5, 32, 33, 8, 1, 1, 1};
    int n = sizeof(arr)/sizeof(int);

    cout << "Before Sorting: \n";

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    threeWayQuickSort(arr, 0, n-1);

    cout << "After Sorting: \n";

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}