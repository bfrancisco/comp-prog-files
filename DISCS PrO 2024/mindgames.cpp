#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int grid[2001][2001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<set<int>> R(n+1), C(n+1);
    map<int, pair<ll, ll>> db;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
            R[i].insert(grid[i][j]);
            C[j].insert(grid[i][j]);
            db[grid[i][j]] = {0,0};
        }
    }

    for (auto r : R){
        for (auto e : r)
            db[e].first++;
    }
    for (auto c : C){
        for (auto e : c)
            db[e].second++;
    }

    ll ans = 0;
    for (auto &[v, p] : db){
        ans += p.first*p.second;
    }
    cout << ans << endl;

    return 0;
}