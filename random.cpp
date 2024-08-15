#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    string ans = "Bob";

    int al, ar, bl, br;
    al = bl = 0; ar = br = n-1;
    for (int i = 0; i < n; i++){
        if (!((a[al] == b[bl] && a[ar] == b[br]) || (a[al] == b[br] && a[ar] == b[bl]))){
            ans = "Alice";
            break;
        }
        if (a[al] == b[bl]) { al++; bl++; }
        else if (a[ar] == b[br]) { ar--; br--; }
        else if (a[al] == b[br]) { al++; br--; }
        else if (a[ar] == b[bl]) { ar--; bl++; }
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