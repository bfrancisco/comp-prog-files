#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; ll sx, sy;
    cin >> n >> sx >> sy;
    
    vector<pair<ll, char>> HV(n);
    ll htot = 0, vtot = 0;
    for (int i = 0; i < n; i++){
        ll val; char ori;
        cin >> val >> ori;
        HV[i] = {val, ori};
        if (ori == 'H') htot += val;
        else vtot += val;
    }
    vector<pair<ll, int>> Hsort, Vsort;
    for (int i = 0; i < n; i++){
        if (HV[i].second == 'H'){
            Hsort.push_back({HV[i].first, i});
        }
        else{
            Vsort.push_back({HV[i].first, i});
        }
    }
    sort(Hsort.begin(), Hsort.end(), greater<pair<ll, int>>());
    sort(Vsort.begin(), Vsort.end(), greater<pair<ll, int>>());
    int hsn = Hsort.size(), vsn = Vsort.size();

    // check if can reach 0,0
    if (htot < abs(sx) || vtot < abs(sy)) { cout << "NOa" << endl; return; }

    // case when cant change parity (all are 1)
    if ((!Hsort.empty() && Hsort[0].first == 1 && hsn%2 != sx%2) || 
        (!Vsort.empty() && Vsort[0].first == 1 && vsn%2 != sy%2)){
        cout << "NOb" << endl; return;
    }

    // cout << "Hsort: "; for (auto [x, i] : Hsort) cout << x << " "; cout << endl;
    // cout << "Vsort: "; for (auto [x, i] : Vsort) cout << x << " "; cout << endl << endl;

    vector<ll> ans(n, 0);
    // remove 1 <= k constraint
    for (int i = 0; i < hsn; i++){
        if (sx <= 0) { ans[Hsort[i].second]++; sx++; }
        else { ans[Hsort[i].second]--; sx--; }
        Hsort[i].first--;
    }
    for (int i = 0; i < vsn; i++){
        if (sy <= 0) { ans[Vsort[i].second]++; sy++; }
        else { ans[Vsort[i].second]--; sy--; }
        Vsort[i].first--;
    }

    // cout << "Hsort: "; for (auto [x, i] : Hsort) cout << x << " "; cout << endl;
    // cout << "Vsort: "; for (auto [x, i] : Vsort) cout << x << " "; cout << endl; cout << endl;

    for (int i = 0; i < n; i++){
        cout << HV[i].second << " " << ans[i] << endl;
    } cout << endl;

    // cout << "CURRENT: " << sx << " " << sy << endl;

    // go 0,0
    // process X
    for (int i = 0; i < hsn; i++){
        if (sx < 0){
            if (sx + Hsort[i].first >= 0){
                ans[Hsort[i].second] += (-sx);
                // Hsort[i].first -= (-sx);
                sx = 0;
            }
            else{
                sx += Hsort[i].first;
                ans[Hsort[i].second] += Hsort[i].first;
                // Hsort[i].first = 0;
            }
        }
        else if (sx > 0){
            if (sx - Hsort[i].first <= 0){
                ans[Hsort[i].second] -= (sx);
                // Hsort[i].first -= (sx);
                sx = 0;
            }
            else{
                sx -= Hsort[i].first;
                ans[Hsort[i].second] -= Hsort[i].first;
                // Hsort[i].first = 0;
            }
        }
    }
    // process Y
    for (int i = 0; i < vsn; i++){
        if (sy < 0){
            if (sy + Vsort[i].first >= 0){
                ans[Vsort[i].second] += (-sy);
                // Vsort[i].first -= (-sy);
                sy = 0;
            }
            else{
                sy += Vsort[i].first;
                ans[Vsort[i].second] += Vsort[i].first;
                // Vsort[i].first = 0;
            }
        }
        else if (sy > 0){
            if (sy - Vsort[i].first <= 0){
                ans[Vsort[i].second] -= (sy);
                // Hsort[i].first -= (sx);
                sy = 0;
            }
            else{
                sy -= Vsort[i].first;
                ans[Vsort[i].second] -= Vsort[i].first;
                // Hsort[i].first = 0;
            }
        }
    }
    
    int pas = 1;
    for (auto e : ans) if (e == 0) pas = 0;
    if (!pas){ cout << "NOc" << endl; return; }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
        if (HV[i].second == 'H'){
            cout << abs(ans[i]) << " " << (ans[i] > 0 ? "E" : "W") << endl;
        }
        else{
            cout << abs(ans[i]) << " " << (ans[i] > 0 ? "N" : "S") << endl;
        }
    }

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