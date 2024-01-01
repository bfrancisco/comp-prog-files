#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    vector<ll> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) d[i] = b[i] - a[i];

    ordered_set L, R;
    ll Lnsum, Lpsum, Rnsum, Rpsum;
    ll Lnc = 0, Lpc = 0, Rnc = 0, Rpc = 0;

    L.insert({d[0], 0});

    if (d[0] < 0) { Lnsum += d[0]; Lnc++; }
    else { Lpsum += d[0]; Lpc++; }
    
    for (int i = 1; i < n; i++){
        R.insert({d[i], i});

        if (d[i] < 0) { Rnsum += d[i]; Rnc++; }
        else { Rpsum += d[i]; Rpc++; }
    }

    // cout << "Lnsum: " << Lnsum << " Lpsum: " << Lpsum << endl;
    // cout << "Rnsum: " << Rnsum << " Rpsum: " << Rpsum << endl;

    // for (auto [v, i] : L) cout << v << " "; cout << endl;
    // for (auto [v, i] : R) cout << v << " "; cout << endl;

    for (auto v : d) cout << v << " "; cout << endl << endl;

    for (int m = 1; m < n; m++){
        ll Lmed = 0, Rmed = 0;

        if (m%2){
            Lmed = (L.find_by_order((int)(m/2)))->first;
        }
        else{
            ll midl = (L.find_by_order((int)(m/2 - 1)))->first;
            ll midr = (L.find_by_order((int)(m/2)))->first;
            Lmed = (midl+midr)/2;
        }
        if ((m-n)%2){
            Rmed = (R.find_by_order((int)((n-m)/2)))->first;
        }
        else{
            ll midl = (R.find_by_order((int)((n-m)/2 - 1)))->first;
            ll midr = (R.find_by_order((int)((n-m)/2)))->first;
            Rmed = (midl+midr)/2;
        }

        ll Lnega, Lposi, Rnega, Rposi;
        Lnega = Lnsum - Lmed*Lnc;
        Lposi = Lpsum - Lmed*Lpc;
        Rnega = Rnsum - Rmed*Rnc;
        Rposi = Rpsum - Rmed*Rpc;

        cout << "m: " << m << endl;
        cout << Lnsum << " " << Lpsum << " " << Rnsum << " " << Rpsum << endl;
        cout << Lmed << " " << Rmed << endl;
        cout << Lnega << " " << Lposi << " " << Rnega << " " << Rposi << endl;
        cout << abs(Lnega) + abs(Lposi) + abs(Rnega) + abs(Rposi) << endl << endl;
        // cout << abs(Lnega) + abs(Lposi) + abs(Rnega) + abs(Rposi) << " ";

        L.insert({d[m], m});
        R.erase({d[m], m});
        if (d[m] < 0){
            Lnsum += d[m];
            Lnc++;
            Rnsum -= d[m];
            Rnc--;
        }
        else{
            Lpsum += d[m];
            Lpc++;
            Rpsum -= d[m];
            Rpc--;
        }

    }
    cout << endl;

    return 0;
}