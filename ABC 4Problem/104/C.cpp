#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll d, g; cin >> d >> g;
    vector<ll> p(d), c(d);
    for (int i = 0; i < d; i++){
        cin >> p[i] >> c[i];
    }

    ll ans = 1e18;
    for (int bit = 0; bit < (1<<d); bit++){
        ll sm = 0;
        int high = 0;
        ll val = 0;
        for (int i = 0; i < d; i++){
            if (bit & (1<<i)){
                sm += p[i]*100*(i+1) + c[i];
                val += p[i];
            }
            else high = i+1;
        }
        if (sm < g){
            // process remaining
        }
        
        ans = min(ans, val);
    }
    cout << ans << endl;
    return 0;
}