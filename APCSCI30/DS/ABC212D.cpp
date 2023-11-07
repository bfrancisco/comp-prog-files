#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int q; cin >> q;
    ll delta = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (q--){
        int x; cin >> x;
        if (x == 1){
            ll v; cin >> v;
            pq.push(v - delta);
        }
        else if (x == 2){
            ll v; cin >> v;
            delta += v;
        }
        else {
            cout << pq.top() + delta << endl;
            pq.pop();
        }
    }
    
    return 0;
}