#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int R, C;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool valid(int r, int c){
    return (0 < r && r <= R && 0 < c && c <= C);
}

void bfs(int sr, int sc, char person, vector<vector<char>>& grid, vector<vector<int>>& vis){
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;
    while (!q.empty()){
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (!valid(nr, nc) || vis[nr][nc] || grid[nr][nc] != person) continue;
            vis[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
}

void solve(){
    cin >> R >> C;
    vector<vector<char>> grid(R+2, vector<char>(C+2, '-'));
    for (int r = 1; r <= R; r++){
        for (int c = 1; c <= C; c++){
            cin >> grid[r][c];
        }
    }
    vector<vector<int>> vis(R+2, vector<int>(C+2, 0));
    int regions = 0;
    for (int r = 1; r <= R; r++){
        for (int c = 1; c <= C; c++){
            if (vis[r][c] == 0){
                bfs(r, c, grid[r][c], grid, vis);
                regions++;
            }
        }
    }

    int aborder = 0, cborder = 0;
    for (int i = 1; i <= C; i++){
        if (grid[1][i] == 'A') aborder=1;
        if (grid[R][i] == 'A') aborder=1;
        if (grid[1][i] == 'C') cborder=1;
        if (grid[R][i] == 'C') cborder=1;
    }
    for (int i = 1; i <= R; i++){
        if (grid[i][1] == 'A') aborder=1;
        if (grid[i][C] == 'A') aborder=1;
        if (grid[i][1] == 'C') cborder=1;
        if (grid[i][C] == 'C') cborder=1;
    }
    if (regions != 2 || aborder+cborder != 2){
        cout << "NO" << endl; return;
    }

    vector<vector<int>> up(R+2, vector<int>(C+2, 0));
    vector<vector<int>> down(R+2, vector<int>(C+2, 0));
    vector<vector<int>> left(R+2, vector<int>(C+2, 0));
    vector<vector<int>> right(R+2, vector<int>(C+2, 0));
    for (int r = 1; r <= R; r++){
        for (int c = 1; c <= C; c++){
            if (grid[r+1][c] == 'A') down[r][c] = 1;
            if (grid[r-1][c] == 'A') up[r][c] = 1;
            if (grid[r][c+1] == 'A') right[r][c] = 1;
            if (grid[r][c-1] == 'A') left[r][c] = 1;
        }
    }

    int verts = 0, horis = 0;
    set<int> curvs, curhs;
    for (int r = 1; r <= R; r++){
        vector<int> les, ris;
        for (int c = 1; c <= C; c++){
            if (right[r][c]==1 && left[r][c+1]==0){
                les.push_back(c); // between c and c+1
            }
            else if (c != C && right[r][c]==0 && left[r][c+1]==1){
                ris.push_back(c); // between c and c+1
            }
        }

        for (auto le : les){
            if (curvs.find(le) == curvs.end()) verts++;
        }
        for (auto ri : ris){
            if (curvs.find(ri) == curvs.end()) verts++;
        }
        curvs.clear();
        for (auto le : les) curvs.insert(le);
        for (auto ri : ris) curvs.insert(ri);
    }
    for (int c = 1; c <= C; c++){
        vector<int> tos, dos;
        for (int r = 1; r <= R; r++){
            if (down[r][c]==1 && up[r+1][c]==0){
                tos.push_back(r);
            }
            else if (r != R && down[r][c]==0 && up[r+1][c]==1){
                dos.push_back(r);
            }
        }

        for (auto to : tos){
            if (curhs.find(to) == curhs.end()) horis++;
        }
        for (auto ds : dos){
            if (curhs.find(ds) == curhs.end()) horis++;
        }
        curhs.clear();
        for (auto to : tos) curhs.insert(to);
        for (auto ds : dos) curhs.insert(ds);
        // for (auto curh : dos) cout << curh << " "; cout << endl;
    }

    // cout << "verts: " << verts << endl;
    // cout << "horis: " << horis << endl;
    cout << "YES\n" << verts + horis << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}