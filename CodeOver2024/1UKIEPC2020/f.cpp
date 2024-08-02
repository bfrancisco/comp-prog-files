#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int N, M, P, G;
vector<int> starting;
vector<vector<pair<int, ll>>> adj;
map<int, vector<ll>> dist;

ll INF = LLONG_MAX;

vector<ll> dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<ll> d(N+1, INF);
    q.push({0, s});
    d[s] = 0;
    while (!q.empty()){
        auto [mw, u] = q.top();
        q.pop();
        if (d[u] < mw) continue;
        d[u] = mw;
        for (auto [v, w] : adj[u]){
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
            
        }
    }
    return d;
}

int main(){

    cin >> N >> M >> P >> G;
    starting.resize(P+1);
    adj.resize(N+1);

    for (int i = 1; i <= P; i++){
        cin >> starting[i];
    }
    
    for (int i = 0; i < M; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int p = 1; p <= P; p++){
        dist[starting[p]] = dijkstra(starting[p]);
        // cout << "FROM " << u << endl;
        // for (int i = 1; i <= N; i++){
        //     cout << "to " << i << " : " << dist[u][i] << endl;
        // }
        // cout << endl;
    }
    dist[1] = dijkstra(1);

    ll ans = INF;
    for (int grp = 1; grp <= N; grp++){
        ll cost = 0;
        for (int p = 1; p <= P; p++){
            int start = starting[p];
            ll uToGrp = dist[start][grp];
            ll uTo1 = dist[start][1];
            ll oneToGrp = dist[1][grp];
            
            if (uTo1 == oneToGrp + uToGrp){
                // can go to grp
                cost += min(uToGrp + G, uTo1);
            }
            else{
                cost += uTo1;
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;

    return 0;
}