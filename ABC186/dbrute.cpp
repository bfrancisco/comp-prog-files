#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n), pref(n);
    ordered_set s;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s.insert({a[i], i});
    }
    for (auto &[k, v] : s){
        pref[i] = pref[i-1] + a[i];
    }

    cout << s.order_of_key({5, 0}) << endl; 
    for (int i = 0; i < n-1; i++){
        ans += s.order_of_key({a[i], i})*a[i]   
    }    
    return 0;
}