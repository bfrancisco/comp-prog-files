#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define se second
#define pb push_back

vector<string> dir = {"E", "N", "S", "W"};
vector<int> dx = {0, -1, 1, 0};
vector<int> dy = {1, 0, 0, -1};
int r, c;
unordered_map<char, int> dtoi;

bool valid(int x, int y, vector<string>& grid, char goal){
    if ((0 <= x && x < r && 0 <= y && y < c) && (grid[x][y] == '.' || grid[x][y] == goal)) return true;
    return false;
}

int manhattan(int x, int y, int x2, int y2, vector<string>& grid, string prev, char goal){
    int ret = abs(x2-x) + abs(y2-y);
    if (ret == 0) return ret;

    else if (prev.back() == 'W' || prev.back() == 'E'){
        if (!valid(x+1, y, grid, goal) && !valid(x-1, y, grid, goal)) return -1;
    }
    else if (prev.back() == 'S' || prev.back() == 'N'){
        if (!valid(x, y+1, grid, goal) && !valid(x, y-1, grid, goal)) return -1;
    }
    return ret;
}

string astar(int ux, int uy, int vx, int vy, char goal, stack<string>& out, vector<string>& grid, string lastprev){
    
    // open = {manhattan distance : {x, y} : previous move}
    set<tuple<int, string, pair<int, int>, int>> open;
    
    // closed = {{x, y} : }
    map<pair<int, int>, string> closed;
    map<pair<int, int>, int> closed2;
    open.insert({0, lastprev, {ux, uy}, 0});

    while(!open.empty()){
        pair<int, int> cur = get<2>(*open.begin());
        string prev_move = get<1>(*open.begin());
        int moves = get<3>(*open.begin());
        open.erase(open.begin());
        closed[cur] = prev_move;
        closed2[cur] = get<0>(*open.begin());

        cout << "coord: " << cur.fi << " " << cur.se << " " << prev_move << " " << moves << endl;

        if (grid[cur.fi][cur.se] == goal){
            // cout << "   GOAL! prev: " << prev_move << endl;
            // for (auto m : closed)
            //     cout << m.fi.fi << "," << m.fi.se << " : " << m.se << endl;
            char ogprev = prev_move.back();
            string ogprevret; ogprevret.push_back(ogprev);
            ogprevret.push_back('X');
            while(prev_move.back() != 'X'){ // problem with second number
                out.push(prev_move);
                cout << "prev: " << prev_move << " " << cur.fi << " " << cur.se << endl;
                for (auto& c : prev_move){
                    if (c == 'E') cur.se--;
                    else if (c == 'W') cur.se++;
                    else if (c == 'N') cur.fi++;
                    else if (c == 'S') cur.fi--;
                }
                prev_move = closed[cur];
            }
            return ogprevret;
        }

        for (int i = 0; i < 4; i++){
            pair<int, int> newp;
            newp.fi = cur.fi + dx[i];
            newp.se = cur.se + dy[i];

            if (!valid(newp.fi, newp.se, grid, goal) || dtoi[prev_move.back()] == i)
                continue;
            

            int man = manhattan(newp.fi, newp.se, vx, vy, grid, prev_move, goal);
            if (man == -1) continue;
            
            // cout << "   next: " << newp.fi << " " << newp.se << " " << man << endl;
            if (closed.find(newp) != closed.end()){
                if (closed2[newp] >= man+moves+1){
                    open.insert({man+moves+1, dir[i], newp, moves+1});
                    closed[newp] = dir[i];
                    closed2[newp] = man+moves+1;
                }
            }
            else{
                open.insert({man+moves+1, dir[i], newp, moves+1});
            }
            
            
        }
        // cout << "\nOPEN:" << endl;
        // for (auto& e : open){
        //     cout << (get<2>(e)).fi << " " << (get<2>(e)).se << " " << (get<1>(e)) << endl;
        // }
    }
    return "A"; // returning A means IMPOSSIBLE
}

void solve(){
    cin >> r >> c;
    vector<string> grid(r);
    vector<pair<char, pair<int, int>>> nums;
    pair<int, int> start;
    for (int i = 0; i < r; i++){
        cin >> grid[i];
        for (int j = 0; j < c; j++){
            if (grid[i][j] == 'X'){
                start.fi = i; start.se = j;
            }
            else if (grid[i][j] != '#' && grid[i][j] != '.'){
                nums.push_back({grid[i][j], {i, j}});
            }
        }
    }

    sort(nums.begin(), nums.end(), greater<>());

    // print nums
    // for (auto& p : nums){
    //     cout << p.fi << "  :  " << p.se.fi << " " << p.se.se << endl;
    // }

    vector<char> ans;
    
    bool pas = true;
    grid[start.fi][start.se] = '.';
    string prev = "X";
    for (auto& p : nums){
        stack<string> out;
        prev = astar(start.fi, start.se, p.se.fi, p.se.se, p.fi, out, grid, prev);
        // cout << "outprev: " << prev << endl;
        if (prev == "A")
            {pas = false; break;}
        start.fi = p.se.fi;
        start.se = p.se.se;
        while(!out.empty()){
            for (auto& c : out.top())
                ans.push_back(c);
            out.pop();
        }
    }

    if (!pas) cout << "IMPOSSIBLE" << endl;
    else{
        // N-N = ENWN > NEWN > NWEN
        // S-S = ESWS > SEWS > SWES
        // W-W = WNSW > WSNW
        // E-E = ENES > ENSE > ESEN > ESNE

        for (auto& c : ans) cout << c;
        cout << endl;

    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dtoi['E'] = 0;
    dtoi['N'] = 1;
    dtoi['S'] = 2;
    dtoi['W'] = 3;
    dtoi['X'] = 4;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}