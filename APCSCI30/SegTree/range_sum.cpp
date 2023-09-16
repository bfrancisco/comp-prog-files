#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree{
    int n; 
    ll *vals;
    segtree(vector<ll> &ar, int n){
        this->n = n;
        vals = new ll[2*n];
        for (int i = 0; i < n; ++i){
            vals[i+n] = ar[i];
        }
        for (int i = n-1; i > 0; --i){
            vals[i] = vals[i<<1] + vals[i<<1|1];
        }
    }

    void update(int i, ll v){
        for (vals[i+=n] = v; i > 1; i >>= 1){
            vals[i>>1] = vals[i] + vals[i^1];
        }
    }

    // [l, r]
    ll query(int l, int r){
        ll res = 0;
        for (l += n, r += n+1; l < r; l >>= 1, r >>= 1){
            if (l&1) res += vals[l++];
            if (r&1) res += vals[--r];
        }
        return res;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    segtree seg(a, n);
    while(q--){
        int c; cin >> c;
        if (c==2){
            int l, r; cin >> l >> r;
            l--; r--;
            cout << seg.query(l, r) << endl;
        }
        else{
            int i; ll v; cin >> i >> v;
            seg.update(i-1, v);
        }
    }

    return 0;
}