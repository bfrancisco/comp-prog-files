// https://cses.fi/problemset/task/1130

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> adj;
int ans = 0;

int rec(int u, int prev){
    // return 0 if not paired, 1 if paired

    int andd = 1;
    for (auto v : adj[u]){
        if (v == prev) continue;
        andd &= rec(v, u);
    }

    ans += (1-andd);
    return (1-andd);

}
void solve(){
    int n; cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rec(0, -1);

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();    
    return 0;
}