#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<pair<ll, ll>>> adj;
map<ll, ll> prefix; // from k
int n;

void bfs(ll start){
    queue<pair<ll, ll>> q;
    q.push({start, 0});
    vector<bool> vis(n+1, false);
    vis[start] = true;
    prefix[start] = 0;
    while (!q.empty()){
        ll u = q.front().first;
        ll before = q.front().second;
        // cout << "data: " << u << " " << before << endl;
        q.pop();
        for (auto e : adj[u]){
            ll v = e.first;
            ll w = e.second;
            if (vis[v]) continue;
            prefix[v] = before + w;
            vis[v] = true;
            q.push({v, prefix[v]});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    adj.resize(n+1);

    for (int i = 0; i < n-1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int q;
    ll k;
    cin >> q >> k;

    bfs(k);
    // for (ll i = 1; i <= n; i++){
    //     cout << prefix[i] << endl;
    // }
    for (int i = 0; i < q; i++){
        ll u, v;
        cin >> u >> v;
        cout << prefix[u] + prefix[v] << endl;
    }


    return 0;
}   