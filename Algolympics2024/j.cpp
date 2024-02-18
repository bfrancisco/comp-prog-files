#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll MOD = 998244353;

ll mod(ll a){
    return (a%MOD + MOD) % MOD;
}

struct segtreeA {
    int n;
    ll *vals;

    // segtree(vector<ll>& A){
    //     n = A.size();
    //     vals = new ll[4*n];
    //     build(A, 1, 0, n-1);
    // }

    void create(vector<ll>& A){
        n = A.size();
        vals = new ll[4*n];
        build(A, 1, 0, n-1);
    }

    void build(vector<ll> &A, int p, int i, int j){
        if (i == j){
            vals[p] = A[i];
        }
        else{
            int k = (i+j)/2;
            build(A, p<<1, i, k);
            build(A, p<<1|1, k+1, j);
            pull(p);
        }
    }

    void pull(int p){
        vals[p] = mod(mod(vals[p<<1])*mod(vals[p<<1|1]));
    }

    // point update
    void update(int l, int r, ll v, int p, int i, int j){
        if (l <= i && j <= r){
            vals[p] = v;
        }
        else if (j < l || r < i);
        else{
            int k = (i+j)/2;
            update(l, r, v, p<<1, i, k);
            update(l, r, v, p<<1|1, k+1, j);
            pull(p);
        }
    }

    ll query(int l, int r, int p, int i, int j){
        if (l <= i && j <= r){
            return vals[p];
        }
        else if (j < l || r < i){
            return 1ll;
        }
        else{
            int k = (i+j)/2;
            return mod(query(l, r, p<<1, i, k) * query(l, r, p<<1|1, k+1, j));
        }
    }

    ll query(int pnt){
        return query(pnt, pnt, 1, 0, n-1);
    }

    void update(int pnt, ll v){
        update(pnt, pnt, v, 1, 0, n-1);
    }

};

struct segtreeMain {
    int n;
    vector<vector<ll>> data;
    segtreeA segA;

    segtreeMain(vector<ll> &A, vector<ll> &B){
        n = A.size();
        data.assign(n*4, vector<ll>(3, 0));
        segA.create(A);
        build(A, B, 1, 0, n-1);
    }

    void build(vector<ll> &A, vector<ll> &B, int p, int i, int j){
        if (i == j){
            data[p][0] = A[i];
            data[p][1] = 0;
            data[p][2] = B[i];
        }
        else{
            int k = (i+j)/2;
            build(A, B, p<<1, i, k);
            build(A, B, p<<1|1, k+1, j);
            pull(p, i, j);
        }
    }

    void pull(int p, int i, int j){
        data[p][0] = segA.query(i, j, 1, 0, n-1);
        data[p][1] = mod(data[p<<1][0] * mod(data[p<<1|1][1] + data[p<<1|1][2]));
        data[p][2] = mod(data[p<<1][1] + data[p<<1][2]);
    }

    ll compute(int p, ll c){
        // cout << "COMP   p: " << p << " val: " << mod(mod(data[p][0]*c) + mod(data[p][1] + data[p][2])) << endl;
        return mod(mod(data[p][0]*c) + mod(data[p][1] + data[p][2]));
    }

    ll query(int l, int r, ll c, int p, int i, int j){
        if (l <= i && j <= r){
            // cout << "p: " << p << endl;
            return compute(p, c);
        }
        else if (j < l || r < i){
            // cout << "p: " << p << "\t return c" << endl;

            return c;
        }
        else{
            int k = (i+j)/2;
            ll RHS = query(l, r, c, p<<1|1, k+1, j);
            ll LHS = query(l, r, RHS, p<<1, i, k);
            // cout << "p: " << p << "\tLHS: " << LHS << "\tRHS: " << RHS << endl;
            return LHS;
        }
    }

    void update(int l, int r, ll v, char ab, int p, int i, int j){
        if (l <= i && j <= r){
            if (ab=='A'){
                data[p][0] = v;
                segA.update(l, v);
            }
            else data[p][2] = v;
        }
        else if (j < l || r < i);
        else{
            int k = (i+j)/2;
            update(l, r, v, ab, p<<1, i, k);
            update(l, r, v, ab, p<<1|1, k+1, j);
            pull(p, i, j);
        }
    }

    ll query(int l, int r, ll c){
        return query(l, r, c, 1, 0, n-1);
    }

    void update(int pnt, ll v, char ab){
        update(pnt, pnt, v, ab, 1, 0, n-1);
    }

    
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> A(n), B(n);

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        cin >> B[i];
    }

    segtreeMain seg(A, B);

    // for (int i = 1; i <= 15; i++){
    //     cout << "P: " << i << "\tA: " << seg.data[i][0] << "\tB: " << seg.data[i][1] << "\tC: " << seg.data[i][2] << endl;
    // }

    int q; cin >> q;
    ll l, r, c;
    char con, ab;
    while (q--){
        cin >> con;
        if (con == '?'){
            cin >> l >> r >> c;
            l--; r--;
            cout << seg.query(l, r, c) << endl;
        }
        else if (con == 'H'){
            cin >> ab >> l >> r;
            l--; r--;
            if (ab == 'A'){
                swap(A[l], A[r]);
                seg.update(l, A[l], 'A');
                seg.update(r, A[r], 'A');
            }
            else{
                swap(B[l], B[r]);
                seg.update(l, B[l], 'B');
                seg.update(r, B[r], 'B');
            }
        }
        else if (con == 'V'){
            cin >> l;
            l--;
            swap(A[l], B[l]);
            seg.update(l, A[l], 'A');
            seg.update(l, B[l], 'B');
        }
    }
    
    return 0;
}