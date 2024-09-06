#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree {
    int n;
    vector<pair<int, int>> vals;
    segtree(vector<pair<int, int>> &ar) {
        n = ar.size();
        // vals = new int[4*n];
        vals.resize(4*n);
        build(ar, 1, 0, n-1);
    }
    
    void build(vector<pair<int, int>> &ar, int p, int i, int j) {
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
        pair<int, int> le = vals[p<<1];
        pair<int, int> ri = vals[p<<1|1];
        if (le.first > ri.first){
            vals[p] = le;
        }
        else{
            vals[p] = ri;
        }
    }

    pair<int, int> query(int _i, int _j, int p, int i, int j) {
        if (_i <= i && j <= _j)
            return vals[p];
        else if (_j < i || j < _i)
            return {-1, -1};
        else {
            int k = (i + j) / 2;
            pair<int, int> le = query(_i, _j, p<<1, i, k); 
            pair<int, int> ri = query(_i, _j, p<<1|1, k+1, j); 
            if (le.first > ri.first){
                return le;
            }
            return ri;
        }
    }

    pair<int, int> query(int _i, int _j) {
        return query(_i, _j, 1, 0, n-1);
    }
};

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> inc(n);
    inc[0] = {1, 0};
    for (int i = 1; i < n; i++){
        if (a[i-1]+1 == a[i]){
            inc[i] = {inc[i-1].first + 1, i};
        }
        else{
            inc[i] = {1, i};
        }
    }

    // for (auto x : inc) cout << x.first << " " << x.second << endl; cout << endl;

    segtree seg(inc);
    while(q--){
        int l, r; cin >> l >> r;
        l--; r--;

        // cout << seg.query(l, r).first << " " << seg.query(l, r).second << endl;

        auto [mx, ind] = seg.query(l, r);
        // cout << "mx: " << mx << endl;
        // cout << "ind: " << ind << endl;

        mx = (ind-mx+1 < l ? ind-l+1 : mx);
        if (ind+1 < r){
            auto [mx2, ind2] = seg.query(ind+1, r);
            mx = max(mx, mx2);
        }
        cout << max(0, k - mx) << endl;
    }

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