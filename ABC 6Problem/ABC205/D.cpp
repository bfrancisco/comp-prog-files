#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, q;
vector<ll> a;

int bs(ll val){
    // "returns # of elements to the left"
    int l = 0, r = n, mid;
    while (r-l > 1){
        mid = (l+r) / 2;
        if (val <= a[mid])
            r = mid;
        else
            l = mid;
    }
    if (val >= a[r]) return r;
    else return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> q;
    a.resize(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {cin >> a[i];}

    while (q--){
        ll x; cin >> x;
        
        int lefts = bs(x);
        ll cur = x + lefts;
        // cout << "lefts : " << lefts << endl;
        while(true){
            int rlefts = bs(cur);
            // cout << "rlefts : " << rlefts << endl;
            if (lefts == rlefts) break;
            lefts = rlefts;
            cur = x + lefts;
        }
        cout << cur << endl;
    }

    return 0;
}