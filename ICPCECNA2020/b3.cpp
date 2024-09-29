#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MXLEN = 105;
const int MXSZ = 15;
const int MXDIR = 9;
int R, C;
vector<vector<char>> grid;
string s;
int K;

// ith letter, r, c, k, dir
int dp[MXLEN][MXSZ][MXSZ][MXLEN][MXDIR];

int dr[9] = {0, -1, -1, -1,  0 , 0,  1 , 1, 1};
int dc[9] = {0, -1, 0 ,  1,  -1, 1,  -1, 0, 1};
int debug = 0;

bool valid(int r, int c){
    return 0 <= r && r < R && 0 <= c && c < C;
}

int rec(int i, int r, int c, int k, int dir){
    if (k == K && i == (int)s.size()){
        // cout << r << " " << c << " " << dir << endl;
        return 1;
    } 
    if (k > K || i > (int)s.size() || k >= (int)s.size()) return 0;
    
    if (dp[i][r][c][k][dir] != -1) return dp[i][r][c][k][dir]; 

    dp[i][r][c][k][dir] = 0;
    for (int d = 1; d <= 8; d++){
        int nr, nc, nk;
        nr = r + dr[d];
        nc = c + dc[d];
        nk = k + (dir==0 || dir==d ? 0 : 1);
        if (valid(nr, nc) && s[i] == grid[nr][nc]){
            dp[i][r][c][k][dir] |= rec(i+1, nr, nc, nk, d);
        }
    }

    return dp[i][r][c][k][dir];
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

    for (int a = 0; a < MXLEN; a++)
    for (int b = 0; b < MXSZ; b++)
    for (int c = 0; c < MXSZ; c++)
    for (int d = 0; d < MXLEN; d++)
    for (int e = 0; e < MXDIR; e++)
        dp[a][b][c][d][e] = -1;

    int good = 0;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (grid[r][c] != s[0]) continue;

            good |= rec(1, r, c, 0, 0);
        }
    }

    cout << (good ? "YES" : "NO") << endl;
    
    // for (int a = 0; a < MXLEN; a++)
    // for (int b = 0; b < MXSZ; b++)
    // for (int c = 0; c < MXSZ; c++)
    // for (int d = 0; d < MXLEN; d++)
    // for (int e = 0; e < MXDIR; e++)
    //     if (dp[a][b][c][d][e] == 1){
    //         cout << a << " " << b << " " << c << " " << d << " " << e << endl; 
    //     }
    return 0;
}