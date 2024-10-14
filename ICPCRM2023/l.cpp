#include<bits/stdc++.h>
using namespace std;

const double epsi = 0.00000001;

struct Point{
    double x, y;
    pair<double, double> pr;

    Point(){}
    Point(double x, double y){
        this->x = x;
        this->y = y;
        this->pr = {x, y};
    }
 
    bool operator==(const Point& other){
        return (fabs(x-other.x) < epsi && fabs(y-other.y) < epsi);
    }
 
    void operator=(Point other){
        this->x = other.x;
        this->y = other.y;
    }
 
    bool operator<(const Point& other) const {
        // return (pr < other.pr);
        return (fabs(x-other.x) > epsi ? x < other.x : y < other.y);
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
 
    bool operator==(const Line& other){
        return ((A == other.A && B == other.B) || 
                (B == other.A && A == other.B));
    }
 
    bool operator<(const Line& other) const {
        if (fabs(A.x - other.A.x) > epsi){
            return (A.x < other.A.x);    
        }

        return (A.y < other.A.y);
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
 
        if (fabs(determinant) < epsi) return {DBL_MAX, DBL_MAX};
        double cx, cy;
        cx = (b2*c1 - b1*c2)/determinant;
        cy = (a1*c2 - a2*c1)/determinant;
 
        // if (!(min(A.x, B.x) <= cx && cx <= max(A.x, B.x) && 
        //     min(A.y, B.y) <= cy && cy <= max(A.y, B.y) &&
        //     min(other.A.x, other.B.x) <= cx && cx <= max(other.A.x, other.B.x) && 
        //     min(other.A.y, other.B.y) <= cy && cy <= max(other.A.y, other.B.y))){
        //         return {DBL_MAX, DBL_MAX};
        //     }
 
        return Point(cx, cy);
    }
 
    bool on_line(Point pnt){
        return (fabs(A.get_distance(B) - (pnt.get_distance(A) + pnt.get_distance(B))) < epsi);
    }
    
    void print(){
        A.print(); cout << " to "; B.print(); cout << endl;
    }
};

int main(){
    int n; cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++){
        double x, y; cin >> x >> y;
        points.push_back(Point(x, y));
    }

    vector<Line> lines;
    for (int i = 0; i < n-1; i++){
        lines.push_back(Line(points[i], points[i+1]));
    }
    lines.push_back(Line(points[0], points[n-1]));

    double sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    Line ant(Point(sx, sy), Point(ex, ey));

    // for (int i = 0; i < n; i++){
    //     // lines[i].print();
    //     // points[i].print(); cout << endl;
    // }
    // ant.print();

    int intersect = 0;
    bool par = false;

    for (int i = 0; i < n; i++){
        Point inter = lines[i].get_intersection_point(ant);
        inter.print(); cout << endl;
    } 

    // if (par){cout << "?" << endl; return 0;}
    // cout << (intersect == 1 ? "inside" : "outside") << endl;

    return 0;
}