#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree{
    int n; ll *vals;
    segtree(vector<ll>& ar){
        n = ar.size();
        vals = new ll[4*n];
        for (int i = 0; i < 4*n; i++){
            vals[i] = 0ll;
        }
        // build(ar, 1, 0, n-1);
    }

    ll query(int l, int r, int p, int i, int j){
        if (l <= i && j <= r)
            return vals[p];
        else if (r < i || j < l)
            return 0;
        else{
            int k = (i + j) / 2;
            return query(l, r, p << 1, i, k) + query(l, r, p << 1 | 1, k+1, j);
        }
    }

    // point
    void update(int ind, ll vadd, int p, int i, int j){
        if (ind == i && j == ind)
            vals[p] += vadd;
        else if (ind < i || j < ind)
            return;
        else{
            int k = (i + j) / 2;
            update(ind, vadd, p<<1, i, k);
            update(ind, vadd, p<<1|1, k+1, j);
            vals[p] = vals[p<<1] + vals[p<<1|1];
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; ll k; cin >> n >> m >> k;
    int sz = n+(m-1)*2;
    vector<ll> arr(sz, 0ll);
    segtree seg(arr);

    for (int i = m-1; i <= sz-m; i++)
        cin >> arr[i];
    
    int l = 0, r = m-1;
    for (; r < sz; l++, r++){
        ll curval = seg.query(l, r, 1, 0, sz-1);
        // cout << l << " " << r << "   " << curval << endl;
        if (curval >= k)
            continue;
        
        for (int i = r; i >= l; i--){
            ll need = k - curval;
            if (arr[i] >= need){
                arr[i] -= need;
                seg.update(i, need, 1, 0, sz-1);
                curval += need;
            }
            else{
                seg.update(i, arr[i], 1, 0, sz-1);
                curval += arr[i];
                arr[i] = 0ll;
            }
            if (curval >= k) break;
        }

        // for (auto v : arr) cout << v << " "; cout << endl;
    }

    cout << seg.query(m-1, sz-m, 1, 0, sz-1) << endl;

    return 0;
}