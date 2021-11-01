#include <iostream>
using namespace std;

int main()
{
    // Rectangle Pattern
    //Output
    // *  *  *  *  *  *
    // *  *  *  *  *  *
    // *  *  *  *  *  *
    // *  *  *  *  *  *
    // *  *  *  *  *  *

    /* int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<" * ";
        }
        cout<<endl;
        
    } */

    // Hollow Rectangle Pattern
    //Output
    // ******
    // *    *
    // *    *
    // *    *
    // ******

    /* int row, col;
    cin >> row >> col;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (i == 1 || i == row || j == 1 || j == col)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    } */

    //Inverted Half Pyramid
    //Output
    // *  *  *  *  *
    // *  *  *  *
    // *  *  *
    // *  *
    // *

    /* int n;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }*/

    //Half pyramid after 180deg rotation
    //output        *
    //            * *
    //          * * *
    //        * * * *
    //      * * * * *

    /* int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(j<=n-i){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    } */

    //Half pyramid using numbers
    //Output
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5

    /* int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    } */

    //Floy's Triangle
    //Output
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15

    /*int n;
    cin >> n;
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            count++;
            cout<<count<<" ";
        }
        cout<<endl;
    } */

    // ButterFly Pattern
    //Output
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *

    /* int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        int space = 2 * n - 2 * i;

        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        int space = 2 * n - 2 * i;

        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    } */

    // Inverted Pyramid
    //Output
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1

    /* int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n+1-i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    } */

    // 0-1 Pattern
    //Output
    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    // 1 0 1 0 1

    /* int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if((i+j)%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
    cout<<endl;
        
    } */

    //Rhombus Pattern
    //Output
    //         * * * * *
    //       * * * * *
    //     * * * * *
    //   * * * * *
    // * * * * *

    /* int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<"  ";
        }
        for (int j = 1; j <= n; j++)
        {
            cout<<"* ";
        }
        cout<<endl;        
    } */

    // Number Triangle Pattern
    //Output
    //       1
    //      1 2
    //     1 2 3
    //    1 2 3 4
    //   1 2 3 4 5

    /* int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
        
    } */

    // Palindromic Pattern
    //Output
    //         1
    //       2 1 2
    //     3 2 1 2 3
    //   4 3 2 1 2 3 4
    // 5 4 3 2 1 2 3 4 5

    /* int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int j;
        for (j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        int k = i;
        for (; j <= n; j++)
        {
            cout << k-- << " ";
        }
        k = 2;
        for (; j <= n + i - 1; j++)
        {
            cout << k++ << " ";
        }
        cout << endl;
    } */

    //Star Pattern
    //Output
    //         *
    //       * * *
    //     * * * * *
    //   * * * * * * *
    // * * * * * * * * *
    // * * * * * * * * *
    //   * * * * * * *
    //     * * * * *
    //       * * *
    //         *

    /* int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<"  ";
        }
        for (int j = 1; j <= 2*i-1; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<"  ";
        }
        for (int j = 1; j <= 2*i-1; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    } */

    //Zig-Zag pattern
    //Output
    //     *       *
    //   *   *   *   *
    // *       *       *

    /* int n;
    cin >> n;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    } */

    //Hollow Diamond Pattern
    //Output
    //     *
    //    * *
    //   *   *
    //  *     *
    // *       *
    // *       *
    //  *     *
    //   *   *
    //    * *
    //     *

    /* int n;
    cin >> n;

    int space = (2 * n - 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j == 1 || j == 2 * i - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        space--;
    }
    space = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j == 1 || j == 2 * i - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        space++;
    } */

    // Hollow Diamond Inscribed in a Rectangle
    //output
    // *********
    // **** ****
    // ***   ***
    // **     **
    // *       *
    // *       *
    // **     **
    // ***   ***
    // **** ****
    // *********

    /* int n;
    cin>>n;

    int space = (2*n-1)/2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            cout<<"*";
        }
        for (int j = 1; j <= 2*i-1; j++)
        {
            if(j==1 || j == 2*i-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for (int j = 1; j <= space; j++)
        {
            cout<<"*";
        }
        
        cout<<endl;
        space--;
        
    }
    space = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= space; j++)
        {
            cout<<"*";
        }
        for (int j = 1; j <= 2*i-1; j++)
        {
            if(j==1 || j == 2*i-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for (int j = 1; j <= space; j++)
        {
            cout<<"*";
        }
        
        cout<<endl;
        space++;
        
    } */

    //Hollow Rhombus
    //Output
    //         * * * * *
    //       *       *
    //     *       *
    //   *       *
    // * * * * *

    /* int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n)
            {
                cout << "* ";
            }
            else
            {
                if (j == 1 || j == n)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    } */

    //Hollow ButterFly Pattern  
    //Output
    // *        *
    // **      **
    // * *    * *
    // *  *  *  *
    // *   **   *
    // *   **   *
    // *  *  *  *
    // * *    * *
    // **      **
    // *        *

    /* int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if(j==1 || j==i){
                cout << "*";
            }
            else{
                cout<< " ";
            }
        }
        int space = 2 * n - 2 * i;

        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            if(j == 1 || j == i){
                cout << "*";
            }
            else{
                cout<<" ";
            }
        }
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if(j==1 || j==i){
                cout << "*";
            }
            else{
                cout<< " ";
            }
        }
        int space = 2 * n - 2 * i;

        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            if(j == 1 || j == i){
                cout << "*";
            }
            else{
                cout<<" ";
            }
        }
        cout << endl;
    } */   

    return 0;
}