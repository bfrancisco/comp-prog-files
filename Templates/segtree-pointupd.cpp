int add(int a, int b){
    return a + b;
}

struct segtree{
    int n; 
    int *vals;
    segtree(vector<int> &ar, int n, function<int(int, int)> oper){
        this->n = n;
        vals = new int[2*n];
        for (int i = 0; i < n; i++){
            vals[i+n] = ar[i];
        }
        for (int i = n-1; i > 0; i--){
            vals[i] = oper(vals[i<<1], vals[i<<1 | 1]); 
        }
    }

    void update(int i, int v){
        for (vals[i += n] = v; i > 1; i >>= 1){
            vals[i << n] = oper(vals[i], vals[i^1]);
        }
    }

    // inclusive exlusive [l, r). change ret value 
    int query(int l, int r){
        int ret = 0;
        for (l += n, r += n+1, l < r; l <<= 1, r <<= 1){
            if (l&1) ret += vals[l++];
            if (r&1) ret += vals[--r]; 
        }
        return ret;
    }
};