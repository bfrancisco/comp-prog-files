#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, M, T, D;
set<int> stations;
vector<vector<pair<int, ll>>> adj;
vector<map<int, ll>> dist;

ll MX = 1e11;

void dijkstra(int s){
    // distance, fuel, node, prev
    priority_queue<pair<pair<ll, int>, pair<int, int>>, 
                    vector<pair<pair<ll, int>, pair<int, int>>>, 
                    greater<>> q;
    
    q.push({{0, D}, {s, -1}});
    dist[s][D] = 0;

    vector<int> vis(N+1, 0);
    vis[s]++;

    while (!q.empty()){
        auto [plli, pii] = q.top();
        q.pop();
        ll d = plli.first;
        int fuel = plli.second;
        int u = pii.first;
        int prev = pii.second;
        // cout << u << " " << prev << " " << fuel << endl;

        for (auto &[v, w] : adj[u]){
            if (prev == v) continue;
            if (vis[v] > 100) continue;
            int remain = fuel - w;
            
            if (remain < 0) continue;
            if (stations.find(v) != stations.end()){
                remain = D;
            }
            if (dist[v].find(remain) == dist[v].end()){
                dist[v][remain] = dist[u][fuel] + w;
                vis[v]++;
                q.push({{dist[v][remain], remain}, {v, u}});
            }
            else if (dist[v][remain] >= dist[u][fuel] + w){
                dist[v][remain] = dist[u][fuel] + w;
                vis[v]++;
                q.push({{dist[v][remain], remain}, {v, u}});
            }

        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> T >> D;
    for (int i = 0; i < T; i++){
        int x; cin >> x;
        stations.insert(x);
    }

    adj.resize(N+1);
    dist.resize(N+1);
    for (int i = 0; i < M; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        if (w > D) continue;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dijkstra(1);
    ll ans = 1e11;

    for (auto mp : dist[N]){
        ans = min(ans, mp.second);    
    }

    if (ans == (ll)1e11) cout << "stuck" << endl;
    else cout << ans << endl;


    return 0;
}