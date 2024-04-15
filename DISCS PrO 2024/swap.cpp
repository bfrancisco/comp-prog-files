#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree {
    int n, m;
    vector<vector<int>> vals;
    segtree(vector<pair<int, int>> &ar, int m_in) {
        n = ar.size();
        m = m_in;
        vals.assign(4*n, vector<int>(m, -1));
        build(ar, 1, 0, n-1);
    }
    
    void build(vector<pair<int, int>> &ar, int p, int i, int j) {
        if (i == j){
            for (int i = 0; i < m; i++){
                vals[p][i] = i;
            }
            swap(vals[p][ar[i].first], vals[p][ar[i].second]);
        }
        else{
            int k = (i + j) / 2;
            build(ar, p<<1, i, k);
            build(ar, p<<1|1, k+1, j);
            pull(p);
        }
    }
    
    void pull(int p) {
        for (int i = 0; i < m; i++){
            vals[p][i] = vals[p<<1|1][vals[p<<1][i]];
        }
    }

    // i, j starts at 0, n-1
    void update(int _i, int _j, int a, int b, int p, int i, int j) {
        // query overlaps or equates i, j
        if (_i <= i && j <= _j) {
            // point update
            for (int i = 0; i < m; i++){
                vals[p][i] = i;
            }
            swap(vals[p][a], vals[p][b]);
        }
        // no overlap
        else if (_j < i || j < _i) {}
        else {
            int k = (i + j) / 2;
            update(_i, _j, a, b, p<<1, i, k);
            update(_i, _j, a, b, p<<1|1, k+1, j);
            pull(p);
        }
    }

    void query(int _i, int _j, int p, int i, int j, vector<vector<int>> &opers) {
        if (_i <= i && j <= _j){
            opers.push_back(vals[p]);
        }
        else if (_j < i || j < _i) return;
        else {
            int k = (i + j) / 2;
            query(_i, _j, p<<1, i, k, opers);
            query(_i, _j, p<<1|1, k+1, j, opers);
            pull(p);
        }
    }

    void update(int _i, int _j, int a, int b) {
        update(_i, _j, a, b, 1, 0, n-1);
    }

    void query(int _i, int _j, vector<vector<int>> &opers) {
        return query(_i, _j, 1, 0, n-1, opers);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> perm(m);
    for (int i = 0; i < m; i++){
        cin >> perm[i];
        perm[i]--;
    }

    // for (auto e : perm) cout << e << " "; cout << endl << endl;

    vector<pair<int, int>> swaps(n);
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        swaps[i] = {a, b};
    }

    segtree seg(swaps, m);

    // for (int p = 0; p < seg.vals.size(); p++){
    //     cout << "P: " << p << endl;
    //     for (auto e : seg.vals[p]){
    //         cout << e << " ";
    //     }
    //     cout << endl << endl;
    // }

    int q; cin >> q;
    while (q--){
        string con; cin >> con;
        // cout << con << endl;
        if (con[0] == 'P'){
            int l, r; cin >> l >> r;
            l--; r--;
            vector<vector<int>> opers;
            seg.query(l, r, opers);

            vector<int> cpy(m), out(m);
            for (int i = 0; i < m; i++) cpy[i] = perm[i];

            for (auto &op : opers){
                for (int i = 0; i < m; i++){
                    out[op[i]] = cpy[i];
                }
                for (int i = 0; i < m; i++){
                    cpy[i] = out[i];
                }
            }
            
            for (int i = 0; i < m; i++){
                cout << out[i]+1 << " ";
            }
            cout << endl;
        }
        else{
            int ind, a, b; cin >> ind >> a >> b;
            ind--; a--; b--;
            seg.update(ind, ind, a, b);
        }   
    }
    
    return 0;
}