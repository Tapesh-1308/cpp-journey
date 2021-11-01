#include<iostream>
using namespace std;

int main() {
    // 2D Array   
    cout<<"Taking an 2D Array Input: \n";

    int n, m;
    cin>>n>>m;

    int arr[n][m];


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Printing an 2D Array: \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"Searching an 2D Array: \n";
    int x;
    cin>>x;

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == x){
                cout<<i<<" "<<j<<endl;
                flag = true;
            }
        }    
    }
    
    if(flag){
        cout<<"Element is Found\n";
    } else{
        cout<<"Element is not found\n";
    }

    return 0;
}