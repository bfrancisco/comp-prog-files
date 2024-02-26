#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, a, b; cin >> n >> a >> b;
    vector<ll> V(n);
    for (int i = 0; i < n; i++){
        cin >> V[i];
    }
    
    ll l = 1, r = 1e9;
    ll ans = -1;
    while (l <= r){
        ll t = (l+r)/2;
        ll d = t*b;
        ll c = 0;
        for (auto x : V){
            if (x - d > 0) c += ((x-d)+(a-b)-1) / (a-b);
        }

        if (c <= t){
            r = t-1;
            ans = t;
        }
        else{
            l = t+1;
        }
    }
    cout << ans << endl;
    
    
    
    return 0;
}