#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m, t;
    cin >> n >> m >> t;
    ll orign = n;
    vector<ll> vec(m*2+2);
    vec[0] = 0;
    vec[m*2+1] = t*2;
    for (int i = 1; i <= m*2; i+=2){
        ll a, b; cin >> a >> b;
        vec[i] = a*2;
        vec[i+1] = b*2;
    }

    for (int i = 0; i < m*2+1; i++){
        ll val = (vec[i+1] - vec[i]) / 2;
        if (i%2 == 0){
            n -= val;
        }
        else{
            n = min(n+val, orign);
        }
        if (n <= 0){cout << "No"; return 0;}
    }

    cout << "Yes";
    return 0;
}   