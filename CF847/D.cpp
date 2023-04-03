#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<ll, ll> db;
    set<ll> rev;
    for (int i = 0; i < n; i++){
        if (db.find(a[i]) == db.end()){
            db[a[i]] = 1;
            rev.insert(-a[i]);
        }
        else
            db[a[i]] ++;
    }

    // for (auto x : rev) cout << -x << " ";
    // cout << endl;
    ll ans = 0;

    while (!rev.empty()){
        ll mn = 1e12;
        ll prev = -(*rev.begin());
        for (auto x : rev) cout << -x << " ";
        cout << endl;
        for (auto x : rev){
            ll y = -x;
            cout << y << endl;
            if (-x==y) continue;
            if (y+1 != prev){
                cout << mn << endl;
                ans += mn;
                for (auto e : rev){
                    ll eval = -e;
                    
                    db[eval] -= mn;
                    if (db[eval] <= 0){
                        db.erase(eval);
                        rev.erase(-eval);
                    }
                    if (eval == prev) break;
                }
                break;
            }
            else{
                mn = min(mn, db[y]);
                cout << mn << endl;
                prev = y;
            }
        }
    }

    cout << ans << endl;

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