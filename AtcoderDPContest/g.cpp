#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<int>> adj;
map<int, int> indegs;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n);
    dp.assign(n, 0);
    for (int i = 0; i < n; i++) indegs[i]=0;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        indegs[v]++;
    }

    queue<int> q;
    for (auto &[u, indeg] : indegs){
        if (indeg==0){
            q.push(u);
        }
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (auto v : adj[u]){
            dp[v] = max(dp[v], dp[u]+1);
            indegs[v]--;
            if (indegs[v]==0) q.push(v);
        }
    }

    int ans = 0;
    for (auto x : dp) ans = max(ans, x);
    cout << ans << endl;

    return 0;
}