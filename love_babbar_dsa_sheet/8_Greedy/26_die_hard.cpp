// DIEHARD - SPOJ
#include<bits/stdc++.h>
using namespace std;

// Time complexity -> 
// Space Complexity -> (1)

int main(){
    // t - number of testcases
    int t; cin>>t;
    while(t--) {
        // h - health, a - armour
        int h, a;
        cin>>h>>a;

        // time we can survive - answer
        long long int time = 0;

        // run till survival is possible
        while(1) {
            // if time is even choose air, because we are alternatively jumping in air
            if(time%2 == 0) {
                // in air health increased by 3 
                h+=3;
                // and armour increased by 2
                a+=2;
            }

            // if you can't choose air
            else {
                // choose water if by choosing water you are not going to die
                if(a>10) {
                    // in water health decreased by 5
                    h-=5;
                    // and armour decreased by 10
                    a-=10;
                }
                // choose fire if you can't choose water also
                else {
                    // in fire health decreased by 20
                    h-=20;
                    // and armour increased by 5
                    a+=5;
                }
            }

            // if you have both health and armour greater than 0 then you can survive more, increase time 
            if(a>0 && h>0) time++;

            // if either of ur health or armour becomes 0  or less than 0 break, u r dead
            else break;
        } 

        // print the maximum time u survived
        cout << time << endl;

    }

    return 0;
}