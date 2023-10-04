#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree{
    int n; int *mx;
    segtree(vector<int>& ar){
        n = ar.size();
        mx = new int[4*n];
        for (int i = 0; i < 4*n; i++){
            mx[i] = -1e9;
        }
        build(ar, 1, 0, n-1);
    }

    void build(vector<int>& ar, int p, int i, int j){
        if (i == j){
            mx[p] = ar[i];
        }
        else{
            int k = (i + j) / 2;
            build(ar, p << 1, i, k);
            build(ar, p << 1 | 1, k+1, j);
            mx[p] = max(mx[p<<1], mx[p<<1|1]);
        }
    }

    int query(int l, int r, int p, int i, int j){
        if (l <= i && j <= r)
            return mx[p];
        else if (r < i || j < l)
            return -1e9;
        else{
            int k = (i + j) / 2;
            return max(query(l, r, p << 1, i, k), query(l, r, p << 1 | 1, k+1, j));
        }
    }

    // point
    void update(int ind, int v, int p, int i, int j){
        if (ind == i && j == ind)
            mx[p] = v;
        else if (ind < i || j < ind)
            return;
        else{
            int k = (i + j) / 2;
            update(ind, v, p<<1, i, k);
            update(ind, v, p<<1|1, k+1, j);
            mx[p] = max(mx[p<<1], mx[p<<1|1]);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    map<pair<int, int>, int> atoi;
    for (int i = 0; i < n; i++){
        int x, h; cin >> x >> h;
        a[i] = {x, h};
        atoi[a[i]] = i;
    }

    sort(a.begin(), a.end());

    vector<int> far(n), fall(n);
    for (int i = 0; i < n; i++){
        far[i] = a[i].first + a[i].second - 1;
    }

    segtree segfar(far);

    for (int i = n-1; i >= 0; i--){
        int r = upper_bound(a.begin()+i, a.end(), make_pair(far[i], (int)1e9)) - a.begin() - 1;
        int mx = segfar.query(i, r, 1, 0, n-1);
        segfar.update(i, mx, 1, 0, n-1);
        // cout << i << " " << r << endl;
        int j = upper_bound(a.begin()+i, a.end(), make_pair(mx, (int)1e9)) - a.begin();
        fall[i] = j-i;
    }

    // for (auto e : far) cout << e << " "; cout << endl;
    // for (auto e : fall) cout << e << " "; cout << endl;

    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[atoi[a[i]]] = fall[i];
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}