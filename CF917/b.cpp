#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<char> don;

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (don.find(s[i]) != don.end()) continue;
        ans += n-i;
        don.insert(s[i]);
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