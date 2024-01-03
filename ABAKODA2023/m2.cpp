#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int R, C, K;
vector<vector<ll>> alice, cindy;
set<pair<int, int>> boards; // used to eliminate equivalent board configs
// <bitset for verts, bitset for horis>. bitset is at most 2^31-1

//            UL, DL, UR, DR, U, D            
int vdr[6] = {-1, 1, -1, 1, -2, 2};
int vdc[6] = {-1, -1, 1, 1, 0, 0};
//            UL, UR, DL, DR, L, R
int hdr[6] = {-1, -1, 1, 1, 0, 0};
int hdc[6] = {-1, 1, -1, 1, -2, 2};

int dr[4] = {0, 0, 2, -2};
int dc[4] = {2, -2, 0, 0};

ll ans;
int cnt;

bool is_valid(int r, int c){
    return (0 < r && r < R*2 && 0 < c && c < C*2);
}

bool is_border(int r, int c){
    return (r==1 || r==R*2-1 || c==1 || c==C*2-1);
}

int conv_to_bit(int r, int c){
    // assert((r&1) != (c&1));
    // if vertical
    if (c%2==0) return (c/2) + (int)(r/2)*5 - 1;
    // if horizontal    
    else        return (r/2) + (int)(c/2)*5 - 1;
}

bool is_visited(int r, int c, int vert, int hori){
    if (c%2==0){
        return (vert & (1 << conv_to_bit(r, c)));
    }
    else{
        return (hori & (1 << conv_to_bit(r, c)));
    }
}

// r, c, turns, bitset verts, bit set horis, moves, prev vert, prev hori
void rec(int r, int c, int k, int vert, int hori, int pv, int ph, int moves){
    // if (moves > 3) return;
    // cout << r << " " << c << " " << moves << endl;
    if (k > K) return;

    if (moves > 1 && is_border(r, c)){
        cnt++;
        pair<int, int> config = {vert, hori};
        if (boards.find(config) != boards.end()) return;
        boards.insert(config);

        // calculations
        ll score1 = 0; // alice - 1st region, cindy - 2nd region
        ll score2 = 0; // vice versa

        vector<vector<int>> vis(R*2+1, vector<int>(C*2+1, 0));
        int regions = 0;
        for (int i = 1; i < R*2; i+=2){
            for (int j = 1; j < C*2; j+=2){
                if (vis[i][j]) continue;
                regions++;
                queue<pair<int, int>> q;
                vis[i][j] = 1;
                q.push({i, j});
                while (!q.empty()){
                    auto [rr, cc] = q.front();
                    q.pop();
                    if (regions == 1){
                        score1 += alice[rr][cc];
                        score2 += cindy[rr][cc];
                    }
                    else if (regions == 2){
                        score1 -= cindy[rr][cc];
                        score2 -= alice[rr][cc];
                    }
                    for (int z = 0; z < 4; z++){
                        int nrr = rr + dr[z];
                        int ncc = cc + dc[z];
                        if (!(0 < nrr && nrr < R*2 && 0 < ncc && ncc < C*2)) continue;
                        if (vis[nrr][ncc] == 1) continue;
                        
                        // the grid cell that is jumped
                        int brr = rr + dr[z]/2;
                        int bcc = cc + dc[z]/2;
                        if (bcc%2==0){
                            if (vert & (1 << conv_to_bit(brr, bcc))) continue;
                        }
                        else{
                            if (hori & (1 << conv_to_bit(brr, bcc))) continue;
                        }

                        vis[nrr][ncc] = 1;
                        q.push({nrr, ncc});
                    }
                }
            }
        }

        if (regions != 2) return;
        ans = min(ans, abs(score1));
        ans = min(ans, abs(score2));
        return;
    }

    for (int i = 0; i < 6; i++){
        int nr, nc;
        if (c%2==0){
            if (i%2==0 && pv == -1) continue;
            else if (i%2 && pv == 1) continue;
            nr = r + vdr[i];
            nc = c + vdc[i];
        }
        else{
            if (i%2==0 && ph == -1) continue;
            else if (i%2 && ph == 1) continue;
            nr = r + hdr[i];
            nc = c + hdc[i];
        }
        if (!is_valid(nr, nc) || is_visited(nr, nc, vert, hori)) continue;

        // vertical
        if (c%2==0){
            // turn
            if (i < 2)
                rec(nr, nc, k+1, vert, (hori | (1 << conv_to_bit(nr, nc))), 0, 1, moves+1);
            else if (i < 4)
                rec(nr, nc, k+1, vert, (hori | (1 << conv_to_bit(nr, nc))), 0, -1, moves+1);
            // straight
            else if (i == 4)
                rec(nr, nc, k, (vert | (1 << conv_to_bit(nr, nc))), hori, 1, 0, moves+1);
            else
                rec(nr, nc, k, (vert | (1 << conv_to_bit(nr, nc))), hori, -1, 0, moves+1);
        }
        else{
            if (i < 2)
                rec(nr, nc, k+1, (vert | (1 << conv_to_bit(nr, nc))), hori, 1, 0, moves+1);
            else if (i < 4)
                rec(nr, nc, k+1, (vert | (1 << conv_to_bit(nr, nc))), hori, -1, 0, moves+1);
            else if (i == 4)
                rec(nr, nc, k, vert, (hori | (1 << conv_to_bit(nr, nc))), 0, 1, moves+1);
            else
                rec(nr, nc, k, vert, (hori | (1 << conv_to_bit(nr, nc))), 0, -1, moves+1);
        }
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cnt = 0;
    ans = 1e18;
    cin >> R >> C >> K;
    alice.assign(R*2+1, vector<ll>(C*2+1, 0));
    cindy.assign(R*2+1, vector<ll>(C*2+1, 0));
    for (int r = 1; r <= 2*R; r+=2){
        for (int c = 1; c <= 2*C; c+=2){
            cin >> alice[r][c];
        }
    }
    for (int r = 1; r <= 2*R; r+=2){
        for (int c = 1; c <= 2*C; c+=2){
            cin >> cindy[r][c];
        }
    }

    // cout << conv_to_bit(1, 2) << endl;
    // cout << is_visited(1, 2, 1, 1) << endl;
    for (int c = 2; c < C*2; c+=2){
        rec(1, c, 1, (1 << conv_to_bit(1, c)), 0, -1, 0, 1);
    }
    for (int c = 2; c < C*2; c+=2){
        rec(R*2-1, c, 1, (1 << conv_to_bit(R*2-1, c)), 0, 1, 0, 1);
    }
    for (int r = 2; r < R*2; r+=2){
        rec(r, 1, 1, 0, (1 << conv_to_bit(r, 1)), 0, -1, 1);
    }
    for (int r = 2; r < R*2; r+=2){
        rec(r, C*2-1, 1, 0, (1 << conv_to_bit(r, C*2-1)), 0, 1, 1);
    }

    // cout << "# of boards: " << boards.size() << endl;
    // cout << "# of generated boards: " << cnt << endl;
    cout << ans << endl;
    
    return 0;
}