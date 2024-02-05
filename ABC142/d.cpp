#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll a, b; cin >> a >> b;
    ll tmpa = a, tmpb = b;
    set<ll> A, B;
    ll p = 2;
    for (ll p = 2; p*p <= a; p++){
        while (a%p == 0){
            a /= p;
            A.insert(p);
        }
    }
    if (a > 1){
        A.insert(a);
    }
    for (ll p = 2; p*p <= b; p++){
        while (b%p == 0){
            b /= p;
            B.insert(p);
        }
    }
    if (b > 1){
        B.insert(b);
    }
    
    ll ans = 1;
    for (auto p : A){
        if (B.find(p) != B.end()) ans++;
    }
    cout << ans << endl;
    
    return 0;
}