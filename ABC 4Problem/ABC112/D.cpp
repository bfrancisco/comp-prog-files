#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    ll ans = -1;
    for (ll i = 1; i*i <= m; i++){
        if (m%i == 0){
            if (n*i <= m){
                ans = max(ans, i);
            }
            if (n*(m/i) <= m){
                ans = max(ans, m/i);
            }
        }
    }
    cout << ans;
    return 0;
}