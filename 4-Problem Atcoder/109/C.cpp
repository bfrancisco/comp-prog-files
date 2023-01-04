#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    ll a[100010];
    for (int i = 0; i < n+1; i++)
        cin >> a[i];
    
    vector<ll> b;
    for (int i = 1; i < n+1; i++){
        b.push_back(abs(a[i] - a[i-1]));
    }

    ll ans = gcd(b[0], b[1]);
    for (ll i = 2; i < b.size(); i++){
        ans = gcd(ans, b[i]);
    }
    
    cout << ans;

    return 0;
}