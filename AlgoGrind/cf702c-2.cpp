#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int n, m;
vector<ll> city, cell;

void solve(){
    cin >> n >> m;
    city.resize(n);
    cell.resize(m);
    vector<pair<int, int>> all;
    for (int i = 0; i < n; i++){
        cin >> city[i];
        all.push_back({city[i], 1});
    }
    for (int i = 0; i < m; i++){
        cin >> cell[i];
        all.push_back({cell[i], 0});
    }

    sort(all.begin(), all.end());

    // for (auto [a, b] : all) cout << a << " " << b << endl;

    // from left, from right
    vector<ll> le(n), ri(n), mn(n);
    ll ci = -1e10;
    ll ti = 0;
    for (int i = 0; i < n+m; i++){
        if (all[i].second == 0){
            ci = all[i].first;
        }
        else{
            le[ti] = abs(ci - all[i].first);
            ti++;
        }
    }
    ci = 1e10;
    ti = n-1;
    for (int i = n+m-1; i >= 0; i--){
        if (all[i].second == 0){
            ci = all[i].first;
        }
        else{
            ri[ti] = abs(ci - all[i].first);
            ti--;
        }
    }
    for (int i = 0; i < n; i++){
        mn[i] = min(le[i], ri[i]);
    }

    // for (auto e : le) cout << e << " "; cout << endl;
    // for (auto e : ri) cout << e << " "; cout << endl;
    
    cout << *max_element(mn.begin(), mn.end()) << endl;

}

int main(){
    // int t; cin >> t;
    int t = 1;
    while (t--){
        solve();
    }
    
    return 0;
}