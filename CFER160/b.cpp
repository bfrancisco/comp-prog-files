#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    string s; cin >> s;
    int n = s.size();
    int one = 0, zer = 0;
    for (auto c : s){
        one += ('1' == c);
        zer += ('0' == c);
    }
    if (one == 0 || zer == 0){
        cout << one+zer << endl;
        return;
    }
    
    int ans = 0;
    string bago = "";
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            if (zer) { bago += '0'; zer--; }
            else { bago += '1'; }
        }
        else{
            if (one) { bago += '1'; one--; }
            else { bago += '0'; }
        }
    }
    for (int i = 0, j = 0; i < n && j < n; i++){
        if (bago[i] != s[j]) { j++; }
        else { ans++; }
    }
    // cout << bago << " " << ans << endl;
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