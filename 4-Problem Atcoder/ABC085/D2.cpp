#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, h;
    cin >> n >> h;
    vector<pair<ll, ll>> dagger; // first - value, secondfirst - {0 - a, 1 - b}
    // second second - ith orig
    
    for (ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        dagger.push_back({a, 1});
        dagger.push_back({b, 0});
    }

    sort(dagger.begin(), dagger.end(), greater<pair<ll, ll>>());
    
    ll m = dagger.size();
    ll ia; // highest a;
    ll hits = 0;
    for (ll i = 0; i < m; i++){
        ll x = dagger[i].first, y = dagger[i].second;
        // cout << x << " ";
        
        if (y == 0){
            hits++;
            h -= x;
        }
        else{
            ia = i;
            break;
        }
        if (h <= 0){
            cout << hits;
            return 0;
        }
        
    }


    if (h > 0){
        hits += ceil((double)(h) / (double)dagger[ia].first);
    }

    
    cout << hits;
    return 0;
}