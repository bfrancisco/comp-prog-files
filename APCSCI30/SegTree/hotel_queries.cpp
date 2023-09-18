#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct segtree{
    int n; 
    int *vals;
    segtree(vector<int> &ar, int n){
        this->n = n;
        vals = new int[2*n];
        for (int i = 0; i < n; ++i){
            vals[i+n] = ar[i];
        }

        for (int i =  n-1; i >= 1; --i){
            vals[i] = max(vals[i<<1], vals[(i<<1)|1]); 
        }
    }

    void update(int i, int v){
        for (vals[i] = v; i > 1; i >>= 1){
            vals[i >> 1] = max(vals[i], vals[i^1]);
        }
    }

    int getroom(int cur, int g){
        if (g > vals[cur]) return 0;
        if (cur >= n){
            update(cur, vals[cur] - g);
            // cout << "[update] cur: " << cur << "  vals[cur]: " << vals[cur] << endl;
            return cur - n + 1;
        }

        if (g <= vals[cur<<1]) return getroom(cur<<1, g);
        else return getroom((cur<<1) | 1, g);

    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q; cin >> n >> q;
    vector<int> n2(20);
    n2[0] = 1;
    for (int i = 1; i <= 20; i++){
        n2[i] = n2[i-1] * 2;
    }
    int newN = n2[lower_bound(n2.begin(), n2.end(), n) - n2.begin()];
    vector<int> a(newN);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i < newN; i++) a[i] = 0;
    segtree seg(a, newN);
    while(q--){
        int g; cin >> g;
        cout << seg.getroom(1, g) << " "; 
    }
    cout << endl;

    return 0;
}