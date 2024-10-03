#include<bits/stdc++.h>
using namespace std;

// from (fsx, fsy), check intersections from paths. Let's call all intersections from F "critical" 
// sort by distance, then connect adj points. last point is (fex, fey)

// from (sx, sy), check which line is it located. connect (sx, sy) to the endpoints of first line
// check for intersecting lines. create node for intersecting point. connect to endpoints and repeat
// repeat until all paths are exhausted

// Do dijkstra from F and S, separately
// if F[critical_i] == F[critical_i], it is gud. output nearest

struct Point{
    double x, y;

    Point(){}
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point& other){
        return (x == other.x && y == other.y);
    }

    void operator=(Point other){
        this->x = other.x;
        this->y = other.y;
    }

    bool operator<(const Point& other) const {
        return (x != other.x ? x < other.x : y < other.y);
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
        return ((A == other.A && B == other.B) || (B == other.A && A == other.B));
    }

    bool operator<(const Line& other) const {
        // not complete; only implemented to store in a set
        return (A.x < other.A.x);
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

        if (!(min(A.x, B.x) <= cx && cx <= max(A.x, B.x) && 
            min(A.y, B.y) <= cy && cy <= max(A.y, B.y) &&
            min(other.A.x, other.B.x) <= cx && cx <= max(other.A.x, other.B.x) && 
            min(other.A.y, other.B.y) <= cy && cy <= max(other.A.y, other.B.y))){
                return {DBL_MAX, DBL_MAX};
            }

        return Point(cx, cy);
    }

    bool on_line(Point pnt){
        return (fabs(A.get_distance(B) - (pnt.get_distance(A) + pnt.get_distance(B))) < 0.00001);
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

void print_adj(map<Point, set<Point>>& adj){
    for (auto& [point, v] : adj){
        cout << "From: ";
        cout << "(" << point.x << " " << point.y << ")" << endl;

        for (auto p : v){
            cout << "\t";
            cout << "(" << p.x << " " << p.y << ")" << endl;
        }
    }
}

void update_adj(Point pnt, Line line, map<Point, set<Point>>& adj){
    if (!(pnt == line.A)){
        adj[pnt].insert(line.A);
        adj[line.A].insert(pnt);
    }
    if (!(pnt == line.B)){
        adj[pnt].insert(line.B);
        adj[line.B].insert(pnt);
    }
}

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
    // cout << lines[0].A.get_distance(lines[0].B) << endl;

    double sx, sy, sv;
    cin >> sx >> sy >> sv;
    double fsx, fsy, fex, fey, fv;
    cin >> fsx >> fsy >> fex >> fey >> fv;
    Point S(sx, sy), F_start(fsx, fsy), F_end(fex, fey);
    Line F(F_start, F_end);

    // Build F path. intersection points of F
    vector<Point> f_path = {F_start, F_end};
    for (auto line : lines){
        Point inter_pnt = F.get_intersection_point(line);
        if (inter_pnt.x == DBL_MAX) continue;
        f_path.push_back(inter_pnt);
    }

    sort(f_path.begin(), f_path.end());    
    if (!(f_path[0] == F_start)) reverse(f_path.begin(), f_path.end()); 

    // for (auto pnt : f_path) {pnt.print(); cout << endl;}

    map<Point, set<Point>> adj;
    for (int i = 0; i < f_path.size()-1; i++){
        adj[f_path[i]].insert(f_path[i+1]);
        adj[f_path[i+1]].insert(f_path[i]);
    }

    print_adj(adj); cout << "-------------" << endl;

    // build graph for S
    queue<pair<Line, Point>> q; // line, intersection point
    set<Line> done;

    for (auto line : lines){
        if (line.on_line(S)){
            update_adj(S, line, adj);
        }
    }

    for (int i = 0; i < lines.size(); i++){
        for (int j = i+1; j < lines.size(); j++){
            Line& line1 = lines[i];
            Line& line2 = lines[j];
            Point inter = line1.get_intersection_point(line2);
            if (inter.x == DBL_MAX) continue;

            update_adj(inter, line1, adj);
            update_adj(inter, line2, adj);
        }
    }


    cout << endl; print_adj(adj);

    
    
    return 0;
}