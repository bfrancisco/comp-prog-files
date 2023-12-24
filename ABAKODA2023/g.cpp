#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h, w;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
string d = "SENW";
vector<char> moves;
vector<vector<int>> grid; // 0 - unvis, 1 - safe, 2 - unsafe
string in;

bool valid(int r, int c){
    return (0 <= r && r < h && 0 <= c && c < w);
}

void print_prev_moves(){
    // cout << "PREV: "; for (auto m : moves) cout << m; cout << endl; // debug
    for (auto m : moves){
        cout << m << endl;
        cin >> in;
    }
}

bool done = false;
int dfs(int r, int c){
    int safe = 0;
    for (int i = 0; i < 4; i++){
        if (done) break;
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!valid(nr, nc) || grid[nr][nc] != 0) continue;
        // cout << d[i] << " " << nr << " " << nc << endl;
        cout << d[i] << endl;
        cin >> in;
        if (in == "YAY"){
            grid[nr][nc] = 1;
            safe = 1;
            done = true;
            break;
        }
        else if (in == "SAFE"){
            moves.push_back(d[i]);
            grid[nr][nc] = 1;
            safe |= dfs(nr, nc);
        }
        else if (in == "TRAP"){
            grid[nr][nc] = 2;
            print_prev_moves();
        }

    }
    if (!safe){
        for (int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!valid(nr, nc) || (valid(nr, nc) && grid[nr][nc] == 2)){
                // cout << d[i] << " exit" << endl;
                cout << d[i] << endl;
                cin >> in; // should be TRAP
                break;
            }
        }
        if (!moves.empty()) moves.pop_back();
        print_prev_moves();
    }
    return safe;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> h >> w;
    grid.assign(h, vector<int>(w, 0));
    grid[0][0] = 1;
    int safe = dfs(0, 0);
    if (!safe) cout << "RIGGED" << endl;

    return 0;
}