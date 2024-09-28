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

bool valid(int r, int c){
    return 0 <= r && r < R && 0 <= c && c < C;
}

bool rec(vector<char>& cur, int r, int c, int dir, vector<int>& path){
    // if (debug){
    //     for (auto c : cur) cout << c; cout << endl;
    //     cout << k << " " << dir << endl;
    // }
    if (cur.size() > sv.size()) return false;
    if (cur == sv){
        if ((int)sv.size() == 1) return true;
        int prev = path[1];
        int k = 0;
        for (int i = 2; i < path.size(); i++){
            if (prev != path[i]){
                k++;
            }
            prev = path[i];
        }
        if (k==K) {
            // cout << "-" << endl;
            // for (auto c : cur) cout << c; cout << endl;
            // cout << k << endl;
            // for (auto p : path) cout << p << " "; cout << endl;
            // cout << "-" << endl;
            return true;
        }
    }

    bool good = false;
    for (int d = 0; d < 8; d++){
        if (d != dir && k == K) continue;

        int nr, nc;
        nr = r + dr[d];
        nc = c + dc[d];
        if (valid(nr, nc) && grid[nr][nc] == sv[(int)cur.size()]){
            cur.push_back(grid[nr][nc]);
            path.push_back(d);
            good = good || rec(cur, nr, nc, d, path);
            cur.pop_back();
            path.pop_back();
        }
    }

    return good;
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
    int good = false;
    vector<char> cur;
    vector<int> path;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            for (int d = 0; d < 8; d++){
                if (grid[r][c] != sv[0]) continue;
                if (r == 1 && c == 4){
                    debug = 1;
                }
                else{
                    debug = 0;
                }
                cur.clear();
                cur.push_back(grid[r][c]);
                path.clear();
                path.push_back(d);
                if (rec(cur, r, c, d, path)){
                    good = true;
                    break;
                }
                
            }
             
        }
    }

    cout << (good ? "YES" : "NO") << endl;
    
    return 0;
}