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
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= i;
    }

    for (auto x : a) cout << x << " "; cout << endl;
    map<int, int> db;
    map<int, int> ans;
    int mx = -1;
    for (int i = 0; i < k; i++){
        db[a[i]]++;
        mx = max(mx, db[a[i]]);
    }

    ans[0] = mx;
    int l = 0, r = k-1;
    while (r < n){
        db[a[l]]--;
        l++;
        db[a[l]]++;
    }
    for (auto [k, v] : db){
        cout << k << " " << v << endl;
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