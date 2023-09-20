#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree{
    int n; 
    ll *le, *ri, *to, *mx;
    // included left, included right, total, mx subarray
    segtree(vector<ll> &ar, int n){
        this->n = n;
        le = new ll[2*n];
        ri = new ll[2*n];
        to = new ll[2*n];
        mx = new ll[2*n];
        for (int i = 0; i < n; ++i){
            le[i+n] = ar[i];
            ri[i+n] = ar[i];
            to[i+n] = ar[i];
            mx[i+n] = ar[i];
        }
        for (int i = n-1; i > 0; --i){
            le[i] = max(le[i<<1], to[i<<1] + le[i<<1|1]);
            ri[i] = max(ri[i<<1|1], to[i<<1|1] + ri[i<<1]);
            to[i] = to[i<<1] + to[i<<1|1];
            mx[i] = max({0ll, ri[i<<1] + le[i<<1|1], mx[i<<1], mx[i<<1|1]});
        }
    }

    void update(int i, ll v){
        i += n;
        le[i] = v;
        ri[i] = v;
        to[i] = v;
        mx[i] = v;
        for (i >>= 1; i >= 1; i >>= 1){
            le[i] = max(le[i<<1], to[i<<1] + le[i<<1|1]);
            ri[i] = max(ri[i<<1|1], to[i<<1|1] + ri[i<<1]);
            to[i] = to[i<<1] + to[i<<1|1];
            mx[i] = max({0ll, ri[i<<1] + le[i<<1|1], mx[i<<1], mx[i<<1|1]});
        }
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int faken, q; cin >> faken >> q;

    vector<ll> n2(20);
    n2[0] = 1;
    for (int i = 1; i <= 20; i++){
        n2[i] = n2[i-1] * 2;
    }
    int n = n2[lower_bound(n2.begin(), n2.end(), faken) - n2.begin()];

    vector<ll> a(n);
    for (int i = 0; i < faken; i++){
        cin >> a[i];
    }
    for (int i = faken; i < n; i++){
        a[i] = 0;
    }

    segtree seg(a, n);
    while(q--){
        int k; ll v; cin >> k >> v;
        seg.update(k-1, v);
        cout << seg.mx[1] << endl;
        // for (int i = 1; i < n*2; i++) cout << seg.mx[i] << " "; cout << endl;

    }

    return 0;
}