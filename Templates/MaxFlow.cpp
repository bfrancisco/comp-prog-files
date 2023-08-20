#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll max_flow(vector<vector<ll>>& c, ll s, ll t) {
    vector<vector<ll>> f(c.size(), vector<ll>(c.size()));
    vector<ll> p(c.size()); // parent pollers

    auto resid = [&](ll u, ll v) {
        return c[u][v] - f[u][v];
    };

    auto find_aug_path = [&]() {
        fill(p.begin(), p.end(), -1);
        queue<ll> q;
        p[s] = s;
        q.push(s);
        while(not q.empty()) {
            ll u = q.front(); q.pop();
            for(ll v = 0; v < c.size(); v++) {
                if(resid(u, v) > 0 and p[v] == -1) {
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        return p[t] != -1;
    };

    auto augment = [&]() {
        ll bottleneck = numeric_limits<ll>::max();
        for(ll v = t; v != s; v = p[v]) {
            bottleneck = min(bottleneck, resid(p[v], v));
        }
        for(ll v = t; v != s; v = p[v]) {
            f[p[v]][v] += bottleneck;
            f[v][p[v]] -= bottleneck;
        }
        return bottleneck;
    };

    ll flow = 0;
    while(find_aug_path()) {
        flow += augment();
    }
    return flow;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> c(n, vector<ll>(n));
    for(ll i = 0; i < m; i++) {
        ll u, v, cap;
        cin >> u >> v >> cap;
        u--; v--;

        c[u][v] += cap;
    }
    int s = 0, t = n-1;
    cout << max_flow(c, s, t) << endl;

    return 0;
}