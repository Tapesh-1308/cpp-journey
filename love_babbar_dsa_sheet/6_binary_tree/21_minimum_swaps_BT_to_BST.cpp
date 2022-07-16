/* C++ program to find minimum swaps required to convert binary ttree to BST */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* Utility function to get inorder from given array */
void arr_to_inorder(vector<int>&arr, vector<int>&inorder, int n, int index) {
    if(index >= n) return; // Base Case
    
    // Call for left child (2*i+1)
    arr_to_inorder(arr, inorder, n, 2*index+1);
    // process current element
    inorder.push_back(arr[index]);
    // Call for right child (2*i+2)
    arr_to_inorder(arr, inorder, n, 2*index+2);
}

// Approach - Same as minimum swaps to sort array - TC O(NlogN) SC O(1)
int minSwaps(vector<int>&arr, int n) {

    /* Find the inorder from the input array */
	vector<int> inorder; 
    arr_to_inorder(arr, inorder, n, 0);

    /* Create a temp array of pair {element, index} of inorder */
    vector<pair<int, int>> temp;
    for(int i=0; i<n; i++) 
        temp.push_back({inorder[i], i});
    
    /* Sort the temp array according to the first value of each pair. */
    sort(temp.begin(), temp.end());

    int ans = 0; // Stores minimum swaps
    
    /* Traverse on temp */
    for(int i=0; i<n; i++) {
        /* If element is on its correct position */
        if(i == temp[i].second) continue;

        else {
            /* Else, swap current element and index */
            swap(temp[i].first, temp[temp[i].second].first);
            swap(temp[i].second, temp[temp[i].second].second);
        }
        
        /* If even after the swaps, the second element is not equal to i, then we decrement i, i.e. do i = i - 1. */
        if(i != temp[i].second)
            i--;

        /* Increment the ‘ans’ by 1. */
        ans++;
    }
    
    return ans;
}

int main()
{
    // Given array, where i is root, and 2*i+1 is left child and 2*i+2 is right child
    vector<int> arr = { 5, 6, 7, 8, 9, 10, 11 };
    int n = arr.size();

    cout << minSwaps(arr, n) << endl;
}
