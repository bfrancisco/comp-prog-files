#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m; cin >> n >> m;
    priority_queue<ll> pq;
    for (int i = 0 ; i< n; i++){
        ll x; cin >> x;
        pq.push(x);
    }
    while(m--){
        ll x = pq.top();
        pq.pop();
        x /= 2ll;
        pq.push(x);
    }
    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}