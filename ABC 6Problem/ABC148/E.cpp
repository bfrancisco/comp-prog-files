#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;

    ll ans = 0LL;
    ll div = 10LL;
    while (n >= div){
        ans += (int)(n/div);
        div *= 5LL;
    }

    cout << ans;
    
    return 0;
}   