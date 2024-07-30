#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

struct segtree{
    int n, *vals;
    segtree(vector<int> &ar){
        n = ar.size();
        vals = new int[4*n];
        build(ar, 1, 0, n-1);
    }

    void build(vector<int> &ar, int p, int i, int j){
        if (i == j){
            vals[p] = ar[i];
        }
        else{
            int k = (i+j) / 2;
            build(ar, p<<1, i, k);
            build(ar, p<<1|1, k+1, j);
            pull(p);
        }
    }

    void pull(int p){
        vals[p] = vals[p<<1] + vals[p<<1|1];
    }

    void update(int _i, int _j, int v, int p, int i, int j){
        if (_i <= i && j <= _j) {
            vals[p] += v; // just point update for this problem
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

    int query(int _i, int _j, int p, int i, int j){
        if (_i <= i && j <= _j)
            return vals[p];
        else if (_j < i || j < _i)
            return 0;
        else {
            int k = (i + j) / 2;
            return  query(_i, _j, p<<1, i, k) +
                    query(_i, _j, p<<1|1, k+1, j);
        }
    }

    void update(int l, int r, int v){
        update(l, r, v, 1, 0, n-1);
    }

    int query(int l, int r){
        return query(l, r, 1, 0, n-1);
    }
};

int main(){

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    int mn = 1000000001;
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
        mn = min(mn, a[i].first);
    }

    sort(a.begin(), a.end());

    vector<int> tmp(n-k+1, 0); 
    segtree rsq(tmp);


    int prev = mn;
    int l1,r1,l2,r2;
    vector<pair<int, int>> upds;
    for (auto &[val, i] : a){
        if (prev != val){
            // process updates, clear upds
            for (int j = 0; j < upds.size()-1; j++){
                l1 = upds[j].first;
                r1 = upds[j].second;
                l2 = upds[j+1].first;
                r2 = upds[j+1].second;
                if (l2 <= r1){
                    upds[j+1].first = l1;
                    upds[j] = {-1, -1};
                }
            }
            for (auto &[l, r] : upds){
                rsq.update(l, r, 1);
            }
            upds.clear();
        }
        upds.push_back({max(0, i-k+1), i});
        prev = val;
    }
    // process updates, clear upds for the last time
    for (int j = 0; j < upds.size()-1; j++){
        l1 = upds[j].first;
        r1 = upds[j].second;
        l2 = upds[j+1].first;
        r2 = upds[j+1].second;
        if (l2 <= r1){
            upds[j+1].first = l1;
            upds[j] = {-1, -1};
        }
    }
    for (auto &[l, r] : upds){
        if (l == -1) continue;
        rsq.update(l, r, 1);
    }
    
    vector<int> ans(n, (int)1e9);
    // process last window first
    for (int i = 0; i < n-k+1; i++){
        int high = rsq.vals[i];
        cout << high << endl;
        map<int, int> match;
        for (int j = i; j < i+k; j++){
            match[a[j].first] = j;
        }
        int prev = high;
        for (auto &[val, j] : match){
            if (prev != val){ high--; }
            ans[j] = min(ans[j], high);
            prev = val;
        }
    }

    for (auto e : ans) cout << e << " "; cout << endl;

}