#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll k, n; cin >> k >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll A = 0;
    ll mx = -1;
    for (int i = 1; i < n; i++){
        A += abs(a[i] - a[i-1]);
        mx = max(mx, a[i] - a[i-1]);
    }
    A += (abs(a[n-1] - (k + a[0])));
    mx = max(mx, abs(a[n-1] - (k + a[0])));
    cout << A - mx << endl;
    return 0;
}