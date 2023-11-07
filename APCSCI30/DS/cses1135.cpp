#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> dist;

void dfs(int v, int p, int d)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    dist[v] = d;
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, d+1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dist.resize(n);
    dfs(root, root, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int q;
    cin >> n >> q;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preprocess(0);

    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        int anc = lca(a, b);
        cout << dist[a] + dist[b] - 2*dist[anc] << endl;
    }

    return 0;
}
