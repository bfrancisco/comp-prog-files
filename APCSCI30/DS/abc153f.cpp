#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

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
    lazy.assign(4*n, 0);
  } 
 
  void pull(int p) {
    st[p] = st[p<<1] + st[p<<1|1];
  }
 
  void push(int p, int i, int j) {
    if (lazy[p]) {
      st[p] += (lr[j].second-lr[i].first+1)*lazy[p];
      if (i != j) {
        lazy[p<<1] += lazy[p];
        lazy[p<<1|1] += lazy[p];
      }
      lazy[p] = 0;
    }
  }
 
  void update(int l, int r, ll v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] += v;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; 
    ll d, atk;
    cin >> n >> d >> atk;
    vector<pair<ll, ll>> data(n);
    vector<ll> xs(n), hps(n), points;
    for (int i = 0; i < n; i++) {
        ll x, hp;
        cin >> x >> hp;
        data[i] = {x, hp};
        points.push_back(x);
        points.push_back(x + 2ll*d);
    }

    sort(data.begin(), data.end());
    sort(points.begin(), points.end());

    CompressedST seg(points);
    
    for (int i = 0; i < n; i++){
        // cout << data[i].first << " " << data[i].second << endl;
    }

    for (int i = 0; i < n; i++){
        seg.update(data[i].first, data[i].first, data[i].second);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll curhp = seg.query(data[i].first, data[i].first);
        if (curhp <= 0) continue;
        ll atks = (curhp + atk - 1ll) / atk;
        seg.update(data[i].first, data[i].first + 2ll*d, -atks*atk);
        ans += atks;
    }

    cout << ans << '\n';

    return 0;
}