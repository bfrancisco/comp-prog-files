#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll h; 
ll ans = 0;

ll f(ll x){
    if (x == 1){
        return 1;
    }
    
    ll val  = x/2;
    return 1 + f(val) * 2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> h;

    cout << f(h);

    
    return 0;
}   