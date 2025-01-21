#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll compute(int n, int m, vector<pair<ll, ll>> dx, vector<pair<ll, ll>> cy){
    ll ret = 0;
    int l = 0, r = 0;
    while (l < n && r < m){
        if (dx[l].second < cy[r].second){
            ret += dx[l].first * cy[r].first * dx[l].second;
            cy[r].second -= dx[l].second;
            l++;
        }
        else if (cy[r].second < dx[l].second){
            ret += dx[l].first * cy[r].first * cy[r].second;
            dx[l].second -= cy[r].second;
            r++;
        }
        else{
            ret += dx[l].first * cy[r].first * cy[r].second;
            l++;
            r++;
        }
    }
    return ret;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> dx(n), cy(m);
    for (int i = 0; i < n; i++) cin >> dx[i].second;
    for (int i = 0; i < n; i++) cin >> dx[i].first;
    for (int i = 0; i < m; i++) cin >> cy[i].second;
    for (int i = 0; i < m; i++) cin >> cy[i].first;


    sort(dx.begin(), dx.end(), greater<pair<ll, ll>>());
    sort(cy.begin(), cy.end(), greater<pair<ll, ll>>());

    cout << compute(n, m, dx, cy) << " ";

    for (int i = 0; i < m/2; i++) swap(cy[i], cy[m-i-1]);
    ll mn = compute(n, m, dx, cy);
    for (int i = 0; i < m/2; i++) swap(cy[i], cy[m-i-1]);
    for (int i = 0; i < n/2; i++) swap(dx[i], dx[n-i-1]);
    mn = min(mn, compute(n, m, dx, cy));
    cout << mn << endl;

    // cout << endl << "DX: "; for (auto [a, b] : dx) cout << "(" << a << ", " << b << ") "; cout << endl; 
    // cout << "CY: "; for (auto [a, b] : cy) cout << "(" << a << ", " << b << ") "; cout << endl; 

}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}