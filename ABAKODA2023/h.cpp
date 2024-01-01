#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dbl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    vector<ll> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) d[i] = b[i] - a[i];

    ll L = 0, R = 0;
    L += d[0];
    for (int i = 1; i < n; i++) R += d[i];
    for (ll m = 1; m < n; m++){
        ll valL = round((dbl)L / (dbl)m);
        ll valR = round((dbl)R / (dbl)(n-m));

        // towards zero
        ll sL = 1e18, sR = 1e18;
        // ll sL = L - valL*m;
        // ll sR = R - valR*(n-m);
        
        for (ll j = -1; j <= 1; j++){
            if (abs(L - (valL+j)*m) < abs(sL)){
                sL = L - (valL+j)*m;
            }
            if (abs(R - (valR+j)*(n-m)) < abs(sR)){
                sR = R - (valR+j)*(n-m);
            }
        }

        cout << "L: " << L << endl;
        cout << "R: " << R << endl;
        cout << "valL: " << valL << endl;
        cout << "valR: " << valR << endl;
        cout << "sL: " << sL << endl;
        cout << "sR: " << sR << endl;
        cout << "ans: " << abs(sL) + abs(sR) << endl << endl;
        // cout << abs(sL) + abs(sR) << " ";

        L += d[m];
        R -= d[m];
    }
    cout << endl;

    return 0;
}