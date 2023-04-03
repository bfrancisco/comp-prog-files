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