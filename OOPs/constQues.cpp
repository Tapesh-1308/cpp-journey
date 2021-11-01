#include<iostream>
#include<math.h>
using namespace std;

class Point{
    int x, y;
    friend class CalcDist;
    public:
    Point(int, int);

};

Point::Point(int a, int b){
    x = a;
    y = b;
}

class CalcDist{
    public:
    CalcDist(Point p, Point q){
        int sum = sqrt(((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y)));
        cout<<sum<<endl;
    }

};


int main() {
    Point p(1, 1);
    Point q(1, 1);
    CalcDist c(p, q);
    return 0;
}