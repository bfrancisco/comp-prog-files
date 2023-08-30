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
            if (u == t) break;
            for (auto ind : adj[u]){
                edge& e = edges[ind];
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

    int n, m, k; cin >> n >> m >> k;
    flow_network fn(1+n+m+1, 0, 1+n+m);

    for (int u = 1; u <= n; u++) fn.add_edge(0, u, 1);
    for (int v = n+1; v <= n+m; v++) fn.add_edge(v, 1+n+m, 1);

    for (int i = 0; i < k; i++){
        int u, v; cin >> u >> v;
        fn.add_edge(u, v+n, 1);
    }

    int x = fn.calc_max_flow();

    vector<pair<int, int>> out;
    for (int u = 1; u <= n; u++){
        for (auto ind : fn.adj[u]){
            edge& e = fn.edges[ind];
            if (ind%2==0 and e.residue() == 0){
                out.push_back({u, e.v - n});
                break;
            }
        }
    }

    cout << out.size() << endl;
    for (auto& [a, b] : out)
        cout << a << " " << b << endl;

    return 0;
}