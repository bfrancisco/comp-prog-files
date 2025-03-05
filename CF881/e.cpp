#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

struct segtree {
    int n, *vals;
    segtree(vector<int> &ar) {
        n = ar.size();
        vals = new int[4*n];
        build(ar, 1, 0, n-1);
    }
    
    void build(vector<int> &ar, int p, int i, int j) {
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

    // i, j starts at 0, n-1
    void update(int _i, int _j, int v, int p, int i, int j) {
        // query overlaps or equates i, j
        if (_i <= i && j <= _j) {
            vals[p] = v;
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

    int query(int _i, int _j, int p, int i, int j) {
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

    void update(int _i, int _j, int v) {
        update(_i, _j, v, 1, 0, n-1);
    }

    int query(int _i, int _j) {
        return query(_i, _j, 1, 0, n-1);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> segments;
    vector<int> ta(n+1, 0);
    segtree a(ta);

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        segments.insert({x, y});
    }
    m = segments.size();

    int q; cin >> q;
    vector<int> Q(q);
    for (int i = 0; i < q; i++) cin >> Q[i];

    int ans = -1;
    int l = 0, r = q-1;
    int prevm = -1;
    while (r-l > 5){
        int m = (l+r)/2;
        if (prevm < m){
            for (int i = prevm+1; i <= m; i++){
                a.update(Q[i], Q[i], 1);
            }
        }
        else{
            for (int i = prevm; i > m; i--){
                a.update(Q[i], Q[i], 0);
            }
        }

        // cout << l << " " << r << endl;
        // cout << "M: " << m << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << a.query(i, i) << " ";
        // }cout << endl;

        bool pass = false;
        for (auto& [l, r] : segments){
            if (a.query(l, r) > (int)((r-l+1)/2)){
                // cout << l << " " << r << " " << m << endl;
                pass = true;
                break;
            }
        }
        if (pass){
            r = m;
        }
        else{
            l = m;
        }
        prevm = m;
        // cout << endl;
    }

    for (int i = 0; i < q; i++){
        if (i < max(l-5, 0)) a.update(Q[i], Q[i], 1);
        else a.update(Q[i], Q[i], 0);
    }

    for (int i = max(l-5, 0); i <= min(q-1, l+15); i++){
        // cout << i << endl;
        a.update(Q[i], Q[i], 1);

        bool pass = false;
        for (auto& [l, r] : segments){
            if (a.query(l, r) > (int)((r-l+1)/2)){
                // cout << l << " " << r << " " << m << endl;
                pass = true;
                break;
            }
        }

        // for (int i = 1; i <= n; i++){
        //     cout << a.query(i, i) << " ";
        // }cout << endl;

        if (pass){
            ans = i;
            break;
        }
    }

    cout << (ans==-1 ? -1 : ans+1) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}