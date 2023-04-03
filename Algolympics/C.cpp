#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    char prev = '1';
    for (char x : s){
        if (x != prev){
            ans ++;
            if (prev == '1') prev = '0';
            else prev = '1';
        }
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