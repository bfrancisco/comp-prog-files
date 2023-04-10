#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    ll z = -3e9;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int l = 0;
    for (int i = 0; i < n-1; i++){
        if (a[i] > a[i+1]){
            l = i;
        }
    }
    for (int i = l; i < n-1; i++){
        a[i+1] -= a[i];
        a[i] = 0;
        
    }
 
    if (a[n-1] < 0) cout << "NO" << endl;
    else cout << "YES" << endl;

    cout << a[n-1] << endl;
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}
