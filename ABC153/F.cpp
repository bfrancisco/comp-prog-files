#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; ll d, a;
    cin >> n >> d >> a;

    vector<pair<ll, ll>> v;

    for (int i = 0; i < n; i++){
        ll x, h; cin >> x >> h;
        ll val = (h+a-1) / a;
        v.push_back({x, val});
    }
    
    sort(v.begin(), v.end());
    v.push_back({-1LL , -1LL});
    int l = 0, r = 0;
    ll ans = 0;
    while (r < n){
        ll BOMBS = v[l].second;
        // cout << "l: " << l << endl;
        // cout << BOMBS << endl;
        ans += BOMBS;

        r = l;
        while(v[r].first <= v[l].first + d*2 && v[r].first != -1){
            if (v[r].second - BOMBS < 0) v[r].second = 0;
            else v[r].second -= BOMBS;
            r++;
        }

        bool pas = false;
        for (int i = l+1; i < r; i++){
            if (v[i].second > 0){
                l = i;
                pas = true;
                break;
            }
        }
        if (!pas){
            l = r;
        }
    }

    cout << ans << endl;

    return 0;
}   