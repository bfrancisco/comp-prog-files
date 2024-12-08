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