#include<bits/stdc++.h>
using namespace std;

using ll = long long int;

struct segtree{
    struct data {
        ll sum, pref, suff, ans;
    };

    data make_data(ll val) {
        data res;
        res.sum = res.pref = res.suff = res.ans = val;
        return res;
    }

    int n; 
    data *vals;
    segtree(vector<ll> &ar){
        n = ar.size();
        vals = new data[4*n];
        for (int i = 0; i < 4*n; i++) vals[i] = make_data(-1e9);
        build(ar, 1, 0, n-1);
    }

    data combine(data l, data r) {
        data res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, r.sum + l.suff);
        res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
        return res;
    }

    void build(vector<ll> &ar, int p, int l, int r){
        if (l == r){
            vals[p] = make_data(ar[l]);
        }
        else{
            int m = (l + r) / 2;
            build(ar, p<<1, l, m);
            build(ar, p<<1|1, m+1, r);
            vals[p] = combine(vals[p<<1], vals[p<<1|1]);
        }
    }

    // point update
    void update(int p, int l, int r, int i, ll v){
        if (i <= l && r <= i){
            vals[p] = make_data(v);
        }
        else if (i < l || r < i) return;
        else{
            int m = (l + r) / 2;
            update(p<<1, l, m, i, v);
            update(p<<1|1, m+1, r, i, v);
            vals[p] = combine(vals[p<<1], vals[p<<1|1]);
        }
    }

    data query(int l, int r, int p, int ql, int qr){
        if (ql <= l && r <= qr){
            return vals[p];
        }
        if (r < ql || qr < l){
            return make_data(-1e9);
        }
        int m = (l + r) / 2;
        return combine(query(l, m, p<<1, ql, qr), 
                       query(m+1, r, p<<1|1, ql, qr));
    }

    void update(int i, int v){
        update(1, 0, n-1, i, v);
    }

    ll query(int ql, int qr){
        return query(0, n-1, 1, ql, qr).ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, ll>> ops(m);
    for (int i = 0; i < m; i++){
        int l, r;
        ll x;
        cin >> ops[i].first.first >> ops[i].first.second >> ops[i].second;
    }

    // start[which k][which op i] = value to change
    vector<vector<ll>> start(n+1), end;
    for (int i = 0; i < m; i++){
        auto &[lr, x] = ops[i];
        start[lr.first][i] = x;
        start[lr.second+1][i] = 0;
    }

    int q; cin >> q;
    vector<pair<pair<int, int>, pair<int, int>>> que(q);
    for (int i = 0; i < q; i++){
        que[i].first.second = i;
        cin >> que[i].first.first >> que[i].second.first >> que[i].second.second;
    }
    sort(que.begin(), que.end());
    
    vector<ll> ini(m);
    for (auto [oi, x] : start[1]){
        ini[oi] = x;
    }
    segtree subarraysm(ini);

    vector<ll> ans(q);
    int prevk = 1;
    for (int i = 0; i < q; i++){
        auto &[kqi, lr] = que[i];
        int k = kqi.first, qi = kqi.second;
        if (prevk != k){
            for (auto [oi, x] : start[k]){
                subarraysm.update(oi, x);
            }
            for (auto [oi, x] : end[k]){
                subarraysm.update(oi, x);
            }
        }
        ans[qi] = subarraysm.query(lr.first-1, lr.second-1);
    }

    for (auto x : ans) cout << x << endl;

    return 0;
}