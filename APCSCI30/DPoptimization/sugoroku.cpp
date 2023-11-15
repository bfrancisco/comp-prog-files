#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using pii = pair<int, int>;
int INF = 1e9;

struct segtree {
    int n; pii *vals;
    segtree(vector<pii> &ar) {
        n = ar.size();
        vals = new pii[4*n];
        build(ar, 1, 0, n-1);
    }
    
    void build(vector<pii> &ar, int p, int i, int j) {
        if (i == j) {
            vals[p] = ar[i];
        }
        else {
            int k = (i + j) / 2;
            build(ar, p<<1, i, k);
            build(ar, p<<1|1, k+1, j);
            pull(p);
        }
    }
    
    void pull(int p) {
        vals[p] = min(vals[p<<1], vals[p<<1|1]);
    }

    // i, j starts at 0, n-1
    void update(int _i, int _j, pii v, int p, int i, int j) {
        // query overlaps or equates i, j
        if (_i == i && j == _j) {
            vals[p] = v;
        }
        // no overlap
        else if (_j < i || j < _i) {}
        else {
            int k = (i + j) / 2;
            update(_i, _j, v, p<<1, i, k);
            update(_i, _j, v, p<<1|1, k+1, j);
            pull(p);
        }
    }

    pii query(int _i, int _j, int p, int i, int j) {
        if (_i <= i && j <= _j)
            return vals[p];
        else if (_j < i || j < _i)
            return {INF, INF};
        else {
            int k = (i + j) / 2;
            return  min(query(_i, _j, p<<1, i, k),
                    query(_i, _j, p<<1|1, k+1, j));
        }
    }

    void update(int _i, pii v) {
        update(_i, _i, v, 1, 0, n-1);
    }

    pii query(int _i, int _j) {
        return query(_i, _j, 1, 0, n-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<pii> temp(n+1, {INF, INF});
    segtree dp(temp);
    dp.update(0, {0, 0});
    for (int i = 1; i <= n; i++){
        if (s[i] == '1') continue;
        dp.update(i, {dp.query(max(i-m, 0), i-1).first + 1, i});
    }

    // for (int i = 0; i <= n; i++) cout << dp.query(i, i).first << " " << endl;

    stack<int> ans;
    int cur = n;
    while (cur > 0){
        int left = dp.query(max(cur-m, 0), n-1).second;
        if (left == INF){
            cout << -1 << endl;
            return 0;
        }
        ans.push(cur - left);
        cur = left;
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
    

    return 0;
}