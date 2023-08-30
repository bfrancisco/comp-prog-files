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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 0 - S, 1 - M, 2 - L, ... , 5 - XXXL
    int shirt_cap[6];
    for (int i = 0; i < 6; i++) cin >> shirt_cap[i];
    
    vector<string> szes = {"S", "M", "L", "XL", "XXL", "XXXL"};
    for (int i = 0; i < 6; i++){
        for (int j = i+1; j < 6; j++){
            szes.push_back(szes[i] + "," + szes[j]);
        }
    }

    int m; cin >> m;
    int p = szes.size(); // 21
    int n = 1 + p + 6 + 1; // source + people + shirts + sink

    flow_network fn(n, 0, n-1);

    // -> sink
    for (int i = p+1; i <= p+6; i++){
        if (shirt_cap[i-p-1] > 0){
            fn.add_edge(i, n-1, shirt_cap[i-p-1]);
        }
    }

    map<string, int> sztoi, sztou;
    map<int, string> itosz, utosz;
    for (int i = 0; i < 6; i++) { sztoi[szes[i]] = i+p+1; itosz[i+p+1] = szes[i]; }
    for (int u = 0; u < p; u++) { sztou[szes[u]] = u+1; utosz[u+1] = szes[u]; }
    map<string, vector<string>> matches;
    map<string, int> freq;
    set<int> exists;
    for (int i = 0; i < p; i++) { matches[szes[i]]; freq[szes[i]] = 0; }

    vector<string> inputs(m);
    for (int i = 0; i < m; i++){
        cin >> inputs[i];
        freq[inputs[i]]++;
        exists.insert(sztou[inputs[i]]);
    }

    // people -> shirts
    for (int u = 1; u <= p; u++){
        string s = szes[u-1] + ',';
        string shirt = "";
        for (auto c : s){
            if (c == ','){
                fn.add_edge(u, sztoi[shirt], freq[szes[u-1]]);
                shirt.clear();
            }
            else shirt += c;
        }
    }

    // source -> 
    for (int i = 1; i <= p; i++){
        fn.add_edge(0, i, freq[szes[i-1]]);
    }

    int x = fn.calc_max_flow();
    if (x < m) { cout << "NO" << endl; return 0; }

    cout << "YES" << endl;

    for (auto inp : inputs){
        for (auto ind : fn.adj[sztou[inp]]){
            if (ind%2) continue;
            edge& e = fn.edges[ind];
            if (e.f > 0){
                cout << itosz[e.v] << endl;
                e.f--;
                break;
            }
        }
    }
}