#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int max_flow(vector<vector<int>>& c, int s, int t, int n) {
    vector<vector<int>> f(n, vector<int>(n));
    vector<int> p(n); // parent pointers

    auto resid = [&](int u, int v) {
        return c[u][v] - f[u][v];
    };

    auto find_aug_path = [&]() {
        fill(p.begin(), p.end(), -1);
        queue<int> q;
        p[s] = s;
        q.push(s);
        while(not q.empty()) {
            int u = q.front(); q.pop();
            for(int v = 0; v < n; v++) {
                if(resid(u, v) > 0 and p[v] == -1) {
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        return p[t] != -1;
    };

    auto augment = [&]() {
        int bottleneck = numeric_limits<int>::max();
        for(int v = t; v != s; v = p[v]) {
            bottleneck = min(bottleneck, resid(p[v], v));
        }
        for(int v = t; v != s; v = p[v]) {
            f[p[v]][v] += bottleneck;
            f[v][p[v]] -= bottleneck;
        }
        return bottleneck;
    };

    int flow = 0;
    while(find_aug_path()) {
        flow += augment();
    }

    return flow;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> c(n, vector<int>(n));
    for(int i = 0; i < m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        c[u][v] += cap;
    }
    int s, t;
    cin >> s >> t;
    cout << max_flow(c, s, t, n) << endl;
    return 0;
}