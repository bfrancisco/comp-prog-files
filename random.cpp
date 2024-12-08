#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

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
    // included left, included right, total, mx subarray
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
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    segtree subarray_sum(v);
    // cout << max(0ll, subarray_sum.query(0, n-1)) << endl;
    // for (int i = 1; i < 10; i++){
    //     cout << subarray_sum.vals[i].ans << " "; 
    // } cout << endl;

    while (m--){
        int i;
        ll x;
        cin >> i >> x;
        subarray_sum.update(i-1, x);
        // for (int i = 1; i < 10; i++){
        //     cout << subarray_sum.vals[i].ans << " "; 
        // } cout << endl;
        cout << max(0ll, subarray_sum.query(0, n-1)) << endl;
    }

    return 0;
}