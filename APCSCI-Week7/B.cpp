#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define INF 10000000007
ll n;
vector<vector<pair<ll, ll>>> graph;
ll ans = 0;
vector<ll> pplants;
vector<pair<ll, ll>> connections;

void primify(ll start){
    priority_queue<pair<ll, pair<ll, ll>>> pq;
    
    vector<bool> vis(n+1, false);
    vis[start] = true;

    // fill up pq with all edges containing vertex start
    for (auto &[v, w] : graph[start]){
        pq.push({(-1LL) * w, {start, v}});    // swap weight and vertex fuck
    }

    while(!pq.empty()){
        auto edge = pq.top(); pq.pop();
        ll u = edge.second.first;
        ll v = edge.second.second;
        ll weight = edge.first * (-1LL);
        //cout << weight << endl;
        if (vis[v]) continue;
        vis[v] = true;

        if (u == 0){
            pplants.push_back(v);
        }
        else{
            connections.push_back({u, v});
        }
        ans += weight;

        for (auto &[next, w] : graph[v]){
            if (!vis[next]) pq.push({(-1LL) * w, {v, next}});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    vector<pair<ll, ll>> xy(n);
    graph.resize(n+1);
    vector<ll> k(n);
    
    for (ll i = 0; i < n; i++){
        cin >> xy[i].first >> xy[i].second;
    }
    for (ll i = 1; i <= n; i++){
        ll c; cin >> c;
        graph[0].push_back({i, c});
        graph[i].push_back({0, c});
    }
        
    for (ll i = 0; i < n; i++){
        cin >> k[i];
    }

    for (ll i = 0; i < n; i++){
        for (ll j = i+1; j < n; j++){
            ll x1 = xy[i].first, y1 = xy[i].second;
            ll x2 = xy[j].first, y2 = xy[j].second;
            ll wirecost = (k[i] + k[j]) * (abs(x1-x2) + abs(y1-y2));
            graph[i+1].push_back({j+1, wirecost});
            graph[j+1].push_back({i+1, wirecost});
        }
    }

    primify(0);

    cout << ans << endl;
    cout << pplants.size() << endl;
    for (auto x : pplants) cout << x << " ";
    cout << endl;
    cout << connections.size() << endl;
    for (auto &[u, v] : connections) cout << u << " " << v << endl;
    return 0;
}