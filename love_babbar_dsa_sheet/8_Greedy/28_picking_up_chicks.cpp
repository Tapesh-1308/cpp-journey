// GCJ101BB - Picking Up Chicks - SPOJ
#include<bits/stdc++.h>
using namespace std;

// Time Complexity - O(N)
// Space Complexity - O(1)

int main(){
    // T - testcases
    int t;
    cin>>t;

    // loop for all test cases
    for(int x=1; x<=t; x++) {
        // N - number of chicks
        // K - chicks needed to reach barn
        // B - barn location
        // T - time required in which K chick should reach barn 
        int N, K, B, T;
        cin>>N>>K>>B>>T;

        // X -> inital positions of chicks (time = 0)
        // V -> speed of chicks
        int X[N], V[N];

        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>V[i];

        // swap -> minimum swap required - ans
        // count -> tells how many chicks reached barn
        // cant_reach -> number of chicks that cant reach in barn in given time
        int swap=0, count=0, cant_reach=0;

        // reverse traversing
        for(int i=N-1; i>=0; i--) {
            // dist -> distance a chick needs to travel to reach barn
            int dist = B - X[i];
            // can_cover -> distance chick can cover in given time -> d = speed*time
            int can_cover = T*V[i];

            // if distance to travel is less than or equal the distance chick can travel
            //  chick easily can reach to barn
            if(dist <= can_cover){
                count++; // chick reached
                // if there are slower chicks before current chick
                if(cant_reach > 0) 
                    // increment swap by cant_reach, means you have to swap all slower chicks
                    swap += cant_reach;
            }

            // if distance to travel is more than chicks aukat
            else {  
                cant_reach++; // it can't reach
            }

            // if all required chick reached to barn break
            if(count >= K) break;
        }

        // if all required reached, print swap performed which is minimum
        if(count >= K) cout << "Case #" << x << ": "<< swap << endl;
        // if K chicks cant reached to barn, print impossible
        else  cout << "Case #" << x << ": IMPOSSIBLE" << endl;
    }

    return 0;
}