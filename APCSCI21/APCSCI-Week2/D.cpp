#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve(){
    ll n; cin >> n;
    ll N = pow(2, n);
    pair<ll, ll> a[N];
    map<ll, ll> db;
    for (ll i = 0; i < N; i++) {
        pair<ll, ll> temp;
        cin >> temp.first;
        temp.second = i;
        a[i] = temp;
        db[temp.second] = temp.first;
    }
    sort(a, a+N, greater<pair<ll,ll>>());
    //for (ll i = 0; i < N; i++) cout << "[" << a[i].first << ',' << a[i].second << "] ";
    //cout << endl;
    vector<ll> out(N+1, -1);

    ll l = 0, r = 1;
    ll ogL = a[0].second, ogR = a[1].second;
    ll orscore;
    //cout << l << " " << r << endl;
    while (ogL != 0 && ogR != 0){
        //cout << ogL << " " << ogR << endl;
        orscore = ogL | ogR;
        out[orscore] = a[l].first + a[r].first;
        //cout << out[orscore] << endl;
        
        ll lk = r+1, rk = r+1;
        
        while ((a[l].second | a[lk].second) >= orscore){
            if (lk >= N-1) break;
            lk++;
            
        }
        //cout << l << " " << lk << endl;
        while ((a[r].second | a[rk].second) >= orscore){
            if (rk >= N-1) break;
            rk++;
        }
        //cout << r << " " << rk << endl;

        if (a[l].first + a[lk].first >= a[r].first + a[rk].first){
            r = lk;
        }
        else{
            l = r; r = rk;
        }
        ogL = a[l].second; ogR = a[r].second;
    }

    ll hi = max(ogL, ogR), lo = min(ogL, ogR);
    do {
        out[hi] = db[hi] + db[lo];
        hi--;
    } while(hi > 0);

    ll prevout;
    for (ll i = 1; i < N; i++){
        if (out[i] != -1){
            prevout = out[i];
            cout << prevout << endl;
        }
        else cout << prevout << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    //cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}