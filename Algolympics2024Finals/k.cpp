#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int R, C;

bool valid(int r, int c){
    return (0 <= r && r < R && 0 <= c && c < C);
}

void solve(){
    cin >> R >> C;
    int r, c, k, nr, nc, sr, sc, er, ec;
    vector<vector<ll>> grid(R, vector<ll>(C));
    for (r = 0; r < R; r++){
        for (c = 0; c < C; c++){
            cin >> grid[r][c];
        }
    }
    cin >> sr >> sc >> er >> ec;
    sr--; sc--;
    er--; ec--;

    vector<vector<ll>> entry(R, vector<ll>(C, 0));
    for (r = 0; r < R; r++){
        for (c = 0; c < C; c++){
            for (k = 0; k < 4; k++){
                nr = r + dr[k];
                nc = c + dc[k];
                if (!valid(nr,nc) || (nr == sr && nc == sc)) continue;
                entry[r][c] = max(entry[r][c], grid[nr][nc]);
            }
        }
    }

    for (auto &row : entry){
        for (auto e : row) cout << e << " "; cout << endl;
    }
    
    priority_queue<pair<ll, pair<int, int>>> q;
    q.push({-grid[sr][sc], {sr, sc}});

    grid[sr][sc] = 0;
    ll p, np;
    ll mxp = 0;
    while (!q.empty()){
        auto &pp = q.top(); q.pop();
        p = -pp.first;
        r = pp.second.first;
        c = pp.second.second;
        // cout << p << " " << r << " " << c << endl;
        mxp = max(mxp, p);
        if (r == er && c == ec){
            cout << "UNOBTANIUM" << endl;
            return;
        }

        for (k = 0; k < 4; k++){
            nr = r + dr[k];
            nc = c + dc[k];
            if (!valid(nr, nc)) continue;
            
            np = mxp + grid[nr][nc];
            grid[nr][nc] = 0;
            if (np >= entry[nr][nc]){
                q.push({-np, {nr, nc}});
            }
        }
    }

    cout << "UNOBTAINABLE" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}