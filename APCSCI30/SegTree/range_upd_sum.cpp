#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree {
    int n; ll *vals, *deltas, *setdeltas;
    segtree(vector<ll> &ar) {
        n = ar.size();
        vals = new ll[4*n];
        deltas = new ll[4*n];
        setdeltas = new ll[4*n];

        build(ar, 1, 0, n-1);
    }
    
    void build(vector<ll> &ar, int p, int i, int j) {
        deltas[p] = 0;
        if (i == j) {
            vals[p] = ar[i];
        }
        else {
            int k = (i + j) / 2;
            build(ar, p<<1, i, k);
            build(ar, p<<1|1, k+1, j);
            pull(p);
        }
    }
    
    void pull(int p) {
        vals[p] = vals[p<<1] + vals[p<<1|1];
    }

    void push(int p, int i, int j) {
        if (setdeltas[p]) { 
            vals[p] = (j - i + 1) * setdeltas[p];
            if (i != j) {
                setdeltas[p<<1] = setdeltas[p];
                setdeltas[p<<1|1] = setdeltas[p];
                deltas[p<<1] = 0;
                deltas[p<<1|1] = 0;
            }
            setdeltas[p] = 0;
        }
        if (deltas[p]) { 
            vals[p] += (j - i + 1) * deltas[p];
            if (i != j) {
                deltas[p<<1] += deltas[p];
                deltas[p<<1|1] += deltas[p];
            }
            deltas[p] = 0;
        }
    }

    // i, j starts at 0, n-1
    void update(int _i, int _j, ll v, int p, int i, int j, bool isSet) {
        push(p, i, j);
        // query overlaps or equates i, j
        if (_i <= i && j <= _j) {
            if (isSet) {
                setdeltas[p] = v;
                deltas[p] = 0;
            }
            else {
                deltas[p] += v;
            }
            push(p, i, j);
        }
        // no overlap
        else if (_j < i || j < _i) {}
        else {
            int k = (i + j) / 2;
            update(_i, _j, v, p<<1, i, k, isSet);
            update(_i, _j, v, p<<1|1, k+1, j, isSet);
            pull(p);
        }
    }

    ll query(int _i, int _j, int p, int i, int j) {
        push(p, i, j);
        if (_i <= i && j <= _j)
            return vals[p];
        else if (_j < i || j < _i)
            return 0;
        else {
            int k = (i + j) / 2;
            return  query(_i, _j, p<<1, i, k) +
                    query(_i, _j, p<<1|1, k+1, j);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0;i < n; i++) cin >> a[i];

    segtree seg(a);

    while (q--) {
        int c; cin >> c;
        if (c==1) {
            int l, r; ll v; cin >> l >> r >> v;
            seg.update(--l, --r, v, 1, 0, n-1, false);
        }
        else if (c==2) { 
            int l, r; ll v; cin >> l >> r >> v;
            seg.update(--l, --r, v, 1, 0, n-1, true);
        }
        else {
            int l, r; cin >> l >> r;
            cout << seg.query(--l, --r, 1, 0, n-1) << endl;
        }
    }

    return 0;
}