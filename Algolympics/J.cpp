#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define se second

string dir = "ENSW";
vector<int> dx = {0, -1, 1, 0};
vector<int> dy = {1, 0, 0, -1};
int r, c;

int manhattan(int x1, int y1, int x2, int y2){
    return abs(x2-x1) + abs(y2-y1);
}

bool valid(int x, int y){
    if (0 <= x && x < r && 0 <= y && y < c) return true;
    return false;
}

bool astar(int ux, int uy, int vx, int vy, char goal, stack<char>& out, vector<string>& grid){
    
    // open = {manhattan distance : {x, y} : previous move}
    set<tuple<int, pair<int, int>, char>> open;
    
    // closed = {{x, y} : }
    set<pair<int, int>> closed;

    open.insert({0, {ux, uy}, 'X'});

    while(!open.empty()){
        pair<int, int> cur = get<1>(*open.begin());
        cout << cur.first << " " << cur.second << endl;
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

    vector<char> outAll;
    stack<char> out;
    bool pas = true;
    for (auto& p : nums){
        cout << p.se.fi << endl;
        if (!astar(start.fi, start.se, p.se.fi, p.se.se, p.fi, out, grid))
            {pas = false; break;}
        start.fi = p.se.fi;
        start.se = p.se.se;
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
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}