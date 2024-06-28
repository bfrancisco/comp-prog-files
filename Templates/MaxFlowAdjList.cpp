#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

struct edge {
    size_t i; // index at edges
    int v;
    ll c, f; // directed to v, capacity, flow
    ll residue() { return c - f; }
};
 
struct flow_network {
    int n, s, t;
    vector<edge> edges;  // even indeces are forward flows, e_i+1 are reverse flows.
    vector<vector<int>> adj; // stores index pointing in edges
    vector<int> parent;
    set<pair<int, int>> edge_cuts;
    set<int> A; // set of nodes that belongs to one side of the cut
 
    flow_network(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        parent.resize(n);
    }
 
    void add_edge(int u, int v, ll cap) {
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
 
    ll augment() {
        ll bottleneck = numeric_limits<ll>::max();
        for (int v = t; v != s; v = edges[parent[v] ^ 1].v) {
            bottleneck = min(bottleneck, edges[parent[v]].residue());
        }
        for (int v = t; v != s; v = edges[parent[v] ^ 1].v) {
            edges[parent[v]].f += bottleneck;
            edges[parent[v] ^ 1].f -= bottleneck;
        }
        return bottleneck;
    }
 
    ll calc_max_flow() {
        ll flow = 0;
        while (aug_path()){
            flow += augment();
        }
        return flow;
    }
 
    void calc_edge_cuts() {
        queue<int> q;
        q.push(s);
        vector<int> vis(n, 0);
 
        while (!q.empty()) {
            int u = q.front(); q.pop();
            A.insert(u);
            for (auto ind : adj[u]) {
                edge& e = edges[ind];
                if (ind % 2 == 0 && !vis[e.v] && e.residue() > 0) {
                    vis[e.v] = 1;
                    q.push(e.v);
                }
            }
        }
        for (int u = 0; u < n; u++) {
            for (auto ind : adj[u]) {
                edge& e = edges[ind];
                int a = u, b = e.v;
                if (a > b) swap(a, b);
 
                if ((A.find(a) != A.end() && A.find(b) == A.end()) || 
                    (A.find(a) == A.end() && A.find(b) != A.end())){
                    edge_cuts.insert({a, b});
                }
            }
        }
        
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    int s = 0, t = n-1;
    flow_network fn(n, s, t);
    for (int i = 0; i < m; i++) {
        int u, v; 
        ll cap;
        cin >> u >> v >> cap;
        u--; v--;
        fn.add_edge(u, v, cap);
    }

    cout << fn.calc_max_flow() << endl;
}