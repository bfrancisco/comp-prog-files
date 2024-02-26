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
    
    ll n, k; cin >> n >> k;
    vector<ll> A(n);
    for (int i = 0; i < n; i++){
        cin >> A[i];
        A[i] -= k;
    }

    ordered_set vals;
    
    
    return 0;
}