#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n; ll t;

ll tymtook(int k, vector<ll>& a){
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int i = 0;
    for (; i < k; i++) pq.push(a[i]);
    ll delta = 0;
    while(!pq.empty()){
        ll mn = pq.top();
        while(pq.top() == mn){
            pq.pop();
            if (pq.empty()) break;
        }
        delta += mn - delta;
        while(i < n && pq.size() < k){
            pq.push(a[i] + delta);
            i++;

        }
    }
    return delta;
}

void solve(){
    cin >> n >> t;
    vector<ll> a(n);
    ll mx = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (t < mx){
        cout << "NO" << endl;
        return;
    }

    int l = 1, r = n, ans;
    while (l <= r){
        int mid = (l+r)/2;
        // cout << l << " " << mid << " " << r << endl; 
        if (tymtook(mid, a) <= t){
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }
    cout << "YES\n" << ans << endl;
    
    // for (int i = 1; i <= n; i++){
    //     cout << i << " " << tymtook(i, a) << endl;
    // }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}