#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, k; cin >> n >> k;
    vector<vector<ll>> grid(n, vector<ll>(n));
    vector<vector<pair<ll, ll>>> numCoords(k+1);
    vector<vector<ll>> min_dist(n, vector<ll>(n, 1e18)); // min dist to get to grid[i][j]
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            cin >> grid[i][j];
            numCoords[grid[i][j]].push_back({i, j});
        }
    }
    
    for (auto &[r, c] : numCoords[1]){
        min_dist[r][c] = 0;
    }

    // iterate from 2 to k using numCoords
    // sweep thru rows and cols

    for (ll x = 2; x <= k; x++){
        // save min of previous k per row and col
        vector<ll> mn_row(n, 1e18), mn_col(n, 1e18);
        for (auto &[r, c] : numCoords[x-1]){
            mn_row[r] = min(mn_row[r], min_dist[r][c]);
            mn_col[c] = min(mn_col[c], min_dist[r][c]);
        }

        for (auto &[r, c] : numCoords[x]){
            // sweep thru rows
            for (ll row = 0; row < n; row++){
                min_dist[r][c] = min(min_dist[r][c], mn_row[row] + (row-r)*(row-r));
            }
            // sweep thru cols
            for (ll col = 0; col < n; col++){
                min_dist[r][c] = min(min_dist[r][c], mn_col[col] + (col-c)*(col-c));
            }
        }
    }

    ll ans = 1e18;
    for (auto &[r, c] : numCoords[k]){
        ans = min(ans, min_dist[r][c]);
    }

    if (ans == 1e18) cout << -1 << endl;
    else cout << ans << endl;

    return 0;   
}