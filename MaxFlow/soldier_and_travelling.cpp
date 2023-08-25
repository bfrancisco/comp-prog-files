// https://codeforces.com/problemset/problem/546/E

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
    size_t i; // index at edges
    int v, c, f; // directed to v, capacity, flow
    int residue() { return c - f; }
};

struct flow_network {
    int n, s, t;
    vector<edge> edges;  // even indeces are forward flows, e_i+1 are reverse flows.
    vector<vector<int>> adj; // stores index pointing in edges
    vector<int> parent;

    flow_network(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        parent.resize(n);
    }

    void add_edge(int u, int v, int cap) {
        edges.push_back({edges.size(), v, cap, 0});
        adj[u].push_back((int)edges.size()-1);
        edges.push_back({edges.size(), u, 0, 0}); // reverse
        adj[v].push_back((int)edges.size()-1);
    }

    bool aug_path() {
        for (int i=0; i<n; i++) parent[i] = -1;
        parent[s] = s;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            // cout << "Pop: " << u << endl;
            if (u == t) break;
            for (auto ind : adj[u]){
                edge& e = edges[ind];
                // cout << e.i << " " << e.v << endl;
                if (e.residue() > 0 && parent[e.v] == -1) {
                    parent[e.v] = e.i;
                    q.push(e.v);
                }
            }
        }
        return parent[t] != -1;
    };

    int augment() {
        int bottleneck = numeric_limits<int>::max();
        for (int v = t; v != s; v = edges[parent[v] ^ 1].v) {
            bottleneck = min(bottleneck, edges[parent[v]].residue());
        }
        for (int v = t; v != s; v = edges[parent[v] ^ 1].v) {
            edges[parent[v]].f += bottleneck;
            edges[parent[v] ^ 1].f -= bottleneck;
        }
        return bottleneck;
    }

    int calc_max_flow() {
        int flow = 0;
        while (aug_path()){
            flow += augment();
        }
        return flow;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n+1), b(n+1), sd(n+1);
    int balanced = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) { sd[i] = b[i]-a[i]; balanced += sd[i]; }

    if (balanced != 0) { cout << "NO" << endl; return 0; }

    flow_network fn(1 + n + 1, 0, n+1);
    
    for (int u = 1; u <= n; u++){
        if (sd[u] > 0) fn.add_edge(u, n+1, sd[u]);
        else if (sd[u] < 0) fn.add_edge(0, u, -sd[u]);
    }

    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        fn.add_edge(u, v, 1e9);
        fn.add_edge(v, u, 1e9);
    }

    int x = fn.calc_max_flow();

    int good = 1;
    vector<vector<int>> out(n+1, vector<int>(n+1, 0));
    for (int u = 1; u <= n; u++){
        if (sd[u] > 0){
            for (auto ind : fn.adj[u]){
                edge& e = fn.edges[ind];
                if (e.v != n+1) continue;
                if (e.residue() != 0) { 
                    good = 0;
                    break;
                }

            }
        }
    }
    for (auto ind : fn.adj[0]){
        edge& e = fn.edges[ind];
        if (e.residue() != 0) { good = 0; break; }
    }

    if (!good) { cout << "NO" << endl; return 0; }

    for (int u = 1; u <= n; u++){
        for (auto ind : fn.adj[u]){
            if (ind%2) continue;
            edge& e = fn.edges[ind];
            if (e.v > n || e.v < 1) continue;
            out[u][e.v] = e.f;
        }
        if (sd[u] > 0) out[u][u] = a[u];
        else if (sd[u] <= 0) out[u][u] = b[u];
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    

    return 0;
}