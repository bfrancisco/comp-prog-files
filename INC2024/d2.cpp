#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int R, C;
vector<string> grid;
vector<vector<int>> cumuH, cumuV;

void solve(int r, int c, int K){
    int f_le, f_ri, f_top, f_bot;
    int time = 0;
    int treasures = (grid[r-1][c-1] == '1');
    if (K == treasures) { cout << 0 << endl; return; }

    for (int la = 1; la <= 1000; la++){
        f_le = c - la;
        f_ri = c + la;
        f_top = r - la;
        f_bot = r + la;

        // cout << f_le << " " << f_ri << " " << f_top << " " << f_bot << endl;

        int cur_layer = 0;
        int top, bot, lef, rig;
        top = lef = bot = rig = 0;
        if (f_top > 0) top = cumuH[f_top][min(f_ri, C)] - cumuH[f_top][max(f_le-1, 0)];
        if (f_bot <= R) bot = cumuH[f_bot][min(f_ri, C)] - cumuH[f_bot][max(f_le-1, 0)];
        if (f_le > 0) lef = cumuV[min(f_bot, R)][f_le] - cumuV[max(f_top-1, 0)][f_le];
        if (f_ri <= C) rig = cumuV[min(f_bot, R)][f_ri] - cumuV[max(f_top-1, 0)][f_ri];
        
        // cout << top << " " << bot << " " << lef << " " << rig << endl;
        cur_layer += top + bot + lef + rig;
        if (f_le > 0 && f_top > 0){
            cur_layer -= (grid[f_top-1][f_le-1] == '1');
            // cout << "TOPLEFT" << endl;
        }  
        if (f_le > 0 && f_bot <= R){
            cur_layer -= (grid[f_bot-1][f_le-1] == '1');
            // cout << "BOTLEFT" << endl;
        } 
        if (f_ri <= C && f_top > 0){
            cur_layer -= (grid[f_top-1][f_ri-1] == '1');
            // cout << "TOPRIG" << endl;
        } 
        if (f_ri <= C && f_bot <= R){
            cur_layer -= (grid[f_bot-1][f_ri-1] == '1');
            // cout << "BOTRIG" << endl;
        }
        
        treasures += cur_layer;
        
        // cout << la << " : " << cur_layer << endl;

        time += 2*la*cur_layer;
        if (treasures >= K){
            time -= (treasures - K) * 2 * la;
            break;
        }

    }

    cout << time << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> R >> C;
    grid.resize(R);
    for (int i = 0; i < R; i++){
        cin >> grid[i];
    }

    cumuV.assign(R+1, vector<int>(C+2, 0));
    cumuH.assign(R+1, vector<int>(C+2, 0));
    for (int c = 1; c <= C; c++){
        for (int r = 1; r <= R; r++){
            cumuV[r][c] = cumuV[r-1][c] + (grid[r-1][c-1] == '1');
        }
    }
    for (int r = 1; r <= R; r++){
        for (int c = 1; c <= C; c++){
            cumuH[r][c] = cumuH[r][c-1] + (grid[r-1][c-1] == '1');
        }
    }

    // for (int r = 0; r <= R; r++){
    //     for (int c = 0; c <= C; c++)
    //         cout << cumuV[r][c] << " "; cout << endl;
    // }
    // cout << endl;
    // for (int r = 0; r <= R; r++){
    //     for (int c = 0; c <= C; c++)
    //         cout << cumuH[r][c] << " "; cout << endl;
    // }

    // for (int r = 0; r < R; r++){
    //     for (int c = 0; c < C; c++){
    //         cout << grid[r][c];
    //     }
    //     cout << endl;
    // }

    int q; cin >> q;
    while (q--){
        int sr, sc, K;
        cin >> sr >> sc >> K;
        solve(sr, sc, K);
    }
    
    return 0;
}