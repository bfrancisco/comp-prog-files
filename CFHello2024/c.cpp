#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int MX = 1000000000;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b, c;
    b.push_back(MX);
    c.push_back(MX);
    for (int i = 0; i < n; i++){
        auto& vb = b.back();
        auto& vc = c.back();
        if (vb < vc){
            if (a[i] <= vb) b.push_back(a[i]);
            else if (a[i] > vc) b.push_back(a[i]);
            else c.push_back(a[i]);
        }
        else if (vc < vb){
            if (a[i] <= vc) c.push_back(a[i]);
            else if (a[i] > vb) c.push_back(a[i]);
            else b.push_back(a[i]);
        }
        else{
            b.push_back(a[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < b.size()-1; i++){
        if (b[i] < b[i+1]) ans++;
    }
    for (int i = 0; i < c.size()-1; i++){
        if (c[i] < c[i+1]) ans++;
    }
    // for (auto e : b) cout << e << " "; cout << endl;
    // for (auto e : c) cout << e << " "; cout << endl;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}