#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll L, R;
    cin >> L >> R;
    ll ans = 2e9 + 5;
    ll MOD = 2019;

    vector<ll> a;
    for (int i = 0; i < min(2019ll, (R-L)+1); i++){
        a.push_back(L+i);
    }
    int n = a.size();

    // for (auto e : a) cout << e << " "; cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            ans = min(ans, (a[i]*a[j])%MOD);
        }
    }
    cout << ans << endl;
    
    return 0;
}