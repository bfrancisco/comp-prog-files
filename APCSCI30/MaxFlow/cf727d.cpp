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
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 0 - S, 1 - M, 2 - L, ... , 5 - XXXL
    int shirt_cap[6];
    for (int i = 0; i < 6; i++) cin >> shirt_cap[i];
    

    int m; cin >> m;
    int n = 1 + 21 + 6 + 1; // source + people + shirts + sink

    flow_network fn(n, 0, n-1);

    for (int i = 22; i <= 26; i++){
        if (shirt_cap[i-22] > 0){
            fn.add_edge(i, n-1, shirt_cap[i-22]);
            // cout << "Added " << i << " to " << n-1 << endl;
        }
    }

    map<string, int> sztoi;
    map<int, string> itosz;
    vector<string> szes = {"S", "M", "L", "XL", "XXL", "XXXL"};
    
    for (int i = 0; i < 6; i++){
        for (int j = i+1; j < 6; j++){
            szes.push_back(szes[i] + "," + szes[j]);
        }
    }
    for (int i = 0; i < 21; i++) { sztoi[szes[i]] = i+21+1; itosz[i+21+1] = szes[i]; }

    vector<string> inps(m);
    for (int i = 1; i <= m; i++){
        fn.add_edge(0, i, 1);
        string inp; cin >> inp;
        inps[i] = inp;
        inp += ',';
        string shirt = "";
        for (auto c : inp){
            if (c == ',') {
                 fn.add_edge(i, sztoi[shirt], 1);
                // cout << "Added " << i << " to " << sztoi[shirt] << endl;
                shirt.clear();
            }
            else shirt += c;
        }
    }

    int x = fn.calc_max_flow();

    // at least 1 forward edge with a flow == 1 should exist from each person to have perfect matching
    vector<string> out(m+1);

    for (int u = 1; u <= 21; u++){
        int match = 0;
        // cout << "Person: " << u << endl;
        for (int ind : fn.adj[u]){
            if (ind%2) continue;
            edge& e = fn.edges[ind];
            // cout << "  to: " << e.v << " | flow: " << e.f << "   ";
            if (e.f >= 1) {
                // cout << "Found!";
                out[u] = itosz[e.v];
                match = 1;
                break;
            }
            // cout << endl;
        }
        if (!match) { cout << "NO" << endl; return 0; }
    }

    cout << "YES" << endl;
    for (int u = 1; u <= m; u++) cout << out[u] << endl;

}