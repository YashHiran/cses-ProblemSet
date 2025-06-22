#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
/*
    Other problems for Geometry topic are submitted on cses. 
*/
class Point {
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

/*
    slope of p1, p2 = (p2.x - p1.x) / (p2.y - p1.y)
    slope if p2, p3 = (p3.x - p2.x) / (p3.y - p2.y)
    
    1st slope > 2nd slope then clockwise
    1st - 2nd > 0 clockwise

    Now, as denominator sign gets cancelled, we just multiply and check signs of numerator.
*/

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if(val == 0) return val; // co-linear
    if(val > 0) return 1; // clockwise means to right
    return 2; // anti-clockwise means to left.
}

int main() {
    #ifndef ONLINE_JUDGEs
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  #endif

     int t; cin >> t;
     while(t--) {
        /*
            1
            1 4
            2 5
            3 6 -> co-linear
        */
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point p1 = Point(x1, y1);
        Point p2 = Point(x2, y2);
        Point p3 = Point(x3, y3);

        cout << orientation(p1, p2, p3);

     } 
}