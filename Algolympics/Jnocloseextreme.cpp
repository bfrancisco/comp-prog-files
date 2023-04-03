#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define se second
#define pb push_back

// vector<char> dir = {"E", "N", "S", "W"};
string dir = "ENSW";
vector<int> dx = {0, -1, 1, 0};
vector<int> dy = {1, 0, 0, -1};
int r, c;
unordered_map<char, int> dtoi;

bool valid(int x, int y, vector<string>& grid, char goal){
    if ((0 <= x && x < r && 0 <= y && y < c) && (grid[x][y] == '.' || grid[x][y] == goal)) return true;
    return false;
}

int manhattan(int x, int y, int x2, int y2, vector<string>& grid, char prev, char goal){
    int ret = abs(x2-x) + abs(y2-y);
    if (ret == 0) return ret;

    else if (prev == 'W' || prev == 'E'){
        if (!valid(x+1, y, grid, goal) && !valid(x-1, y, grid, goal)) return -1;
    }
    else if (prev == 'S' || prev == 'N'){
        if (!valid(x, y+1, grid, goal) && !valid(x, y-1, grid, goal)) return -1;
    }
    return ret;
}

string astar(int ux, int uy, int vx, int vy, char goal, vector<string>& grid, char lastprev){
    
    // open = {manhattan distance : {x, y} : previous move}
    set<tuple<int, char, pair<int, int>, int, string>> open;
    
    // closed = {{x, y} : }
    // map<pair<int, int>, string> closed;
    map<pair<int, int>, int> closed2;
    string tmp;
    open.insert({0, lastprev, {ux, uy}, 0, tmp});

    vector<string> possiblemoves;

    while(!open.empty()){
        tuple<int, char, pair<int, int>, int, string> gettup = (*open.begin());

        char prev_move = get<1>(gettup);
        pair<int, int> cur = get<2>(gettup);
        int moves = get<3>(gettup);
        string smove = get<4>(gettup);
        closed2[cur] = get<0>(gettup);
        
        open.erase(open.begin());
        // closed[cur] = prev_move;
        
        // cout << "coord: " << cur.fi << " " << cur.se << " " << prev_move << " " << moves << endl;
        // cout << smove << endl;
        if (grid[cur.fi][cur.se] == goal){
            possiblemoves.push_back(smove);
            continue;
        }

        for (int i = 0; i < 4; i++){
            pair<int, int> newp;
            newp.fi = cur.fi + dx[i];
            newp.se = cur.se + dy[i];
            string smovetmp = smove;

            if (!valid(newp.fi, newp.se, grid, goal) || dtoi[prev_move] == i)
                continue;
            

            int man = manhattan(newp.fi, newp.se, vx, vy, grid, prev_move, goal);
            if (man == -1) continue;
            
            // cout << "   next: " << newp.fi << " " << newp.se << " " << man << endl;
            if (closed2.find(newp) != closed2.end()){
                if (closed2[newp] >= (man+moves+1)){
                    smovetmp.push_back(dir[i]);
                    open.insert({man+moves+1, dir[i], newp, moves+1, smovetmp});
                    closed2[newp] = man+moves+1;
                }
            }
            else{
                smovetmp.push_back(dir[i]);
                open.insert({man+moves+1, dir[i], newp, moves+1, smovetmp});
                closed2[newp] = man+moves+1;
            }
        }

        // cout << "\nOPEN:" << endl;
        // for (auto& e : open){
        //     cout << (get<2>(e)).fi << " " << (get<2>(e)).se << " " << (get<1>(e)) << endl;
        // }

        // cout << "\nCLOSED:" << endl;
        // for (auto& e : closed2){
        //     cout << e.fi.fi << " " << e.fi.se << " " << e.se << endl;
        // }
    }

    if (possiblemoves.empty())
        return "A"; // returning A means IMPOSSIBLE
    
    sort(possiblemoves.begin(), possiblemoves.end());
    cout << endl;
    for (auto&s : possiblemoves)
        cout << s << endl;
    cout << "\nleast: " << possiblemoves[0] << endl;
    return possiblemoves[0];
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

    string ans;
    
    bool pas = true;
    grid[start.fi][start.se] = '.';
    string prev = "X";
    for (auto& p : nums){
        prev = astar(start.fi, start.se, p.se.fi, p.se.se, p.fi, grid, prev[0]);
        // cout << "outprev: " << prev << endl;
        if (prev == "A")
            {pas = false; break;}
        start.fi = p.se.fi;
        start.se = p.se.se;
        for (auto& c : prev)
            ans.push_back(c);
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