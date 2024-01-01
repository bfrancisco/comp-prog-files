#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN = 200001;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

struct CompressedST {
  // credits to ongyiumark
  int n;
  vector<ll> st, lazy;

  // compressed information
  vector<pair<ll,ll>> lr;
  map<ll, int> compress;

  CompressedST() {
    vector<ll> c(MAXN);
    for (int i = 0; i < MAXN; i++) c[i] = i;
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

struct fast_median {
    ordered_set left, right, nega, posi;
    ll nsum, psum;
    CompressedST segtreeL, segtreeR;
    fast_median(){
        nsum = 0;
        psum = 0;
    }
    int get_sz() { return left.size() + right.size(); }

    pair<ll, int> get_median() { return (*left.rbegin()); }

    void add(ll v, int i){
        if ((int)left.size() == (int)right.size()){
            auto [r_small, ind] = *right.begin();
            if ((int)right.size() > 0 && (v > r_small || (v == r_small && i > ind))){
                left.insert({r_small, ind});
                segtreeL.update(r_small, r_small, abs(r_small));
                right.erase({r_small, ind});
                segtreeR.update(r_small, r_small, -abs(r_small));
                right.insert({v, i});
                segtreeR.update(v, v, abs(v));
            }
            else{
                left.insert({v, i});
                segtreeL.update(v, v, abs(v));
            }
        }
        else{
            auto [l_high, ind] = *left.rbegin();
            if (v < l_high || (v == l_high && i < ind)){
                right.insert({l_high, ind});
                segtreeR.update(l_high, l_high, abs(l_high));
                left.erase({l_high, ind});
                segtreeL.update(l_high, l_high, -abs(l_high));
                left.insert({v, i});
                segtreeL.update(v, v, abs(v));
            }
            else{
                right.insert({v, i});
                segtreeR.update(v, v, abs(v));
            }
        }

        if (v < 0){
            nega.insert({v, i});
            nsum -= v; // nsum is magnitude of negatives
        }
        else{
            posi.insert({v, i});
            psum += v;
        }
    }

    void remove(ll v, int i){
        if (left.find(make_pair(v, i)) != left.end()){
            left.erase({v, i});
            segtreeL.update(v, v, -abs(v));
            if (left.size() < right.size()){
                auto [rv, ri] = *right.begin();
                left.insert({rv, ri});
                segtreeL.update(rv, rv, abs(rv));
                right.erase({rv, ri});
                segtreeR.update(rv, rv, -abs(rv));
            }
        }
        else{
            right.erase({v, i});
            segtreeR.update(v, v, -abs(v));
            if ((int)left.size() - 2 == (int)right.size()){
                auto [lv, li] = *left.begin();
                right.insert({lv, li});
                segtreeR.update(lv, lv, abs(lv));
                left.erase({lv, li});
                segtreeL.update(lv, lv, -abs(lv));
            }
        }
        
        if (v < 0){
            nega.erase({v, i});
            nsum += v; // this is subtracting
        }
        else{
            posi.erase({v, i});
            psum -= v;
        }
    }

    ll get_abs_sum(){
        auto [median, mi] = get_median();
        ll ps = posi.size();
        ll ns = nega.size();
        // cout << "ps ns: " << ps << " " << ns << endl;
        ll ans = nsum+psum;
        // cout << "L: "; for (auto [x, i] : left) cout << x << " "; cout << endl;
        // cout << "R: "; for (auto [x, i] : right) cout << x << " "; cout << endl;
        // cout << "nega: "; for (auto [x, i] : nega) cout << x << "," << i << " "; cout << endl;
        // cout << "total: " << ans << endl;
        // cout << "median: " << median << "  ind: " << mi << endl;
        
    
        if (median > 0){
            ll lt_median_c = posi.order_of_key({median, -1}); // less than median count, that is +
            ll gte_median_c = ps - lt_median_c; // >= median count, that is posi
            ans -= gte_median_c * median;
            ll rsq = segtreeL.query(0, median-1);
            ans -= rsq; // subtract residue
            ans += lt_median_c * median - rsq; // bring back
            ans += ns * median; // negatives
        }
        else{
            ll lte_median_c = nega.order_of_key({median, mi})+1;
            ll gt_median_c = ns - lte_median_c;
            ans -= lte_median_c * abs(median);
            ll rsq = segtreeR.query(median+1, 0);
            ans -= abs(rsq); // residue
            ans += gt_median_c * abs(median) - abs(rsq); // bring back
            ans += ps * abs(median); // positives
        }
        // cout << "returned: " << ans << endl << endl;

        return ans;
    }


};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    vector<ll> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) d[i] = b[i] - a[i];

    vector<ll> tmp(MAXN, 0);
    fast_median L, R;
    L.add(d[0], 0);
    for (int i = 1; i < n; i++){
        R.add(d[i], i);
    }

    for (int m = 1; m < n; m++){
        ll lv = L.get_abs_sum(), lr = R.get_abs_sum();
        // cout << "ans: " << lv + lr << endl;
        cout << lv + lr << " ";

        L.add(d[m], m);
        R.remove(d[m], m);
        // break;
    }

    return 0;
}