#include<bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;

    Point(){}
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    double get_distance(Point& other){
        return sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y));
    }

    string print(){
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

struct Line{
    double x1, x2, y1, y2;
    Point A;
    Point B;

    Line(){}
    Line(Point A, Point B){
        this->A = A;
        this->B = B;
    }
    
    Point get_intersecting_point(Line& other){
        double a1, b1, c1, a2, b2, c2;
        a1 = B.y - A.y;
        b1 = A.x - B.x;
        c1 = a1*(A.x) + b1*(A.y);
    
        a2 = other.B.y - other.A.y;
        b2 = other.A.x - other.B.x;
        c2 = a2*(other.A.x) + b2*(other.A.y);

        double determinant = a1*b2 - a2*b1;

        if (determinant == 0) return {DBL_MAX, DBL_MAX};
        double cx, cy;
        cx = (b2*c1 - b1*c2)/determinant;
        cy = (a1*c2 - a2*c1)/determinant;
        return Point(cx, cy);
    }
    
    void print(){
        cout << A.print() << " to " << B.print() << endl;
    }
};

int main(){
    int n;
    cin >> n;

    vector<Line> lines;
    for (int i = 0; i < n; i++){
        double a,b,c,d;
        cin >> a >> b >> c >> d;
        lines.push_back(Line(Point(a, b), Point(c, d)));
    }


    // for (auto line : lines) line.print();

    double sx, sy, sv;
    cin >> sx >> sy >> sv;
    double fsx, fsy, fex, fey, fv;
    cin >> fsx >> fsy >> fex >> fey >> fv;

    // n paths, f path, s
    vector<vector<Point>> adj(n+3);
    
    return 0;
}