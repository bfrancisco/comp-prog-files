#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

vector<vector<char>> grid;
vector<vector<int>> dist;
int n, m, t;
int nP; // initial Ps
int ans = (int)1e9;
set<pair<int, int>> exits;

// R L U D S
int dr[5] = {0, 0, -1, 1, 0}; 
int dc[5] = {1, -1, 0, 0, 0};

int newgrid[20][20];

bool valid(int r, int c){
    return (0 <= r && r < n && 0 <= c && c < m && grid[r][c] != '#');
}

void bfs(int er, int ec){
    queue<pair<pair<int, int>, int>> q;
    q.push({{er,ec}, 0});
    dist[er][ec] = 0;
    while (!q.empty()){
        pair<pair<int, int>, int> p = q.front(); q.pop();
        int r = p.first.first;
        int c = p.first.second;
        int cst = p.second;
        for (int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (valid(nr, nc) && dist[nr][nc] > cst + 1){
                dist[nr][nc] = cst + 1;
                q.push({{nr, nc}, cst + 1});
            }
        }
    }
}


void rb(vector<pair<int, int>>& curPs, int i, int curT){
    // if (curPs.empty()){
    //     return;
    // }
    if (curT == t){
        ans = min(ans, nP - (int)curPs.size());
        return;
    }
    if (curPs.size() == i){
        // cout << curT << endl;
        // for (int r = 0; r < n; r++){
        //     for (int c = 0; c < m; c++){
        //         cout << newgrid[r][c];
        //     } cout << endl; } cout << endl;

        curPs.clear();
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++){
                if (newgrid[r][c] == 1){
                    // dont include those who are already at exits
                    if (grid[r][c] != 'E'){
                        curPs.push_back({r, c});
                    }
                    newgrid[r][c] = 0;
                }
            }
        }
        // curPs = newcurPs;
        rb(curPs, 0, curT+1);
        return;
    }
    int r = curPs[i].first;
    int c = curPs[i].second;
    // bool pushed = false;
    for (int k = 0; k < 5; k++){
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (valid(nr, nc) && (k==4 || dist[nr][nc] < dist[r][c]) && newgrid[nr][nc] == 0){
            // pushed = true;
            newgrid[nr][nc]++;
            rb(curPs, i+1, curT);
            newgrid[nr][nc]--;
        }
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;

    grid.resize(n);
    dist.resize(n);
    for (int i = 0; i < n; i++){
        grid[i].resize(m);
        dist[i].resize(m);
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'E'){
                exits.insert({i, j});
            }
            dist[i][j] = (int)1e9;
            if (grid[i][j] == 'P'){
                nP++;
            }
        }
    }

    // precompute optimal distance
    for (auto& [er, ec] : exits){
        bfs(er, ec);
    }

    // cout << n << " " << m << endl;
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    vector<pair<int, int>> curPs;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'P'){
                curPs.push_back({i, j});
            }
        }
    }

    // vector<vector<int>> newgrid(n, vector<int>(m, 0));
    rb(curPs, 0, 0);
    cout << ans << endl;
    return 0;
}