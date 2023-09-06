// https://atcoder.jp/contests/abc190/tasks/abc190_e

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> adj;
vector<int> special;
vector<unordered_map<int,int>> dst; // min from n to special[k]
int dp[17][1<<17];
int n, m, k; 

int rec(int u, int done, int val){
    if (dp[u][done] != 1e9){
        return dp[u][done];
    }

    for (int i = 0; i < k; i++){
        if (u == special[i] || (done & (1<<i))){
            continue;
        }
        dp[u][done] = min(dp[u][done], val + rec(special[i], done | (1<<i), dst[u][special[i]]));
    }

    return dp[u][done];
}

void bfs(int s){
    queue<pair<int,int>> q;
    unordered_set<int> visited;
    q.push({s, 0});
    visited.insert(s);
    dst[s][s] = 0;
    while (!q.empty()){
        auto [u, d] = q.front(); q.pop();
        for (auto v : adj[u]){
            if (visited.find(v) == visited.end()){
                dst[v][s] = d+1;
                visited.insert(v);
                q.push({v, d+1});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "done uv" << endl;
    cin >> k;
    special.resize(k);
    for (int i = 0; i < k; i++){
        cin >> special[i];
        special[i]--;
    }
        

    cout << "done iunput" << endl;
    dst.resize(n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            dst[i][special[j]] = -1;
        }
    }
    cout << "done dst" << endl;
    for (int i = 0; i < k; i++){
        bfs(special[i]);
    }
    cout << "done bfs" << endl;

    // check if connected
    for (int i = 0; i < n; i++){
        cout << i << endl;
        for (int j = 0; j < k; j++){
            cout << "  " << j << endl;
            if (dst[i][special[j]] == -1){
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << "conek" << endl;

    int ans = 1e9;
    memset(dp, 1e9, sizeof dp);
    for (int i = 0; i < k; i++){
        ans = min(ans, rec(special[i], 0, 0));
        cout << i << " " <<  ans << endl;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();    
    return 0;
}