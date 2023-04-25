#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n;
    ll k, c;
    cin >> n >> k >> c;

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dist(n+1);
    dist[1] = 0;
    vector<bool> vis(n+1, false);
    vis[1] = true;
    queue<int> q;
    q.push(1);
    ll far = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (vis[v]) continue;
            dist[v] = dist[u] + k;
            far = max(far, dist[v]);
            vis[v] = true;
            q.push(v);
        }
    }

    ll ans = -1;
    vector<bool> vis2(n+1, false);
    vis[1] = true;
    queue<int> w;
    w.push(1);
    while (!w.empty()){
        int u = w.front();
        w.pop();
        int step = dist[u]/k;
        ans = max(ans, far - dist[u] + step*c);
        for (auto v : adj[u]){
            if (vis2[v]) continue;
            vis2[v] = true;
            w.push(v);
        }
    }

    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) solve();


    return 0;
}