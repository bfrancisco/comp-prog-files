#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> dams(n);
    for (int i = 0; i < n; i++){
        cin >> dams[i];
        dams[i] *= 2ll;
    }

    ll sm = 0;
    int flp = 1;
    for (int i = n-2; i >= 1; i--){
        if (flp) sm += dams[i];
        else sm -= dams[i];
        flp = 1 - flp;
    }
    if (flp == 0) flp = -1;

    ll last2, last, good = -1;
    for (ll first = 0; first <= dams[0]; first += 2ll){
        last2 = sm + flp*first;
        last = dams[n-1] - last2;
        if (first + last == dams[0]) good = first;
    }

    assert(good != -1);
    vector<ll> ans(n);
    ans[0] = good;

    for (int i = 1; i < n; i++){
        ans[i] = dams[i] - ans[i-1];
    }

    // for (auto e : ans) cout << e << " "; cout << endl;

    cout << ans[n-1] << " ";
    for (int i = 0; i < n-1; i++) cout << ans[i] << " ";
    cout << endl;

    
    return 0;
}