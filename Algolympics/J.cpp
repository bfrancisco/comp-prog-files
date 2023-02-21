#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define se second

string dir = "ENSW";
vector<int> dx = {0, -1, 1, 0};
vector<int> dy = {1, 0, 0, -1};
unordered_map<char, pair<int, int>> dirvals;
dirvals['E'] = {0, 1};
dirvals['N'] = {-1, 0};
dirvals['S'] = {1, 0};
dirvals['W'] = {0, -1};
int r, c;

int manhattan(int x1, int y1, int x2, int y2){
    return abs(x2-x1) + abs(y2-y1);
}

bool valid(int x, int y){
    if (0 <= x && x < r && 0 <= y && y < c) return true;
    return false;
}

bool astar(int ux, int uy, int vx, int vy, char goal, vector<char>& out, vector<string>& grid){
    priority_queue<tuple<int, pair<int, int>, char>> open;
    // manhanttan distance, coordinate, previous direction
    unordered_map<pair<int, int>, char> closed;

    open.push({0, {ux, uy}, 'X'});
    // manhattan distance, coordinates, previous direction

    while(!open.empty()){
        int cx = get<1>(open.top()).fi;
        int cy = get<1>(open.top()).se;
        int prev = get<2>(open.top());
        // closed.insert({cx, cy});
        closed[{cx, cy}] = prev;
        open.pop();

        if (grid[cx][cy] == goal){
            while(prev != 'X'){
                out.push(prev);
                cx -= dirvals[prev].fi;
                cy -= dirvals[prev].se;
                prev = closed[{cx, cy}];
            }
            return true;
        }

        for (int i = 0; i < 4; i++){
            if (prev == dir[i] || (!valid(cx+dx[i], c)) || closed.find({cx, cy}) != closed.end())
                continue;
            int nx = cx+dx[i];
            int ny = cx+dx[i];
            open.push({manhattan(nx, ny, vx, vy), {nx, ny}, dir[i]});
        }
    }
    return false;
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

    sort(nums.begin(), nums.end());

    // print nums
    // for (auto& p : nums){
    //     cout << p.fi << "  :  " << p.se.fi << " " << p.se.se << endl;
    // }

    vector<char> out;
    bool pas = true;
    for (auto& p : nums){
        if (!astar(start.fi, start.se, p.se.fi, p.se.se, p.fi, out, grid))
            {pas = false; break;}
        start.fi = p.se.fi;
        start.se = p.se.se;
    }

    if (!pas) cout << "IMPOSSIBLE" << endl;
    else{
        reverse(out.begin(), out.end());
        for (auto& e : out) cout << e;
        cout << endl;
    }


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}