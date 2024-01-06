#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(26);
    for (int i = 0; i < n; i++){
        a[s[i] - 'A']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++){
        if (a[i] >= i+1) ans++;
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