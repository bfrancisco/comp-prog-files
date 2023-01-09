#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;
    ll x[101];
    ll y[101];
    ll h[101];
    ll limit = 100;
    for (ll i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> h[i];
    
    // h[0] should not be 0
    for (ll k = 1; k < n; k++){
        if (h[k] > 0){
            swap(h[k], h[0]);
            swap(x[k], x[0]);
            swap(y[k], y[0]);
            break;
        }
    }

    for (ll i = 0; i <= limit; i++){
        for (ll j = 0; j <= limit; j++){
            bool pas = true;
            
            ll H = max(h[0] + abs(x[0] - i) + abs(y[0] - j), 0LL);
            for (ll k = 0; k < n; k++){
                if (max(H - abs(x[k] - i) - abs(y[k] - j), 0LL) != h[k]){
                    pas = false;
                    break;
                }
            }
            
            if (pas){
                cout << i << " " << j << " " << H << endl;
                return 0;
            }
        }
    }
 
    
 
    return 0;
}