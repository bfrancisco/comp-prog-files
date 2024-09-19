#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

struct CompressedST {
  int n;
  vector<ll> st, lazy;

  // compressed information
  vector<pair<ll,ll>> lr;
  map<ll, int> compress;

  CompressedST(vector<ll> &c) {
    int sz = c.size();
    for (int i = 0; i < sz-1; i++) {
      compress[c[i]] = lr.size();
      lr.push_back({c[i], c[i]});
      if (c[i]+1 <= c[i+1]-1) 
        lr.push_back({c[i]+1, c[i+1]-1});
    }
    compress[c[sz-1]] = lr.size();
    lr.push_back({c[sz-1], c[sz-1]});
    n = lr.size();
  
    st.assign(4*n, 0);
    lazy.assign(4*n, -1);
  } 

  void pull(int p) {
    st[p] = st[p<<1] + st[p<<1|1];
  }

  void push(int p, int i, int j) {
    if (lazy[p] != -1) {
      st[p] = lazy[p];
      if (i != j) {
        lazy[p<<1] = lazy[p];
        lazy[p<<1|1] = lazy[p];
      }
      lazy[p] = -1;
    }
  }

  void update(int l, int r, ll v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] = v;
      push(p, i, j);
    }
    else if (j < l || r < i);
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  ll query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) return st[p];
    else if (j < l || r < i) return 0;
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k) 
        + query(l, r, p<<1|1, k+1, j);
    }
  }

  ll query(ll l, ll r) {
    return query(compress[l], compress[r], 1, 0, n-1);
  } 
  void update(ll l, ll r, ll v) {
    update(compress[l], compress[r], v, 1, 0, n-1);
  }
};

int main(){
    int n;
    ll d;
    cin >> n >> d;

    map<ll, int> freq;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<ll> c;
    ordered_set os;
    c.push_back((ll)-1e9);
    os.insert((ll)-1e9);
    for (auto [k, v] : freq){
        c.push_back(k);
        os.insert(k);
    }
    sort(c.begin(), c.end());

    CompressedST st(c);
    for (auto [k, v] : freq){
        st.update(k, k, v);
    }

    vector<ll> ans;
    while (true){
        ll mx = 0;
        ll rmost = -1e9;
        ll lmost = -1e9;
        for (int i = 1; i < c.size(); i++){
            int lefti = os.order_of_key(c[i]-2ll*d);
            ll left = c[lefti];

            ll que = st.query(left, c[i]);
            if (mx < que){
                mx = que;
                rmost = c[i];
                lmost = left;
            }
        }

        if (rmost == (ll)-1e9){
            break;
        }

        st.update(lmost, rmost, 0);
        ans.push_back(rmost-d);
    }

    // for (auto [k, v] : st.compress){
    //     cout << k << " " << st.query(k, k) << endl;
    // }
    cout << ans.size() << endl;
    for (auto e : ans) cout << e << " "; cout << endl;



    return 0;
}