#include <iostream>
using namespace std;

int main()
{
    // char arr[100] = "Apple";

    //Printing Char Array
    // int i = 0;
    // while(arr[i] != '\0'){
    //     cout<<arr[i]<<endl;
    //     i++;
    // }

    // Taking Input / Output
    // char arr1[100];
    // cin >> arr1;
    // cout << arr1 <<endl;
    // cout << arr1[4] << endl;
    // cout << arr1[101] << endl;

    //Check Palindrome - NITIN <--> NITIN
    /* int n;
    cin>>n;

    char arr[n+1];
    cin>>arr;

    bool check = 1;

    for (int i = 0; i < n/2; i++)
    {
        if(arr[i] != arr[n-i-1]){
            check = 0;
        }
    }
    if(check == true){
        cout<<"No, It is not a Palindrome\n";
    }
    else{
        cout<<"Yes, It is a Palindrome\n";
    } */

    //Finding Largest Word in Sentence

    int n;
    cin >> n;
    cin.ignore();

    char arr[n + 1];
    cin.getline(arr, n);
    cin.ignore();

    int i = 0;
    int currLength = 0, maxLength = 0, st=0, mxst=0;

    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLength > maxLength)
            {
                maxLength = currLength;
                mxst = st;
            }
            currLength = 0;
            st = i+1;
        }
        else
        {
            currLength++;
        }

        if (arr[i] == '\0')
            break;
        i++;
    }

    cout << maxLength << endl;
    for (int i = 0; i < maxLength; i++)
    {
        cout<<arr[i+mxst];
    }
    

    return 0;
}