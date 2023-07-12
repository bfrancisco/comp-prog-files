#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<pair<int, pair<ll, ll>>>> adj;
int n, m;

ll dijkstra(int s){
    priority_queue<pair<ll, int>> pq;
    vector<ll> dist(n+1, 1e15);
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()){
        pair<ll, int> e = pq.top();
        pq.pop();
        ll t = -e.first;
        int u = e.second;
        if (t > dist[u]) continue;
        // cout << "vertex: " << u << endl; 
        for (auto vcd : adj[u]){
            int v = vcd.first;
            ll c = vcd.second.first, d = vcd.second.second;
            ll newt = 1e15;
            // most efficient is somewhere sqrt(d) +- 1
            for (ll denom = sqrt(d)-1, cnt = 3; cnt > 0; denom++, cnt--){
                if (denom < 0) continue;
                
                if (denom >= t+1){
                    newt = min(newt, t + c + (ll)(d/denom) + (denom - (t+1)));
                }
                else{
                    newt = min(newt, t + c + (ll)(d/(t+1)));
                }
            }
            // cout << "next: " << v << "  newt: " << newt << endl;
            if (newt < dist[v]){
                dist[v] = newt;
                pq.push({-newt, v});
            }
        }
    }

    return (dist[n] == 1e15 ? -1 : dist[n]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++){
        int a, b; ll c, d;
        cin >> a >> b >> c >> d;
        if (a==b) continue;
        adj[a].push_back({b, {c, d}});
        adj[b].push_back({a, {c, d}});
    }
    
    cout << dijkstra(1) << endl;

    return 0;
}