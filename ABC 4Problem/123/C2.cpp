#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll c[6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    ll mn = 1e16;
    for (int i = 0; i < 5; i++){
        ll v; cin >> v;
        mn = min(mn, v);
    }

    cout << (n+mn-1) / mn + 4 << endl;
    
    
    return 0;
}