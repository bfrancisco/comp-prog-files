#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    ll prev = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        if (prev > x){
            ans += prev-x;
        }
        else prev = x;
    }
    cout << ans << endl;

    return 0;
}