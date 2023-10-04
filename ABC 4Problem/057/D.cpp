#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll nCr(ll n, ll r)
{
    ll p = 1, k = 1;
 
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
 
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
 
    else
        p = 1;
 
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int a, b; cin >> a >> b;

    ll ar[51];
    unordered_map<ll, ll> freq;
    for (int i = 0; i < n; i++){
        cin >> ar[i];
        if (freq.find(ar[i]) == freq.end()){
            freq[ar[i]] = 1LL;
        }
        else freq[ar[i]] ++;
    }

    sort(ar, ar+n);
    
    unordered_map<ll, ll> need;
    double num = 0, den = 0;
    int j;
    for (int i = 1; i <= a; i++){
        j = n-i;
        if (need.find(ar[j]) == need.end()){
            need[ar[j]] = 1;
        }
        else need[ar[j]] ++;

        num += ar[j];
        den += 1;
    }

    double mxavg = num / den;
    
    ll ans = 1;
    for (auto e : need){
        ans *= nCr(freq[e.first], e.second);
    }
    cout.precision(15);
    cout << fixed << mxavg << endl;
    cout << ans;


    return 0;
}