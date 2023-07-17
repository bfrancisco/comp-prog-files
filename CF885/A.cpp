#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n,m,k; cin >> n >> m >> k;
    int x, y; cin >> x >> y;
    string ans="yes";
    for (int i = 0; i < k; i++){
        int r, c; cin >> r >> c;
        if ((abs(x-r) + abs(y-c)) % 2 == 0) ans="no";
    }
    cout << ans << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}