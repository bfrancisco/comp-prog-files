#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, h;
    cin >> n >> h;
    vector<pair<ll, pair<ll, ll>>> dagger; // first - value, secondfirst - {0 - a, 1 - b}
    // second second - ith orig
    
    for (ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        dagger.push_back({a, {0, i}});
        dagger.push_back({b, {1, i}});
    }

    sort(dagger.begin(), dagger.end(), greater<pair<ll, pair<ll, ll>>>());
    // for (auto e : dagger){
    //     cout << e.second.second << endl;
    // }
    
    ll m = dagger.size();
    ll ia; // highest a;
    ll dmg = 0, hits = 0;
    unordered_set<ll> used;
    ll unused_ia = -1;
    for (ll i = 0; i < m; i++){
        ll x = dagger[i].first, y = dagger[i].second.first;
        cout << x << " ";
        if (y == 1){
            dmg += x;
            hits++;
            used.insert(dagger[i].second.second);
        }
        else{
            ia = i;
            break;
        }
    }
    cout << endl << endl;

    for (ll i = 0; i < m; i++){
        ll x = dagger[i].first, y = dagger[i].second.first;
        if (y == 0){
            if (used.find(dagger[i].second.second) == used.end()){
                unused_ia = i;
            }
        }
    }
    if (h - dmg <= 0){
        cout << hits;
        return 0;
    }

    // two scenarios:
    // 1 - subtract the used dagger to spam the highest a dagger
    // 2 - use the unused highest a dagger


    // SCENARIO 1
    // find highest a counterpart
    ll ib;
    ll hits2 = hits;
    ll h2 = h;
    ll dmg2 = dmg;
    for (ll i = 0; i < m; i++){
        if (dagger[i].second.second == dagger[ia].second.second){
            ib = i;
            break;
        }
    }
    dmg2 -= dagger[ib].first;
    hits2--;

    h2 -= dmg2;
    cout << h2 << " " << dagger[ia].first << " " << ceil((double)h2 / (double)dagger[ia].first) << endl; 
    hits2 += ceil((double)h2 / (double)dagger[ia].first);


    ll hits3 = 1e12;
    if (unused_ia != -1){
        h -= dmg;
        hits3 = hits + ceil((double)h / (double)dagger[unused_ia].first);
    }
    cout << dagger[unused_ia].first << endl;
    cout << hits << " " << hits2 << " " << hits3 << endl;
    cout << min(hits2, hits3);
    return 0;
}