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
    if (prev.back() == 'W' || prev.back() == 'E'){
        if (!valid(x+1, y, grid, goal) && !valid(x-1, y, grid, goal)) return -1;
    }
    else if (prev.back() == 'S' || prev.back() == 'N'){
        if (!valid(x, y+1, grid, goal) && !valid(x, y-1, grid, goal)) return -1;
    }
    int ax = abs(x2-x);
    int ay = abs(y2-y);
    return ax + ay;
}

void move(int& x, int& y, char d){
    if (d == 'E') y++;
    else if (d == 'N') x--;
    else if (d == 'S') x++;
    else if (d == 'W') y--; 
}

string astar(int ux, int uy, int vx, int vy, char goal, stack<string>& out, vector<string>& grid, string lastprev){
    
    // open = {manhattan distance : {x, y} : previous move}
    set<tuple<int, string, pair<int, int>>> open;
    
    // closed = {{x, y} : }
    map<pair<int, int>, string> closed;

    open.insert({0, lastprev, {ux, uy}});

    while(!open.empty()){
        pair<int, int> cur = get<2>(*open.begin());
        string prev_move = get<1>(*open.begin());
        open.erase(open.begin());
        closed[cur] = prev_move;

        // cout << "coord: " << cur.fi << " " << cur.se << " " << prev_move << endl;

        if (grid[cur.fi][cur.se] == goal){
            // cout << "   GOAL! prev: " << prev_move << endl;
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
            


            int man = manhattan(newp.fi, newp.se, vx, vy, grid, prev_move, goal);
            if (man == -1) continue;
            
            // cout << "   next: " << newp.fi << " " << newp.se << " " << man << endl;
            if (dtoi[prev_move.back()] == i){
                // N-N = ENW > EWN > WEN
                // S-S = ESW > EWS > WES
                // W-W = NSW > SNW
                // E-E = NES > NSE > SEN > SNE

                if (prev_move.back() == 'N'){
                    if (valid(cur.fi, cur.se+1, grid, goal)){   // E
                        if (valid(cur.fi-1, cur.se+1, grid, goal))  // NE
                            open.insert({man, "ENW", newp});
                        // EW
                        open.insert({man, "EWN", newp});
                    }
                    else if (valid(cur.fi, cur.se-1, grid, goal)){  // W
                        open.insert({man, "WEN", newp});
                    }
                }
                else if (prev_move.back() == 'S'){
                    if (valid(cur.fi, cur.se+1, grid, goal)){ // E
                        if (valid(cur.fi+1, cur.se+1, grid, goal)) // SE
                            open.insert({man, "ESW", newp});
                        // EW
                        open.insert({man, "EWS", newp});
                    }
                    else if (valid(cur.fi, cur.se-1, grid, goal)){  // W
                        open.insert({man, "WES", newp});
                    }
                }
                else if (prev_move.back() == 'W'){
                    if (valid(cur.fi-1, cur.se, grid, goal)) // N
                        open.insert({man, "NSW", newp});
                    else if (valid(cur.fi+1, cur.se, grid, goal)) // S
                        open.insert({man, "SNW", newp});
                }
                else if (prev_move.back() == 'E'){
                    if (valid(cur.fi-1, cur.se, grid, goal)){ // N
                        if (valid(cur.fi-1, cur.se+1, grid, goal))  // NE
                            open.insert({man, "NES", newp});
                        // NS
                        open.insert({man, "NSE", newp});
                    }
                    else if (valid(cur.fi+1, cur.se, grid, goal)){ // S
                        if (valid(cur.fi+1, cur.se+1, grid, goal)){ // SE
                            open.insert({man, "SEN", newp});
                        }
                        // SN
                        open.insert({man, "SNE", newp});
                    }
                }

                continue;
            }

            
            open.insert({man, dir[i], newp});
            
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
        int n = ans.size();
        char p = 'X';
        vector<char> legit;
        int x = start.fi;
        int y = start.se;

        for (auto& c : ans) cout << c;
        cout << endl;

        // for (int i = 0; i < n-1; i++){
        //     if (ans[i] != ans[i+1]){
        //         legit.pb(ans[i]); prev = ans[i]; move(x, y, ans[i]);
        //     }
        //     else if (ans[i] == 'E'){
        //         if ()
        //     }
        //     else if (ans[i] == 'N'){

        //     }
        //     else if (ans[i] == 'S'){

        //     }
        //     else if (ans[i] == 'W'){

        //     }
        // }
        // cout << endl;
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