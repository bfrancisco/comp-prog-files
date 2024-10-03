#include<bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;

    Point(){}
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    bool operator==(Point& other){
        return (x == other.x && y == other.y);
    }

    void operator=(Point& other){
        x = other.x;
        y = other.y;
    }

    double get_distance(Point& other){
        return sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y));
    }

    void print(){
        cout << "(" << x << ", " << y << ")";
    }
};

struct Line{
    Point A;
    Point B;

    Line(){}
    Line(Point A, Point B){
        this->A = A;
        this->B = B;
    }
    
    Point get_intersection_point(Line& other){
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
        A.print(); cout << " to "; B.print(); cout << endl;
    }
};

bool in(Point pnt, vector<Point>& v){
    for (auto p : v){
        if (p == pnt) return true;
    }
    return false;
}

int main(){
    Point a(1, 2), b(1, 2);
    if (a == b){
        cout << "YeAH" << endl;
        Point c(100, 100);
        a = c;
        a.print(); cout << endl;
    }

    map<Point, int> x;
    x[a] = 1;
    
    return 0;
}