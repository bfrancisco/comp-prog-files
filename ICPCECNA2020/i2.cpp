#include<bits/stdc++.h>
using namespace std;

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

void dijkstra(Point start, map<Point, double>& time, double vel, map<Point, set<Point>>& adj){
    priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<pair<double, Point>>> q;
    q.push(make_pair(0, start));
    time[start] = 0;
    while (!q.empty()){
        auto [t, pnt] = q.top();
        q.pop();
        if (time[pnt] < t) continue;
        time[pnt] = t;
        for (auto p : adj[pnt]){
            if (time[p] > time[pnt] + pnt.get_distance(p)/vel){
                time[p] = time[pnt] + pnt.get_distance(p)/vel;
                q.push(make_pair(time[p], p));
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    const double PR = 10000;

    vector<Line> lines;
    for (int i = 0; i < n; i++){
        double a,b,c,d;
        cin >> a >> b >> c >> d;
        a*=PR;
        b*=PR;
        c*=PR;
        d*=PR;
        lines.push_back(Line(Point(a, b), Point(c, d)));
    }

    // for (auto line : lines) line.print();
    // cout << lines[0].A.get_distance(lines[0].B) << endl;

    double sx, sy, sv;
    cin >> sx >> sy >> sv;
    double fsx, fsy, fex, fey, fv;
    cin >> fsx >> fsy >> fex >> fey >> fv;
    sx *= PR;
    sy *= PR;
    fsx *= PR;
    fsy *= PR;
    fex *= PR;
    fey *= PR;
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

    // for (auto pnt : f_path) {pnt.print(); cout << endl;}

    map<Point, set<Point>> adj;
    for (int i = 0; i < f_path.size()-1; i++){
        adj[f_path[i]].insert(f_path[i+1]);
        adj[f_path[i+1]].insert(f_path[i]);
    }

    // build graph for S
    // line where S is on
    for (auto line : lines){
        if (line.on_line(S)){
            update_adj(S, line, adj);
        }
    }

    // pair all lines, create nodes for intersection
    for (int i = 0; i < lines.size(); i++){
        for (int j = i+1; j < lines.size(); j++){
            Line& line1 = lines[i];
            Line& line2 = lines[j];
            Point inter = line1.get_intersection_point(line2);
            Point l1f_inter = line1.get_intersection_point(F);  
            Point l2f_inter = line2.get_intersection_point(F);  
            if (inter.x != DBL_MAX){
                update_adj(inter, line1, adj);
                update_adj(inter, line2, adj);
            }
            if (l1f_inter.x != DBL_MAX){
                adj[inter].insert(l1f_inter);
            }
            if (l2f_inter.x != DBL_MAX){
                adj[inter].insert(l2f_inter);
            }
        }
    }

    int N = adj.size();
    map<Point, double> F_time, S_time;
    for (auto [pnt, v] : adj){
        F_time[pnt] = DBL_MAX;
        S_time[pnt] = DBL_MAX;
    }
    dijkstra(F_start, F_time, fv, adj);
    dijkstra(S, S_time, sv, adj);

    // print_adj(adj);
    cout << setprecision(15);
    // cout << "F TIME" << endl;
    // for (auto& [pnt, t] : F_time){
    //     // if (t == DBL_MAX) continue;
    //     cout << "(" << pnt.x << ", " << pnt.y << ") : " << t << endl;
    // } cout << endl;
    // cout << "S TIME" << endl;
    // for (auto& [pnt, t] : S_time){
    //     // if (t == DBL_MAX) continue;
    //     cout << "(" << pnt.x << ", " << pnt.y << ") : " << t << endl;
    // } cout << endl;

    double ans = DBL_MAX;
    for (int i = 0; i < f_path.size(); i++){
        if (S_time.find(f_path[i]) != S_time.end()){
            if (S_time[f_path[i]] <= F_time[f_path[i]]){
                ans = min(ans, F_time[f_path[i]]);
            }
        }
    }

    cout << (ans == DBL_MAX ? -1 : ans/PR) << endl;
    
    return 0;
}