#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree{
    int n; int *mx;
    segtree(vector<int>& ar){
        n = ar.size();
        mx = new int[4*n];
        build(ar, 1, 0, n-1);
    }
    
    void build(vector<int>& ar, int p, int i, int j){
        if (i == j){
            mx[p] = ar[i];
        }
        else{
            int k = (i + j) / 2;
            build(ar, p <<1, i, k);
            build(ar, p <<1|1, k+1, j);
            mx[p] = max(mx[p<<1], mx[p<<1|1]);
        }
    }

    int query(int l, int r, int p, int i, int j){
        if (l <= i && j <= r)
            return mx[p];
        else if (r < i || j < l)
            return -1;
        else{
            int k = (i + j) / 2;
            return max(query(l, r, p<<1, i, k), query(l, r, p<<1|1, k+1, j));
        }
    }
};


vector<int> solve(vector<int> arr, vector<int> queries) {
    segtree seg(arr);
    int n = arr.size(), m = queries.size();
    vector<int> b(m);
    for (int i = 0; i < m; i++){
        int mn = 1e9;
        // cout << "D: " << d << endl;
        for (int l = 0, r = queries[i]-1; r < n; l++, r++){
            // cout << l << " " << r << "\n" << seg.query(l, r, 1, 0, n-1) << endl;
            mn = min(mn, seg.query(l, r, 1, 0, n-1));
        }
        b[i] = mn;
    }
    return b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> a(n), b(k);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];

    solve(a, b);
    return 0;
}