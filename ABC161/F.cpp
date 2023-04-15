#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
 
    ll ans = 1;
    ll n1 = n-1;
 
    for (ll i = 1; i * i <= n1; i++){
        if (n1%i == 0){
            if (i != 1) ans++;
            if (i*i != n1) ans++;
        }
    }
 
    for (ll i = 2; i * i <= n; i++){
        ll m = n;
        while (m%i==0) m /= i;
        if (m % i == 1 && m != n) ans++;
    }
    cout << ans << endl;
    
    return 0;
}