#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1000000007;
struct{
    bool operator()(ll a, ll b) const { return abs(a) < abs(b);}
}
abscomp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k; cin >> n >> k;
    ll KORIG = k;
    vector<ll> a(n);
    int pos = 0, neg = 0, zer = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > 0) pos++;
        else if (a[i] < 0) neg++;
        else zer++;
    }
    sort(a.begin(), a.end());

    if (pos + neg < k){cout << 0 << endl; return 0;}
    
    // ideas
    // should get negatives twice in one operation
    // not necessary to get all positives

    int l = 0, r = n-1;
    ll ans = 1;
    if (k%2){ans *= a[r]; r--; k--;}

    while (k){
        if (r-l == 1){
            ans *= a[l]; ans %= mod;
            ans *= a[r]; ans %= mod;
            break;
        }
        ll left, right;
        left = a[l]*a[l+1];
        right = a[r]*a[r-1];

        if (left >= right){
            ans *= a[l]; ans %= mod;
            ans *= a[l+1]; ans %= mod;
            l += 2;
        }
        else{
            ans *= a[r]; ans %= mod;
            ans *= a[r-1]; ans %= mod;
            r -= 2;
        }
        k-=2;
    }
    ll ans2 = 0;
    // cout << ans << " " << ans2 << endl;
    if (ans < 0){
        ans2 = 1ll;
        sort(a.begin(), a.end(), abscomp);
        for (int i = 0; i < KORIG; i++){
            ans2 *= a[i]; ans2 %= mod;
        }
        ans2 = (ans2 < 0 ? ans2 + mod : ans2);
        cout << ans2 << endl;
        return 0;
    }
    ans = (ans < 0 ? ans + mod : ans);
    cout << ans << endl;
    return 0;
}