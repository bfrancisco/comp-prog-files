#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
    vector<ll> x(n-1);
    for (int i = 0; i < n-1; i++){
        x[i] = a[i] + a[i+1];
    }
    for (auto v : x) cout << v << " ";
    cout << endl;
    return 0;
}

// 4 16
// 4 3 2 1