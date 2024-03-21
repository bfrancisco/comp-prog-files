#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int NINF = -1e9;

ll tria(ll x){
    return x*(x+1)/2;
}

ll f(ll u, ll v){
    if (u > v){
        return tria(u) - tria(u-v);
    }
    else if (u==v || u == v+1){
        return tria(u);
    }
    return tria(u) - tria(v-u-1);
}
void solve(){
    int n; cin >> n;
    vector<int> a(n+1), pref(n+1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    // for (auto e : pref) cout << e << " "; cout << endl;

    int q;
    cin >> q;
    while(q--){
        int l, r; ll u;
        cin >> l >> u;
        r = n;
        int ans = NINF;
        if (u >= pref[r]){
            cout << r << " ";
            continue;
        }
        else if (u < a[l]){
            cout << l << " ";
            continue;
        }

        int ogl = l;

        // for (int i = 1; i <= n; i++){
        //     cout << f(u, pref[i] - pref[ogl-1]) << " ";
        // }cout << endl;

        while (r-l > 100){
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            ll fm1 = f(u, pref[mid1] - pref[ogl-1]);
            ll fm1p1 = f(u, pref[mid1 + 1] - pref[ogl-1]);
            ll fm2 = f(u, pref[mid2] - pref[ogl-1]);
            ll fm2m1 = f(u, pref[mid2 - 1] - pref[ogl-1]);

            // cout << l << " " << mid1 << " " << mid2 << " " << r << endl;
            // cout << fm1 << " " << fm1p1 << " " << fm2m1 << " " << fm2 << endl << endl;
            if (fm1 == fm2 || fm1==fm1p1){
                ans = mid1;
                break;
            }
            else if (fm2 == fm2m1){
                ans = mid2-1;
                break;
            }
            if (fm1p1-fm1 > 0 && (fm2-fm2m1) > 0){
                l = mid2;
            }
            else if (fm1p1-fm1 > 0 && (fm2-fm2m1) < 0){
                l = mid1; r = mid2;
            }
            else if (fm1p1-fm1 < 0 && (fm2-fm2m1) < 0){
                r = mid1;
            }
        }

        if (ans == NINF){
            ll mxv = -1e18;
            int ind = -1;
            for (int i = l; i <= r; i++){
                if (mxv < f(u, pref[i] - pref[ogl-1])){
                    mxv = f(u, pref[i] - pref[ogl-1]);
                    ind = i;
                }
            }
            ans = ind;
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}