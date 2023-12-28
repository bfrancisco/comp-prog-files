#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) d[i] = abs(a[i] - b[i]);

    ll L = 0, R = 0;
    L += d[0];
    for (int i = 1; i < n; i++) R += d[i];
    for (int m = 1; m < n; m++){
        ll valL = L/m;
        ll valR = R/(n-m);
        ll mn = abs(L - valL*m) + abs(R - valR*(n-m));
        mn = min(mn, abs(L - (valL+1)*m) + abs(R - valR*(n-m)));
        mn = min(mn, abs(L - valL*m) + abs(R - (valR+1)*(n-m)));
        mn = min(mn, abs(L - (valL+1)) + abs(R - (valR+1)*(n-m)));
        cout << mn << " ";

        L += d[m];
        R -= d[m];
    }
    cout << endl;

    return 0;
}