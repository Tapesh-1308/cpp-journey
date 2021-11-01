#include <iostream>
using namespace std;

bool isSortedArray(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    return (arr[0] < arr[1] && isSortedArray(arr + 1, n - 1));
}

void decreasing(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    decreasing(n - 1);
}

//My method - LONG
void increasing1(int n)
{
    static int temp = 1;
    if (temp > n)
    {
        return;
    }
    cout << temp << " ";
    temp++;
    increasing1(n);
}

//Video Methjod - Simple / Short
void increasing(int n)
{
    if (n == 0)
    {
        return;
    }
    increasing(n - 1);
    cout << n << " ";
}

int firstOcc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
        return i;
    return firstOcc(arr, n, i + 1, key);
}

int lastOcc(int arr[], int n, int i, int key)
{
    if (i == n)
        return -1;

    int restArray = lastOcc(arr, n, i + 1, key);
    if (restArray != -1)
        return restArray;

    if (arr[i] == key)
        return i;

    return -1;
}

void reverseString(string s)
{
    if (s.length() == 0)
    {
        return;
    }

    string ros = s.substr(1);
    reverseString(ros);
    cout << s[0];
}

void replacePi(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << 3.14;
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

void towerOfHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}

string removeDup(string s)
{
    if (s.length() == 0)
        return "";

    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if (ch == ans[0])
        return ans;

    return ch + ans;
}

string moveX(string s)
{
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = moveX(s.substr(1));

    if (ch == 'x')
        return ans + ch;
    return ch + ans;
}

void subStrings(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);

    subStrings(ros, ans);
    subStrings(ros, ans + ch);
}

void subStringsASCII(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subStrings(ros, ans);
    subStrings(ros, ans + ch);
    subStrings(ros, ans + to_string(code));
}

string keyPadArr[]= {"", "", "abc", "def", "ghi"};

void keypad(string s, string ans){
    if(s.length() ==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string code = keyPadArr[ch-'0'];
    string ros = s.substr(1);

    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
    
}
int main()
{
    //Check whether the given array is sorted or not.
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // cout<<isSortedArray(arr, 6);

    //Print Numbers till : 1) Decreasing Order
    // int n;
    // cin>>n;
    // decreasing(n);
    // cout<<endl;
    // increasing1(n);
    // cout<<endl;
    // increasing(n);

    //Print the first and last occurance of an element in an array
    // int arr[] = {4, 2, 1, 2, 5, 2, 7};
    // cout<<firstOcc(arr, 7, 0, 2)<<" ";
    // cout<<lastOcc(arr, 7, 0, 2);

    //Reversing a string using recursion
    // string str = "binod";
    // reverseString(str);

    //Replace "3.14" with "pi"
    // replacePi("pipppppiippip");

    //Tower of hanoi
    // towerOfHanoi(3, 'A', 'C', 'B');

    //Remove duplicate Word from the string
    // cout<<removeDup("aaabbbbbeeeccccdddd");

    //Move All x in the last position
    // cout<<moveX("axxsdxxkexiexxx");

    //Find all substrings using recursion
    // subStrings("tap" , "");

    // Find all substrings using recursion with ASCII code
    // subStringsASCII("AB" , "");

keypad("23", "");

    return 0;
}