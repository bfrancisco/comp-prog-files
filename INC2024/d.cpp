#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int n, m;
vector<string> grid;
vector<>;

void solve(int sr, int sc, int K){
    int f_le, f_ri, f_top, f_bot;
    int time = 0;
    int treasures = (grid[sr-1][sc-1] == '1');
    if (K == treasures) { cout << 0 << endl; return; }

    for (int la = 1; la <= 1000; la++){
        f_le = max(sc - la, 0);
        f_ri = min(sc + la, m+1);
        f_top = max(sr - la, 0);
        f_bot = min(sr + la, n+1);

        cout << f_le << " " << f_ri << " " << f_top << " " << f_bot << endl;

        int cur_layer = 0;
        if (f_top > 0)  cur_layer += cumuRow[f_top+1] - cumuRow[f_top];
        if (f_bot <= n) cur_layer += cumuRow[f_bot] - cumuRow[f_bot-1];
        if (f_le > 0)   cur_layer += cumuCol[f_le+1] - cumuCol[f_le];
        if (f_ri <= m)  cur_layer += cumuCol[f_ri] - cumuCol[f_ri-1];
        if (f_le > 0 && f_top > 0)      cur_layer -= (grid[f_le-1][f_top-1] == '1');
        if (f_le > 0 && f_bot <= n)     cur_layer -= (grid[f_le-1][f_bot-1] == '1');
        if (f_ri <= m && f_top > 0)     cur_layer -= (grid[f_ri-1][f_top-1] == '1');
        if (f_ri <= m && f_bot <= n)    cur_layer -= (grid[f_ri-1][f_bot-1] == '1');
        treasures += cur_layer;
        
        cout << la << " : " << cur_layer << endl;

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
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }

    cumuRow.resize(n+1);
    cumuCol.resize(m+1);
    for (int i = 1; i <= n; i++){
        int c = 0;
        for (int j = 1; j <= m; j++){
            c += (grid[i-1][j-1] == '1');
        }
        cumuRow[i] = cumuRow[i-1] + c;
    }
    for (int j = 1; j <= m; j++){
        int c = 0;
        for (int i = 1; i <= n; i++){
            c += (grid[i-1][j-1] == '1');
        }
        cumuCol[j] = cumuCol[j-1] + c;
    }

    cout << "Row: "; for (auto e : cumuRow) cout << e << " "; cout << endl;
    cout << "Col: "; for (auto e : cumuCol) cout << e << " "; cout << endl;

    int q; cin >> q;
    while (q--){
        int sr, sc, K;
        cin >> sr >> sc >> K;
        solve(sr, sc, K);
    }
    
    return 0;
}