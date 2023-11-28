#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    ordered_set ls, gr;
    vector<ll> less(n), great(n);
    for (int i = n-1; i >= 0; i--){
        ls.insert(a[i]);
        less[i] = ls.order_of_key(a[i]);
    }
    for (int i = 0; i < n; i++){
        gr.insert(a[i]);
        great[i] = i-gr.order_of_key(a[i]);
    }
    
    // for (auto x : less) cout << x << " "; cout << endl;
    // for (auto x : great) cout << x << " "; cout << endl;

    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += less[i]*great[i];
    }
    cout << ans;
    return 0;
}