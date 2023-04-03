#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll n, l, r, x, ans = 0;
vector<ll> a;

void rec(string s){
    //cout << s << endl;
    if (s.size() == n){
        ll val = 0, c = 0, mx = -1, mn = 1e9;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                val += a[i];
                c ++;
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            }
        }
        if (c > 1 && val >= l && val <= r && abs(mn-mx) >= x){
            ans ++;
            // cout << s << endl;
            // cout << mn << " " << mx << endl;
        }
        return;
    }
    rec(s + '0');
    rec(s + '1');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++){
        ll t; 
        cin >> t;
        a.push_back(t);
    }
    rec("");
    cout << ans;
    return 0;
}