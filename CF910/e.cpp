#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(ll x){
    return (x)*(x-1)/2;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int mn = 1e9+10;
    int ind = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < mn){
            mn = a[i];
            ind = i;
        }
    }
    int ans = ind;
    for (int i = ind+1; i < n; i++){
        if (a[i-1] > a[i]){
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
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