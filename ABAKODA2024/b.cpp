#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int R, C;
vector<vector<int>> grid;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

int valid(int r, int c){
    return (0 <= r && r < R && 0 <= c && c < C);
}

ll dfs(int r, int c, int region){
    grid[r][c] = region;
    int ret = 2;
    for (int k = 0; k < 4; k++){
        int nr, nc;
        nr = r + dr[k];
        nc = c + dc[k];
        if (valid(nr, nc) && grid[nr][nc] == 0){
            ret += dfs(nr, nc, region);
        }
    }

    return ret;
}

int main(){
    cin >> R >> C;
    grid.assign(R, vector<int>(C, -1));
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            char v; cin >> v;
            if (v == '#') grid[r][c] = 0;
        }
    }

    int region = 1;
    map<int, int> rscore;
    rscore[-1] = 0;
    int ans = 0;
    bool soloExist = false;
    bool allDot = true;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (grid[r][c] == 0){
                allDot = false;
                rscore[region] = dfs(r, c, region);
                if (rscore[region] > 2){
                    ans += rscore[region];
                }
                else{
                    soloExist = true;
                }
                region++;
            }
        }
    }

    int ad = 0;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (grid[r][c] != -1) continue;
            int score = 0;
            int freq = 0;
            for (int k = 0; k < 4; k++){
                int nr, nc;
                nr = r + dr[k];
                nc = c + dc[k];
                if (valid(nr, nc) && rscore[grid[nr][nc]] == 2){
                    freq++;
                }
            }
            if (freq) ad = max(ad, freq+1);

        }
    }
    
    // for (auto [reg, sc] : rscore){
    //     cout << reg << " " << sc << endl;
    // }
    // cout << endl;

    // for (int r = 0; r < R; r++){
    //     for (int c = 0; c < C; c++){
    //         cout << grid[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << ans << " " << ad << endl;

    if (allDot) cout << 0 << endl;
    else if (soloExist) cout << ans + ad*2 << endl;
    else cout << ans + 2 << endl;

    return 0;
}