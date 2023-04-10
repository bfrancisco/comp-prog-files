#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll mx = *max_element(a.begin(), a.end());
    string out = "YES";
    if (n == 2){
        if (a[0] == mx) out = "NO";
    }
    else{
        if (a[n-1] == mx) out = "NO";
    }
    cout << out << endl;
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