#include <bits/stdc++.h>
using namespace std;

#define INF 1e6
#define EPS 1e-6

// Method - Ternary Search - TC O(N * √N * log₃2(1e6)) SC O(1)

// To make line equation - ax + by + c = 0
struct line{
  int a, b, c;
  line(int aVal, int bVal, int cVal){
      a = aVal; // a is x coefficiant
      b = bVal; // b is y coefficient
      c = cVal; // c is constant
  }
};

// X is point to calculate distance 
double computeDist(vector<vector<int>> &points, line l, double X) {
    double res = 0; // it store total distance of all point to (X, Y)
    
    // We also need Y for distance formula, to calc Y use this formula
    // -> ax + by + c = 0 
    // -> by = - c - ax 
    // -> y =  - (c + ax) / b;
    
    double Y = -(l.c + (l.a * X)) / l.b;

    // Now find all point distance from (X, Y), and add it to res
    for(int i=0; i<points.size(); i++)
        // Distance formula
        res += sqrt(((X - points[i][0]) * (X - points[i][0])) + ((Y - points[i][1]) * (Y - points[i][1])));
        
    // Return total distance
    return res;
}

double optimumTotalDist(vector<vector<int>> &points, line l){
    // Start and ending position of Ternary Search     
    // INF denotes all possible distance
    // st and end is minimum and maximum point value on a line  
    double st = -INF, end = INF;    
    
    while((end - st) > EPS) {
        // Divide the line in 3 part by mid1 and mid2
        double mid1 = st + (end - st) / 3;
        double mid2 = end - (end - st) / 3;
        
        // Calculate distance of all points to mid1 and mid2
        double dist1 = computeDist(points, l, mid1);
        double dist2 = computeDist(points, l, mid2);
        
        //If mid1 distance is smaller then no need to search beyoud mid2 so end = mid2
        if(dist1 < dist2)
            end = mid2;

        //Else we can move start pos to mid1 tosearch in right side
        else
            st = mid1;
    }
    // Compute optimum distance by sending average of st and end as X
    return computeDist(points, l, (st+end)/2);
}


int main() {
    // x - y - 3 = 0
    line l(1, -1, -3);
    
    // Co-ordinates on 2d graph
    vector<vector<int>> points = { { -3, -2 }, { -1, 0 }, {-2, -6}, 
                                   { -1, 2  }, { 1, 3  }, { 3, 4 } };
                         
    cout << optimumTotalDist(points, l);
	return 0;
}