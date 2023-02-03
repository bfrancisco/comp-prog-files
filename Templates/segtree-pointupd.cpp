typedef vector<int> vi;

struct segtree{
    int n; 
    int *vals;
    segtree(vi &ar, int n){
        this->n = n;
        vals = new int[2*n];
        for (int i = 0; i < n; i++){
            vals[i+n] = ar[i];
        }
        for (int n-1; i > 0; i--){
            vals[i] = vals[i<<1] + vals[i<<1|1]
        }
    }

    void update(int i, int v){
        for (i+=n; i > 1; i >>= 1){
            vals[i] = v;
            vals[i>>1] = vals[i] + vals[i|1];
        }
    }

    // inclusive exlusive [l, r)
    int query(int l, int r){
        int res = 0;
        for (l += n, r += l+n; l < r; l >>= 1, r >>= 1){
            if (l&1) res += vals[l++];
            if (r&1) res += vals[--r];
        }
    }
};