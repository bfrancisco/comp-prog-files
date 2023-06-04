#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[1000001], a[101];
ll n, x;

void f(ll v){
    if (v > x) return;
    for (ll i = 0; i < n; i++){
        if (v - a[i] >= 0){
            dp[v] = min(dp[v], 1 + dp[v-a[i]]);
        }
    }
    f(v+1);  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> x;
    for (ll i = 0; i <= x; i++){
        dp[i] = 1e10;
    }
    dp[0] = 0;
    for (ll i = 0; i < n; i++) cin >> a[i];

    f(0);
    // for (ll i = 0; i <= x; i++){
    //     cout << dp[i] << endl;
    // }
    cout << (dp[x] == 1e10 ? -1 : dp[x]) << endl;

    return 0;
}