#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define se second

vector<string> dir = {"E", "N", "S", "W"};
vector<int> dx = {0, -1, 1, 0};
vector<int> dy = {1, 0, 0, -1};
int r, c;
unordered_map<char, int> dtoi;

int manhattan(int x1, int y1, int x2, int y2){
    return abs(x2-x1) + abs(y2-y1);
}

bool valid(int x, int y, vector<string>& grid, char goal){
    if ((0 <= x && x < r && 0 <= y && y < c) && (grid[x][y] == '.' || grid[x][y] == goal)) return true;
    return false;
}

string astar(int ux, int uy, int vx, int vy, char goal, stack<string>& out, vector<string>& grid, string lastprev){
    
    // open = {manhattan distance : {x, y} : previous move}
    set<tuple<int, pair<int, int>, string>> open;
    
    // closed = {{x, y} : }
    map<pair<int, int>, string> closed;

    open.insert({0, {ux, uy}, lastprev});

    while(!open.empty()){
        pair<int, int> cur = get<1>(*open.begin());
        string prev_move = get<2>(*open.begin());
        open.erase(open.begin());
        closed[cur] = prev_move;

        cout << "coord: " << cur.fi << " " << cur.se << " " << prev_move << endl;

        if (grid[cur.fi][cur.se] == goal){
            cout << "   GOAL! prev: " << prev_move << endl;
            // for (auto m : closed)
            //     cout << m.fi.fi << "," << m.fi.se << " : " << m.se << endl;
            char ogprev = prev_move.back();
            string ogprevret; ogprevret.push_back(ogprev);
            ogprevret.push_back('X');
            while(prev_move.back() != 'X'){ // problem with second number
                out.push(prev_move);
                // cout << prev_move << endl;
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

            if (!valid(newp.fi, newp.se, grid, goal) || closed.find(newp) != closed.end())
                continue;
            if (dtoi[prev_move.back()] == i){
                // N-N = ENW > EWN > WEN
                // S-S = ESW > EWS > WES
                // W-W = NSW > SNW
                // E-E = NES > NSE > SEN > SNE

                if (prev_move.back() == 'N'){
                    if (valid(cur.fi, cur.se+1, grid, goal)){   // E
                        if (valid(cur.fi-1, cur.se+1, grid, goal))  // NE
                            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "ENW"});
                        else    // EW
                            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "EWN"});
                    }
                    else if (valid(cur.fi, cur.se-1, grid, goal)){  // W
                        open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "WEN"});
                    }
                }
                else if (prev_move.back() == 'S'){
                    if (valid(cur.fi, cur.se+1, grid, goal)){ // E
                        if (valid(cur.fi+1, cur.se+1, grid, goal)) // SE
                            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "ESW"});
                        else    // EW
                            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "EWS"});
                    }
                    else if (valid(cur.fi, cur.se-1, grid, goal)){  // W
                        open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "WES"});
                    }
                }
                else if (prev_move.back() == 'W'){
                    if (valid(cur.fi-1, cur.se, grid, goal)) // N
                        open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "NSW"});
                    else if (valid(cur.fi+1, cur.se, grid, goal)) // S
                        open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "SNW"});
                }
                else if (prev_move.back() == 'E'){
                    if (valid(cur.fi-1, cur.se, grid, goal)){ // N
                        if (valid(cur.fi-1, cur.se+1, grid, goal))  // NE
                            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "NES"});
                        else    // NS
                            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "NSE"});
                    }
                    else if (valid(cur.fi+1, cur.se, grid, goal)){ // S
                        if (valid(cur.fi+1, cur.se+1, grid, goal)){ // SE
                            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "SEN"});
                        }
                        else // SN
                            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, "SNE"});
                    }
                }

                continue;
            }
            // cout << "   next: " << newp.fi << " " << newp.se << endl;
            open.insert({manhattan(newp.fi, newp.se, vx, vy), newp, dir[i]});
            
        }
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

    vector<char> outAll;
    
    bool pas = true;
    grid[start.fi][start.se] = '.';
    string prev = "X";
    for (auto& p : nums){
        stack<string> out;
        prev = astar(start.fi, start.se, p.se.fi, p.se.se, p.fi, out, grid, prev);
        cout << "outprev: " << prev << endl;
        if (prev == "A")
            {pas = false; break;}
        start.fi = p.se.fi;
        start.se = p.se.se;
        while(!out.empty()){
            for (auto& c : out.top())
                outAll.push_back(c);
            out.pop();
        }
    }

    if (!pas) cout << "IMPOSSIBLE" << endl;
    else{
        for (auto& e : outAll) cout << e;
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