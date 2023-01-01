#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, k;
    ll c[1000005];
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        c[a] += b;
    }
    
    for (ll val = 1; val <= 1000000; val++){
        if (k <= c[val]){
            cout << val;
            break;
        }
        k -= c[val]; 
    }
    return 0;
}