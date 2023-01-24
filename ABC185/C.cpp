#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll C(ll n, ll k) {
    if(k < 0 or k > n) return 0;
    k = min(k, n - k);
    ll ans = 1;
    for(ll i = 0; i < k; i++) {
        ans *= n - i;
        ans /= i + 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    cout << C(n-1, 11);

    
    return 0;
}   