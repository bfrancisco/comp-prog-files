#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

struct segtree{
    int n; 
    int *vals;
    segtree(vi &ar, int n){
        this->n = n;
        vals = new int[2*n];
        for (int i = 0; i < n; ++i){
            vals[i+n] = ar[i];
        }
        for (int i = n-1; i > 0; --i){
            vals[i] = vals[i<<1] ^ vals[i<<1|1];
        }
    }

    void update(int i, int v){
        for (vals[i+=n] ^= v; i > 1; i >>= 1){
            vals[i>>1] = vals[i] ^ vals[i^1];
        }
    }

    // inclusive exlusive [l, r)
    int query(int l, int r){
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1){
            if (l&1) res ^= vals[l++];
            if (r&1) res ^= vals[--r];
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    vi ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    segtree seg(ar, n);

    // for (int i = 1; i < 2*n; i++){
    //     cout << seg.vals[i] << " ";
    // }
    // cout << endl;

    while(q--){
        int t, x, y; cin >> t >> x >> y;
        if (t == 1){
            seg.update(x-1, y);
        }
        else if (t==2){
            cout << seg.query(x-1, y) << endl;
        }
    }

    return 0;
}   