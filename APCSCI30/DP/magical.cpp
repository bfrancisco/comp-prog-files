// https://atcoder.jp/contests/abc190/tasks/abc190_e

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> adj;
vector<int> special;
vector<unordered_map<int,int>> dst; // min from n to special[k]
int dp[17][1<<17];

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
    int n, m; cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k; cin >> k;
    special.resize(k);
    for (int i = 0; i < k; k++)
        cin >> special[k];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            dst[i][special[j]] = -1;
        }
    }
    for (int i = 0; i < k; i++){
        bfs(k);
    }
    
    // check if connected
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            if (dst[i][special[j]] == -1){
                cout << -1 << endl;
                return;
            }
        }
    }

    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();    
    return 0;
}