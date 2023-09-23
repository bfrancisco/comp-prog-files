#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ans = 1e18;
vector<vector<ll>> db;
vector<vector<ll>> mn;
int n, m;

void dfs(int row, bool buy, ll val){
    if (row >= n){
        ans = min(ans, val);
        return;
    }
    if (buy){
        if (val < mn[row][0]){
            mn[row][0] = val;
            dfs(row, false, val+db[row][0]);
        }
    }
    else{
        // selling
        for (int i = 1; i < db[row].size(); i++){
            if (val < mn[row][i]){
                mn[row][i] = val;
                dfs(row+i, true, val-db[row][i]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    db.resize(n);
    mn.resize(n);
    for (int i = 0; i < n; i++){
        db[i].resize(min(m, n-i) + 1);
        mn[i].resize(min(m, n-i) + 1);
        cin >> db[i][0];
        mn[i][0] = 1e18;
        for (int j = 1; j < min(m, n-i) + 1; j++){
            cin >> db[i][j];
            mn[i][j] = 1e18;
        }
    }
    
    dfs(0, true, 0ll);
    cout << ans << endl;

    return 0;
}