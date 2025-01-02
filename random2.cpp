#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll process(int R, int C, vector<vector<ll>>& grid){
    map<int, vector<ll>> db;

    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            db[grid[r][c]].push_back(c);
        }
    }

    for (auto& [color, vc] : db){
        sort(db[color].begin(), db[color].end(), greater<ll>());
    }

    ll ret = 0;
    for (auto& [color, vc] : db){
        // cout << "Color: " << color << endl;

        int sz = vc.size();
        if (sz == 1) continue;

        // for (auto e : vc) cout << e << " "; cout << endl; 

        for (int i = 0, mul = sz-1; i < sz/2; i++, mul -= 2){
            ret += vc[i] * mul;
            // cout << "\t" << vc[i] << " * " << mul << " = " << vc[i] * mul << endl;
        }
        // cout << "neg" << endl;
        for (int i = sz/2, mul = (sz%2 ? 0 : 1); i < sz; i++, mul += 2){
            ret -= vc[i] * mul;
            // cout << "\t" << vc[i] << " * " << mul << " = " << vc[i] * mul << endl;

        }
    }

    // cout << "ret: " << ret << endl;
    return ret;
}

void solve(){  
    int R, C;
    cin >> R >> C;
    vector<vector<ll>> grid(vector<vector<ll>>(R, vector<ll>(C, 0)));
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            cin >> grid[r][c];
        }
    }

    vector<vector<ll>> rev(vector<vector<ll>>(C, vector<ll>(R, 0)));
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            rev[c][r] = grid[r][c];
        }
    }

    ll ans = 0;
    ans += process(R, C, grid);
    ans += process(C, R, rev);

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t = 1;
    // int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}