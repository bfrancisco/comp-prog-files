#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    bool same = true;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i && a[i] != a[i-1]) same = false;
    }

    int ans = 1; // for k==n
    vector<int> divs;
    divs.push_back(1);
    for (int d = 2; d*d <= n; d++){
        if (n%d==0){
            divs.push_back(d);
            if (d*d != n) divs.push_back(n/d);
        }
    }
    int dn = divs.size();

    if (same){ cout << (n == 1 ? 1 : dn+1) << endl; return; }

    for (auto d : divs){
        int gcd = 0;
        for (int i = 0; i < d; i++){
            for (int j = i; j+d < n; j += d){
                gcd = __gcd(gcd, abs(a[j+d] - a[j]));
            }
        }

        
        if (gcd >= 2 || gcd == 0) ans++;

        // if (pas) cout << "passed" << endl;
        // cout << "div: " << d << endl;
        // cout << "gcds: "; for (auto e : gcds) cout << e << " "; cout << endl;
    }

    cout << ans << endl;
    
    
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