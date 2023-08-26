// https://atcoder.jp/contests/abc205/tasks/abc205_f

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

    int h,w,k; cin >> h >> w >> k;

    int s = 0, t = w+h+2*k+1;
    flow_network fn(1 + w + 2*k + h + 1, 0, t);

    for (int v = 1; v <= w; v++) {
        fn.add_edge(s, v, 1);
    }
    for (int u = 1; u <= h; u++) {
        fn.add_edge(u+w+k+k, t, 1);
    }
    for (int i = 1; i <= k; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        fn.add_edge(i+w, i+w+k, 1);
        for (int u = b; u <= d; u++){
            fn.add_edge(u, i+w, 1);
        }
        for (int u = a; u <= c; u++){
            fn.add_edge(i+w+k, u+w+k+k, 1);
        }
    }

    cout << fn.calc_max_flow() << endl;

    return 0;
}