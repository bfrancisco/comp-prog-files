// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1421

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
    set<pair<int, int>> edge_cuts;
    set<int> A; // set of nodes that belongs to one side of the cut

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
            // cout << "Pop: " << u+1 << endl;
            for (auto ind : adj[u]){
                edge& e = edges[ind];
                // cout << e.i << " " << e.v+1 << endl;
                if (e.residue() > 0 && parent[e.v] == -1) {
                    // cout << "Edge: " << e.i << 
                    // "  |  Flow: " << e.f << 
                    // "  |  Cap: " << e.c << 
                    // "  |  Residue: " << e.residue() <<
                    // "  |  Directs to: " << e.v +1 << endl;
                    parent[e.v] = e.i;
                    q.push(e.v);
                }
            }
        }

        // cout << "\nPath: " << endl;
        // for (int v = t; v != s; v = edges[parent[v] ^ 1].v){
        //     cout << v+1 << " ";
        // } cout << s+1 << endl;

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

void solve(int n, int m){
    flow_network fn(n, 0, 1);
    // 1 is sink (2 in input)
    for (int i = 0; i < m; i++){
        int u, v, cap; cin >> u >> v >> cap;
        u--; v--;
        fn.add_edge(u, v, cap);
        fn.add_edge(v, u, cap);
    }

    int x = fn.calc_max_flow();
    fn.calc_edge_cuts();

    for (auto& [u, v] : fn.edge_cuts){
        cout << u+1 << " " << v+1 << endl;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    while (n != 0 && m != 0){
        solve(n, m);
        cin >> n >> m;
    }

    return 0;
}