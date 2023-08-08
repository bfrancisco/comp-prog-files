#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    int odd = 0, even = 0;

    for (int i =0; i < n; i++) {
        int x; cin >> x;
        if (x%2) odd++;
        else even++;
    }

    if (odd % 2) cout << "No" << endl;
    else cout << "Yes" << endl;

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