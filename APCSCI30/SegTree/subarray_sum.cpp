#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree {
    int n; ll *vals, *posvals, *deltas;
    segtree(vector<ll> &ar) {
        n = ar.size();
        vals = new ll[4*n];
        deltas = new ll[4*n];
        posvals = new ll[4*n];
        build(ar, 1, 0, n-1);
    }
    
    void build(vector<ll> &ar, int p, int i, int j) {
        deltas[p] = 0;
        if (i == j) {
            vals[p] = ar[i];
            posvals[p] = max(0ll, ar[i]);
        }
        else {
            int k = (i + j) / 2;
            build(ar, p<<1, i, k);
            build(ar, p<<1|1, k+1, j);
            pull(p);
        }
    }
    
    void pull(int p) {
        vals[p] = max(vals[p<<1], vals[p<<1|1]);
        posvals[p] = max(0ll, vals[p]);
    }

    void push(int p, int i, int j) {
        if (deltas[p]) {
            vals[p] += deltas[p];
            posvals[p] = max(0ll, vals[p]);
            if (i != j) {
                deltas[p<<1] += deltas[p];
                deltas[p<<1|1] += deltas[p];
            }
            deltas[p] = 0;
        }
    }

    void ulti_push(int p, int i, int j, int target){
        // cout << p << endl;
        push(p, i, j);
        if (i == j) return;
        int k = (i + j) / 2;
        if (target <= k){
            ulti_push(p<<1, i, k, target);
        }
        else{
            ulti_push(p<<1|1, k+1, j, target);
        }
    }

    // i, j starts at 0, n-1
    void update(int _i, int _j, ll v, int p, int i, int j) {
        push(p, i, j);
        // query overlaps or equates i, j
        if (_i <= i && j <= _j) {
            deltas[p] += v;
            push(p, i, j);
        }
        // no overlap
        else if (_j < i || j < _i) {}
        else {
            int k = (i + j) / 2;
            update(_i, _j, v, p<<1, i, k);
            update(_i, _j, v, p<<1|1, k+1, j);
            pull(p);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q; cin >> n >> q;

    vector<int> n2(20);
    n2[0] = 1;
    for (int i = 1; i <= 20; i++){
        n2[i] = n2[i-1] * 2;
    }
    int newN = n2[lower_bound(n2.begin(), n2.end(), n) - n2.begin()];

    vector<ll> a(newN);
    vector<ll> p(newN);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n; i < newN; i++)
        a[i] = 0;

    p[0] = max(0ll, a[0]);
    for (int i = 1; i < n; i++)
        p[i] = max(0ll, a[i] + p[i-1]);
    for (int i = n; i < newN; i++)
        p[i] = max(0ll, p[i-1]);

    for (auto e : p) cout << e << " "; cout << endl;
    segtree seg(p);
    // for (int i = 1; i < newN*2; i++) cout << seg.vals[i] << " "; cout << endl;
    while(q--){
        int k; ll v; cin >> k >> v;
        k--;
        ll diff = v - a[k];
        a[k] = v;
        if (seg.vals[k+newN] + diff >= 0){
            seg.update(k, newN-1, diff, 1, 0, newN-1);
        }
        else {
            seg.ulti_push(1, 0, newN-1, k);
            // cout << -seg.posvals[k+newN] << endl;
            seg.update(k+1, newN-1, -seg.posvals[k+newN], 1, 0, newN-1);
            seg.update(k, k, diff, 1, 0, newN-1);
        }
        cout << seg.posvals[1] << endl;
        // for (int i = 1; i < newN*2; i++) cout << seg.vals[i] << " "; cout << endl;

    }

    return 0;
}