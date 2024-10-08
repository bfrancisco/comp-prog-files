#include<bits/stdc++.h>
using namespace std;

const double M = 10000;
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
 
        if (!(min(A.x, B.x) <= cx && cx <= max(A.x, B.x) && 
            min(A.y, B.y) <= cy && cy <= max(A.y, B.y) &&
            min(other.A.x, other.B.x) <= cx && cx <= max(other.A.x, other.B.x) && 
            min(other.A.y, other.B.y) <= cy && cy <= max(other.A.y, other.B.y))){
                return {DBL_MAX, DBL_MAX};
            }
 
        return Point(cx, cy);
    }
 
    bool on_line(Point pnt){
        return (fabs(A.get_distance(B) - (pnt.get_distance(A) + pnt.get_distance(B))) < epsi);
    }
    
    void print(){
        A.print(); cout << " to "; B.print(); cout << endl;
    }
};
 
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
    // if (!(pnt == line.A)){
        adj[pnt].insert(line.A);
        adj[line.A].insert(pnt);
    // }
    // if (!(pnt == line.B)){
        adj[pnt].insert(line.B);
        adj[line.B].insert(pnt);
    // }
}

void update_adj(Point pnt1, Point pnt2, map<Point, set<Point>>& adj){
    // if (!(pnt1 == pnt2)){
        adj[pnt1].insert(pnt2);
        adj[pnt2].insert(pnt1);
    // }
}
 
// void dijkstra(Point start, map<Point, double>& time, double vel, map<Point, set<Point>>& adj){
//     priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<pair<double, Point>>> q;
//     q.push(make_pair(0, start));
//     time[start] = 0;
//     while (!q.empty()){
//         auto [t, pnt] = q.top();
//         q.pop();
//         if (time[pnt] < t) continue;
//         time[pnt] = t;
//         for (auto p : adj[pnt]){
//             if (time[p] > time[pnt] + pnt.get_distance(p)/vel){
//                 time[p] = time[pnt] + pnt.get_distance(p)/vel;
//                 q.push(make_pair(time[p], p));
//             }
//         }
//     }
// }

void dijkstra(Point start, map<Point, double>& dst, map<Point, set<Point>>& adj){
    priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<pair<double, Point>>> q;
    q.push(make_pair(0, start));
    dst[start] = 0;
    while (!q.empty()){
        auto [t, pnt] = q.top();
        q.pop();
        if (dst[pnt] < t) continue;
        dst[pnt] = t;
        for (auto p : adj[pnt]){
            if (dst[p] > dst[pnt] + pnt.get_distance(p)){
                dst[p] = dst[pnt] + pnt.get_distance(p);
                q.push(make_pair(dst[p], p));
            }
        }
    }
}
 
int main(){
    int n;
    cin >> n;
 
    vector<Line> lines;
    for (int i = 0; i < n; i++){
        double a,b,c,d;
        cin >> a >> b >> c >> d;

        a *= M;
        b *= M;
        c *= M;
        d *= M;

        lines.push_back(Line(Point(a, b), Point(c, d)));
    }
 
    // for (auto line : lines) line.print();
    // cout << lines[0].A.get_distance(lines[0].B) << endl;
 
    double sx, sy, sv;
    cin >> sx >> sy >> sv;
    double fsx, fsy, fex, fey, fv;
    cin >> fsx >> fsy >> fex >> fey >> fv;
    
    sx *= M; sy *= M; sv *= M;
    fsx *= M; fsy *= M; fex *= M; fey *= M; fv *= M;

    Point S(sx, sy), F_start(fsx, fsy), F_end(fex, fey);
    Line F(F_start, F_end);
    
    // Find critical points. intersection points of F and lines[i] for all i.
    // at the same time, insert critical points to graph of S
    set<Point> f_path;
    map<Point, set<Point>> adj;
    map<Line, set<Point>> line_crit; // lines containing crit points
    for (auto line : lines){
        Point crit_pnt = F.get_intersection_point(line);
        if (fabs(crit_pnt.x - DBL_MAX) < epsi) continue;
        f_path.insert(crit_pnt);
        update_adj(crit_pnt, line, adj);
        line_crit[line].insert(crit_pnt);
        // line.print();
        // cout << "connect: "; crit_pnt.print(); cout << endl;
    }

    // line where S is on
    for (auto line : lines){
        if (line.on_line(S)){
            update_adj(S, line, adj);
            // cout << "SLINE  "; line.print();
            for (auto crit_pnt : line_crit[line]){
                update_adj(S, crit_pnt, adj);
                // cout << '\t'; crit_pnt.print(); cout << endl;
            }
        }
    }


    // for (auto [line, ss] : line_crit){
    //     cout << line.A.x << ", " << line.A.y << " to " << line.B.x << ", " << line.B.y << endl;
    //     cout << "\t";
    //     for (auto p : ss){
    //         p.print();
    //         cout << endl;
    //     }
    // }cout << endl;
 
    // pair all lines, create nodes for intersection
    for (int i = 0; i < lines.size(); i++){
        for (int j = i+1; j < lines.size(); j++){
            Line line1 = lines[i];
            Line line2 = lines[j];
            Point inter = line1.get_intersection_point(line2);  
            if (fabs(inter.x - DBL_MAX) > epsi){
                update_adj(inter, line1, adj);
                update_adj(inter, line2, adj);
                // line1.print();
                // line2.print();
                for (auto crit_pnt : line_crit[line1]){
                    // cout << "\tPAIR1 "; inter.print(); cout << " - "; crit_pnt.print(); cout << endl;
                    update_adj(inter, crit_pnt, adj);
                }
                for (auto crit_pnt : line_crit[line2]){
                    // cout << "\tPAIR2 "; inter.print(); cout << " - "; crit_pnt.print(); cout << endl;
                    update_adj(inter, crit_pnt, adj);
                }
            }
        }
    }
 
    map<Point, double> S_dst;
    for (auto [pnt, vec] : adj){
        S_dst[pnt] = DBL_MAX;
    }
    // dijkstra(S, S_time, sv, adj);
    dijkstra(S, S_dst, adj);
 
    
    cout << setprecision(10);

    // print_adj(adj);
    // cout << "S dst" << endl;
    // for (auto& [pnt, t] : S_dst){
    //     // if (t == DBL_MAX) continue;
    //     cout << "(" << pnt.x << ", " << pnt.y << ") : " << t << endl;
    // } cout << endl;
 
    double ans = DBL_MAX;
    for (auto f_node : f_path){
        double f_time = F_start.get_distance(f_node) / fv;
        // f_node.print(); cout << " : " << f_time << endl;
        double s_time = S_dst[f_node] / sv;
        if (s_time < f_time || fabs(s_time - f_time) < epsi){
            // cout << f_dst << endl;
            if (ans > f_time){
                ans = f_time;
                // cout << "\t"; f_node.print(); cout << endl;
            }
        }
    }
 
    cout << (fabs(ans - DBL_MAX) < epsi ? -1 : ans) << endl;

    
    return 0;
}