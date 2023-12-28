#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; ll sx, sy;
    cin >> n >> sx >> sy;
    
    vector<pair<ll, char>> HV(n);
    ll htot = 0, vtot = 0;
    int hs = 0, vs = 0;
    for (int i = 0; i < n; i++){
        ll val; char ori;
        cin >> val >> ori;
        HV[i] = {val-1, ori};
        if (ori == 'H') hs++;
        else vs++;
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