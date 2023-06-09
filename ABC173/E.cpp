#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1000000007;

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
    // 1 - should get negatives twice in one operation
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

    if (ans < 0){
        vector<ll> negs;
        for (auto e : a){
            if (e >= 0) break;
            negs.push_back(e);
        }
        ans = 1;
        for (int i = negs.size()-1, kn = KORIG; i >= 0 && kn > 0; i--, kn--){
            ans *= negs[i]; ans %= mod;
        }
    }
    cout << (ans < 0 ? ans + mod : ans) << endl;
    return 0;
}