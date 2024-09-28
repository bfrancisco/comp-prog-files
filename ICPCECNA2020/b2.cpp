#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MXLEN = 100;
int R, C;
vector<vector<char>> grid;
string s;
vector<char> sv;
int K;

int dr[8] = {-1, -1, -1,  0 , 0,  1 , 1, 1};
int dc[8] = {-1, 0 ,  1,  -1, 1,  -1, 0, 1};
int debug = 0;
bool good = false;

bool valid(int r, int c){
    return 0 <= r && r < R && 0 <= c && c < C;
}

void rec(vector<char>& cur, int r, int c, int k, int dir){
    // for (auto c : cur) cout << c; cout << endl;
    // cout << r << " " << c << endl;
    cout << k << endl;
    if (good) return;
    if (cur.size() > sv.size() || k > K) return;
    if (cur == sv & k == K) {good = true; return;}

    int direc = dir;

    for (int d = 0; d < 8; d++){
        if (dir == -1) direc = d;
        if (d != direc && k == K) continue;

        int nr, nc;
        nr = r + dr[d];
        nc = c + dc[d];
        if (valid(nr, nc) && grid[nr][nc] == sv[(int)cur.size()]){
            cur.push_back(grid[nr][nc]);
            rec(cur, nr, nc, k + (direc != d), d);
            cur.pop_back();
        }
        if (good) break;

    }

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    cin >> R >> C;
    grid.resize(R, vector<char>(C));
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            cin >> grid[r][c];
        }
    }
    cin >> K;
    cin >> s;
    for (auto c : s) sv.push_back(c);
    
    vector<char> cur;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (grid[r][c] != sv[0]) continue;
            cout << "START" << endl;
            cur.push_back(grid[r][c]);
            rec(cur, r, c, 0, -1);
            cur.clear();

            if (good) break; 
        }
        if (good) break; 
    }

    cout << (good ? "YES" : "NO") << endl;
    
    return 0;
}